#include "SGameMode.h"
#include "TimerManager.h"
#include "CoopGame/Public/Components/SHealthComponent.h"
#include "CoopGame/Public/SGameState.h"
#include "CoopGame/Public/SPlayerState.h"
#include "EngineUtils.h"

ASGameMode::ASGameMode()
{
    TimeBetweenWaves = 2.0f;

    GameStateClass = ASGameMode::StaticClass();
    PlayerStateClass = ASPlayerState::StaticClass();

    PrimaryActorTick.bCanEverTick = true;
    PrimaryActorTick.TickInterval = 1.0f;
}

void ASGameMode::StartPlay()
{
    Super::StartPlay();

    PrepareForNextWave();
}

void ASGameMode::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    CheckWaveState();
    CheckAnyPlayerAlive();
}

void ASGameMode::StartWave()
{
    WaveCount++;
    NbOfBotsToSpawn = 2 * WaveCount;

    GetWorldTimerManager().SetTimer(TimerHandle_BotSpawner, this, &ASGameMode::SpawnBotTimerElapsed, 1.0f, true, 0.0f);
    SetWaveState(EWaveState::WaveInProgress);
}

void ASGameMode::EndWave()
{
    GetWorldTimerManager().ClearTimer(TimerHandle_BotSpawner);
    SetWaveState(EWaveState::WaitingToComplete);
}

void ASGameMode::PrepareForNextWave()
{
    GetWorldTimerManager().SetTimer(TimerHandle_NextWaveStart, this, &ASGameMode::StartWave, TimeBetweenWaves, false);
    SetWaveState(EWaveState::WaitingToStart);
    ReviveDeadPlayers();
}

void ASGameMode::SpawnBotTimerElapsed()
{
    SpawnNewBot();
    --NbOfBotsToSpawn;

    if (NbOfBotsToSpawn <= 0)
    {
        EndWave();
    }
}

void ASGameMode::CheckWaveState()
{
    bool bIsPreparingForWave = GetWorldTimerManager().IsTimerActive(TimerHandle_NextWaveStart);

    if (NbOfBotsToSpawn > 0 || bIsPreparingForWave)
    {
        return;
    }

    bool bIsAnyBotAlive = false;

    for (TActorIterator<APawn> It(GetWorld(), APawn::StaticClass()); It; ++It)
    {
        APawn* TestPawn = *It;
        if (TestPawn == nullptr || TestPawn->IsPlayerControlled())
        {
            continue;
        }

        USHealthComponent* HealthComp = Cast<USHealthComponent>(TestPawn->GetComponentByClass(USHealthComponent::StaticClass()));
        if (HealthComp && HealthComp->GetHealth() > 0.0f)
        {
            bIsAnyBotAlive = true;
            break;
        }
    }

    if (!bIsAnyBotAlive)
    {
        SetWaveState(EWaveState::WaveComplete);
        PrepareForNextWave();
    }
}

void ASGameMode::CheckAnyPlayerAlive()
{
    for (TActorIterator<APlayerController> It(GetWorld(), APlayerController::StaticClass()); It; ++It)
    {
        APlayerController* PlayerController = *It;

        if (PlayerController && PlayerController->GetPawn())
        {
            APawn* MyPawn = PlayerController->GetPawn();
            USHealthComponent* HealthComp = Cast<USHealthComponent>(MyPawn->GetComponentByClass(USHealthComponent::StaticClass()));
            if (ensure(HealthComp) && HealthComp->GetHealth() > 0.0f)
            {
                return;
            }
        }
    }

    GameOver();
}

void ASGameMode::GameOver()
{
    EndWave();
    SetWaveState(EWaveState::GameOver);
}

void ASGameMode::SetWaveState(EWaveState NewWaveState)
{
    ASGameState* MyGameState = GetGameState<ASGameState>();

    if (ensureAlways(MyGameState))
    {
        MyGameState->SetWaveState(NewWaveState);
    }
}

void ASGameMode::ReviveDeadPlayers()
{
    for (TActorIterator<APlayerController> It(GetWorld(), APlayerController::StaticClass()); It; ++It)
    {
        APlayerController* PlayerController = *It;

        //When a player dies, unposses the pawn
        if (PlayerController && PlayerController->GetPawn() == nullptr)
        {
            RestartPlayer(PlayerController);
        }
    }
}
