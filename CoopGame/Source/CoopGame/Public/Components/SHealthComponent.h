// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SHealthComponent.generated.h"

//OnHealthChange event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_SixParams(FOnHealthChangedSignature, USHealthComponent*, ReceivedHealthComp, float, Health, float, HealthDelta, const class UDamageType*, DamageType, AController*, InstigatedBy, AActor*, DamageCauser);

UCLASS(ClassGroup = (COOP), meta = (BlueprintSpawnableComponent))
class COOPGAME_API USHealthComponent : public UActorComponent
{
    GENERATED_BODY()


public:
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "HealthComponent")
    uint8 TeamNumber;

protected:
    UPROPERTY(ReplicatedUsing=OnRep_Health, EditDefaultsOnly, BlueprintReadOnly, Category = "HealthComponent")
    float Health;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HealthComponent")
    float DefaultHealth;

private:
    bool bIsDead;

public:
    UPROPERTY(BlueprintAssignable, Category = "Events")
    FOnHealthChangedSignature OnHealthChanged;

public:
    USHealthComponent();
    
    float GetHealth() const;

    UFUNCTION(BlueprintCallable, Category = "HealthComponent")
    void Heal(float HealAmount);

    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "HealthComponent")
    static bool IsFriendly(AActor* ActorA, AActor* ActorB);

protected:
    virtual void BeginPlay() override;

    UFUNCTION()
    void HandleTakeAnyDamage(AActor* DamagedActor, float Damage, const UDamageType* DamageType, AController* InstigatedBy, AActor* DamageCauser);

    UFUNCTION()
    void OnRep_Health(float OldHealth);
};
