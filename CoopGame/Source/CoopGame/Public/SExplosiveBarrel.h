// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SExplosiveBarrel.generated.h"

class USHealthComponent;
class UStaticMeshComponent;
class URadialForceComponent;
class UParticleSystem;

UCLASS()
class COOPGAME_API ASExplosiveBarrel : public AActor
{
    GENERATED_BODY()

public:
    ASExplosiveBarrel();

protected:
    UPROPERTY(VisibleAnywhere, Category = "Components")
    USHealthComponent* HealthComp;

    UPROPERTY(VisibleAnywhere, Category = "Components")
    UStaticMeshComponent* MeshComp;

    UPROPERTY(VisibleAnywhere, Category = "Components")
    URadialForceComponent* RadialForceComp;

    UPROPERTY(ReplicatedUsing = OnRep_BarrelExplode)
    bool bExploded;

    UPROPERTY(EditDefaultsOnly, Category = "FX")
    float ExplosionImpulse;

    UPROPERTY(EditDefaultsOnly, Category = "FX")
    UParticleSystem* ExplosionEffect;

    UPROPERTY(EditDefaultsOnly, Category = "FX")
    UMaterialInterface* ExplodedMaterial;

    UPROPERTY(EditDefaultsOnly, Category = "Gameplay")
    float AreaOfEffect;

    UPROPERTY(EditDefaultsOnly, Category = "Gameplay")
    float BaseDamage;

    UPROPERTY(EditDefaultsOnly, Category = "Gameplay")
    TSubclassOf<UDamageType> DamageTypeClass;

protected:
    UFUNCTION()
    void OnRep_BarrelExplode();

    UFUNCTION()
    void OnHealthChanged(USHealthComponent* ReceivedHealthComp, float Health, float HealthDelta, const UDamageType* DamageType, AController* InstigatedBy, AActor* DamageCauser);
};
