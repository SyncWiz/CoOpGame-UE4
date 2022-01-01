// Fill out your copyright notice in the Description page of Project Settings.


#include "SProjectileWeapon.h"

#include "SWeapon.h"

void ASProjectileWeapon::Fire()
{
    PlayMuzzleEffect();
    ShakeCamera();
    
    AActor* MyOwner = GetOwner();
    if (MyOwner && ProjectileClass)
    {
        FVector EyeLocation;
        FRotator EyeRotation;

        MyOwner->GetActorEyesViewPoint(EyeLocation, EyeRotation);

        FVector MuzzleLocation = MeshComp->GetSocketLocation(MuzzleSocketName);
        FRotator MuzzleRotation = MeshComp->GetSocketRotation(MuzzleSocketName);

        FActorSpawnParameters ActorSpawnParams;
        ActorSpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

        AActor* Instance = GetWorld()->SpawnActor<AActor>(ProjectileClass, MuzzleLocation, EyeRotation, ActorSpawnParams);
        Instance->SetOwner(this);
    }

    LastFireTime = GetWorld()->TimeSeconds;
}
