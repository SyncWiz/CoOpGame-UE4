#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "SGameMode.generated.h"

enum class EWaveState : uint8;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnActorKilled, AActor*, VictimActor, AActor*, KillerActor, AController*, KillerController);

UCLASS()
class COOPGAME_API ASGameMode : public AGameModeBase
{
    GENERATED_BODY()


public:
    UPROPERTY(BlueprintAssignable, Category = "GameMode")
    FOnActorKilled OnActorKilled;

protected:
    UPROPERTY(EditDefaultsOnly, Category = "GameMode")
    float TimeBetweenWaves;

    FTimerHandle TimerHandle_BotSpawner;
    FTimerHandle TimerHandle_NextWaveStart;

    int32 NbOfBotsToSpawn;
    int32 WaveCount;

public:
    ASGameMode();

    virtual void StartPlay() override;
    virtual void Tick(float DeltaTime) override;

protected:
    UFUNCTION(BlueprintImplementableEvent, Category = "GameMode")
    void SpawnNewBot();

private:
    void StartWave();
    void EndWave();
    void PrepareForNextWave();
    void SpawnBotTimerElapsed();
    void CheckWaveState();
    void CheckAnyPlayerAlive();
    void GameOver();
    void SetWaveState(EWaveState NewWaveState);
    void ReviveDeadPlayers();
};
