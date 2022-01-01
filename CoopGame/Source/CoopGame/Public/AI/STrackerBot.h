// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "STrackerBot.generated.h"

class USHealthComponent;
class USphereComponent;
class USoundCue;

UCLASS()
class COOPGAME_API ASTrackerBot : public APawn
{
    GENERATED_BODY()

protected:
    UPROPERTY(VisibleDefaultsOnly, Category = "Components")
    UStaticMeshComponent* MeshComp;

    UPROPERTY(VisibleDefaultsOnly, Category = "Components")
    USHealthComponent* HealthComp;

    UPROPERTY(EditDefaultsOnly, Category = "Components")
    float MovementForce;

    UPROPERTY(EditDefaultsOnly, Category = "Components")
    float RequiredDistanceToTarget;

    UPROPERTY(EditDefaultsOnly, Category = "Components")
    bool bUseVelocityChange;

    UPROPERTY(EditDefaultsOnly, Category = "Explosion")
    UParticleSystem* ExplosionEffect;

    UPROPERTY(EditDefaultsOnly, Category = "Explosion")
    USphereComponent* SphereComp;
    
    UPROPERTY(EditDefaultsOnly, Category = "Explosion")
    float ExplosionRadius;

    UPROPERTY(EditDefaultsOnly, Category = "Explosion")
    float ExplosionDamage;

    UPROPERTY(EditDefaultsOnly, Category = "Explosion")
    float SelftDamageInterval;

    UPROPERTY(EditDefaultsOnly, Category = "Explosion")
    USoundCue* SelfDestructSound;

    UPROPERTY(EditDefaultsOnly, Category = "Explosion")
    USoundCue* ExplodeSound;


    UPROPERTY(VisibleAnywhere, Category = "ExtraDamageAlliance")
    USphereComponent* AllianceShereComp;

    UPROPERTY(EditDefaultsOnly, Category = "ExtraDamageAlliance")
    int MaxPowerLevel;

    UPROPERTY(EditDefaultsOnly, Category = "ExtraDamageAlliance")
    float ExtraDamagePerAlly;

    UPROPERTY(ReplicatedUsing = OnRep_PowerLevel)
    int CurrentPowerLevel;

    FTimerHandle TimerHandle_RefreshPath;

private:
    FVector NextPathPoint;

    //Dynamic Material to pulse on Damage
    UMaterialInstanceDynamic* MatInst;

    bool bExploded;

    bool bStartedSelfDestruction;

    FTimerHandle TimerHandle_SelfDamage;

public:
    ASTrackerBot();

    virtual void Tick(float DeltaTime) override;

    virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;

protected:
    virtual void BeginPlay() override;

    UFUNCTION()
    void OnHealthChanged(USHealthComponent* ReceivedHealthComp, float Health, float HealthDelta, const UDamageType* DamageType, AController* InstigatedBy, AActor* DamageCauser);

    UFUNCTION()
    void OnRep_PowerLevel();

private:
    FVector GetNextPathPoint();
    void SelfDestruct();
    void DamageSelf();
    void RefreshPath();
};
