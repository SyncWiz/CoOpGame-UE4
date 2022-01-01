#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "SCharacter.generated.h"

class UCameraComponent;
class USpringArmComponent;
class ASWeapon;
class USHealthComponent;

UCLASS()
class COOPGAME_API ASCharacter : public ACharacter
{
    GENERATED_BODY()

protected:
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
    UCameraComponent* CameraComp;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
    USpringArmComponent* SpringArmComp;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
    USHealthComponent* HealthComp;

    UPROPERTY(Replicated, BlueprintReadOnly, Category = "Player")
    bool bDied;

private:
    bool bWantsToZoom;
    float DefaultFOV;

    UPROPERTY(EditDefaultsOnly, Category = "Player")
    float ZoomedFOV;

    UPROPERTY(EditDefaultsOnly, Category = "Player", meta = (ClampMin = 0.1, ClampMax = 100))
    float ZoomInterpSpeed;

    UPROPERTY(EditDefaultsOnly, Category = "Player")
    TSubclassOf<ASWeapon> StarterWeaponClass;

    UPROPERTY(VisibleDefaultsOnly, Category = "Player")
    FName WeaponSocketName;

    UPROPERTY(Replicated)
    ASWeapon* CurrentWeapon;

public:
    ASCharacter();

    virtual void Tick(float DeltaTime) override;
    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

    UFUNCTION(BlueprintCallable, Category = "Player")
    void StartFire();

    UFUNCTION(BlueprintCallable, Category = "Player")
    void StopFire();

protected:
    UFUNCTION()
    void OnHealthChanged(USHealthComponent* ReceivedHealthComp, float Health, float HealthDelta, const UDamageType* DamageType, AController* InstigatedBy, AActor* DamageCauser);

    void MoveForward(float Value);
    void MoveRight(float Value);

    void BeginCrouch();
    void EndCrouch();

    void BeginZoom();
    void EndZoom();

    virtual void BeginPlay() override;
    virtual FVector GetPawnViewLocation() const override;
};
