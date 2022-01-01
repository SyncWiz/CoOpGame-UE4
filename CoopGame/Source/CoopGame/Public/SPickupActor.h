// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SPickupActor.generated.h"

class USphereComponent;
class UDecalComponent;
class ASPowerupActor;

UCLASS()
class COOPGAME_API ASPickupActor : public AActor
{
    GENERATED_BODY()

protected:
    UPROPERTY(VisibleAnywhere, Category = "Components")
    USphereComponent* SphereComp;

    UPROPERTY(VisibleAnywhere, Category = "Components")
    UDecalComponent* DecalComp;

    UPROPERTY(EditInstanceOnly, Category = "PickUpActor")
    TSubclassOf<ASPowerupActor> PowerUpClass;

    UPROPERTY(EditInstanceOnly, Category = "PickUpActor")
    float CooldownDuration;

private:
    ASPowerupActor* PowerUpInstance;
    FTimerHandle TimerHandle_RespawnTimer;

public:
    ASPickupActor();

    virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;

protected:
    virtual void BeginPlay() override;

    void Respawn();
};
