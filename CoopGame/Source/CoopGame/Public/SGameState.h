#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "SGameState.generated.h"

UENUM(BlueprintType)
enum class EWaveState : uint8
{
    WaitingToStart,

    WaveInProgress,

    //No longer spawning new bots, waiting for player to kill remaining bots
    WaitingToComplete,

    WaveComplete,

    GameOver
};

UCLASS()
class COOPGAME_API ASGameState : public AGameStateBase
{
    GENERATED_BODY()


protected:
    UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_WaveState, Category = "GameState")
    EWaveState WaveState;


public:
    void SetWaveState(EWaveState NewState);

protected:
    UFUNCTION(BlueprintImplementableEvent, Category = "GameState")
    void WaveStateChanged(EWaveState NewState, EWaveState OldState);

    UFUNCTION()
    void OnRep_WaveState(EWaveState OldState);
};
