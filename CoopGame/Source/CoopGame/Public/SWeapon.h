// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SWeapon.generated.h"

class UParticleSystem;

USTRUCT()
struct FHitScanTrace
{
    GENERATED_BODY()

public:
    UPROPERTY()
    FVector_NetQuantize TraceFrom;

    UPROPERTY()
    FVector_NetQuantize TraceTo;

    UPROPERTY()
    TEnumAsByte<EPhysicalSurface> SurfaceType;
};

UCLASS()
class COOPGAME_API ASWeapon : public AActor
{
    GENERATED_BODY()

public:
    ASWeapon();

    void StartFire();
    void StopFire();

protected:

    virtual void BeginPlay() override;

    UFUNCTION(BlueprintCallable, Category = "Weapon")
    virtual void Fire();

    UFUNCTION(Server, Reliable, WithValidation)
    void ServerFire();

    UFUNCTION()
    void OnRep_HitScanTrace();

    void PlayMuzzleEffect();
    void PlayHitscanEffects(FVector TracerEndPoint);
    void ShakeCamera();
    void PlayerImpactEffect(const EPhysicalSurface SurfaceType, FVector ImpactPoint);

protected:
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
    USkeletalMeshComponent* MeshComp;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Weapon")
    TSubclassOf<UDamageType> DamageType;

    UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "Weapon")
    FName MuzzleSocketName;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Weapon")
    UParticleSystem* MuzzleEffect;

    UPROPERTY(EditDefaultsOnly, Category = "Weapon")
    TSubclassOf<UCameraShakeBase> FireCamShake;

    UPROPERTY(ReplicatedUsing=OnRep_HitScanTrace)
    FHitScanTrace HitScanTrace;

    float LastFireTime;

private:
    UPROPERTY(VisibleDefaultsOnly, Category = "Weapon")
    FName TracerTargetName;

    UPROPERTY(EditDefaultsOnly, Category = "Weapon")
    UParticleSystem* DefaultImpactEffect;

    UPROPERTY(EditDefaultsOnly, Category = "Weapon")
    UParticleSystem* FleshImpactEffect;

    UPROPERTY(EditDefaultsOnly, Category = "Weapon")
    UParticleSystem* TracerEffect;

    UPROPERTY(EditDefaultsOnly, Category = "Weapon")
    float BaseDamage;
    
    UPROPERTY(EditDefaultsOnly, Category = "Weapon")
    float RateOfFire;

    UPROPERTY(EditDefaultsOnly, Category = "Weapon", meta = (ClampMin = 0.0f))
    float BulletSpread;

    FTimerHandle TimerHandle_TimeBetweenShots;
    float TimeBetweenShots;
};
