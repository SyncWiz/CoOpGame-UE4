#include "SPowerupActor.h"
#include "Net/UnrealNetwork.h"

ASPowerupActor::ASPowerupActor()
{
    PowerUpInterval = 0.0f;
    TotalNbOfTicks = 0;

    bIsPowerupActive = false;

    SetReplicates(true);
}

void ASPowerupActor::ActivatePowerUp(AActor* ActivateFor)
{
    OnActivated(ActivateFor);

    bIsPowerupActive = true;
    OnRep_PowerupActive();

    if (PowerUpInterval > 0.0f)
    {
        GetWorldTimerManager().SetTimer(TimerHandle_PowerupTick, this, &ASPowerupActor::OnTickPowerUp, PowerUpInterval, true);
    }
    else
    {
        OnTickPowerUp();
    }
}

void ASPowerupActor::OnTickPowerUp()
{
    TicksProcessed++;

    OnPowerUpTicked();

    if (TicksProcessed >= TotalNbOfTicks)
    {
        OnExpired();
        
        bIsPowerupActive = true;
        OnRep_PowerupActive();

        GetWorldTimerManager().ClearTimer(TimerHandle_PowerupTick);
    }
}

void ASPowerupActor::OnRep_PowerupActive()
{
    OnPowerUpActiveChanged(bIsPowerupActive);
}

void ASPowerupActor::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);

    DOREPLIFETIME(ASPowerupActor, bIsPowerupActive);
}
