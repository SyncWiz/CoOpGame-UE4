#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SPowerupActor.generated.h"

UCLASS()
class COOPGAME_API ASPowerupActor : public AActor
{
    GENERATED_BODY()

protected:

    /* Time between PowerUp ticks */
    UPROPERTY(EditDefaultsOnly, Category = "PowerUps")
    float PowerUpInterval;

    /* Total times we apply the PowerUp effect */
    UPROPERTY(EditDefaultsOnly, Category = "PowerUps")
    int32 TotalNbOfTicks;

    UPROPERTY(ReplicatedUsing = OnRep_PowerupActive)
    bool bIsPowerupActive;

    FTimerHandle TimerHandle_PowerupTick;

    //Total Number of Tick Applied
    int32 TicksProcessed;

public:
    ASPowerupActor();

    void ActivatePowerUp(AActor* ActivateFor);

    UFUNCTION(BlueprintImplementableEvent, Category = "PowerUps")
    void OnActivated(AActor* ActivateFor);
    
    UFUNCTION(BlueprintImplementableEvent, Category = "PowerUps")
    void OnExpired();

    UFUNCTION(BlueprintImplementableEvent, Category = "PowerUps")
    void OnPowerUpTicked();


    UFUNCTION(BlueprintImplementableEvent)
    void OnPowerUpActiveChanged(bool bNewIsActive);

protected:
    UFUNCTION()
    void OnTickPowerUp();

    UFUNCTION()
    void OnRep_PowerupActive();
};
