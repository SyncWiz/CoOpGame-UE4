#include "SCharacter.h"

#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/PawnMovementComponent.h"
#include "SWeapon.h"
#include "Components/CapsuleComponent.h"
#include "CoopGame/CoopGame.h"
#include "CoopGame/Public/Components/SHealthComponent.h"
#include "Net/UnrealNetwork.h"

ASCharacter::ASCharacter()
{
    PrimaryActorTick.bCanEverTick = true;

    SpringArmComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm Component"));
    SpringArmComp->bUsePawnControlRotation = true;
    SpringArmComp->SetupAttachment(RootComponent);

    CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera Component"));
    CameraComp->SetupAttachment(SpringArmComp);

    GetMovementComponent()->GetNavAgentPropertiesRef().bCanCrouch = true;
    GetCapsuleComponent()->SetCollisionResponseToChannel(COLLISION_WEAPON, ECR_Ignore);

    ZoomedFOV = 65.0f;
    ZoomInterpSpeed = 20.0f;
    WeaponSocketName = "WeaponSocket";

    HealthComp = CreateDefaultSubobject<USHealthComponent>(TEXT("Health Component"));
    HealthComp->OnHealthChanged.AddDynamic(this, &ASCharacter::OnHealthChanged);
}

void ASCharacter::BeginPlay()
{
    Super::BeginPlay();

    DefaultFOV = CameraComp->FieldOfView;

    if (HasAuthority())
    {
        FActorSpawnParameters SpawnParams;
        SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

        CurrentWeapon = GetWorld()->SpawnActor<ASWeapon>(StarterWeaponClass, FVector::ZeroVector, FRotator::ZeroRotator, SpawnParams);
        if (CurrentWeapon)
        {
            CurrentWeapon->SetOwner(this);
            CurrentWeapon->AttachToComponent(GetMesh(), FAttachmentTransformRules::SnapToTargetNotIncludingScale, WeaponSocketName);
        }
    }
}

FVector ASCharacter::GetPawnViewLocation() const
{
    return CameraComp ? CameraComp->GetComponentLocation() : Super::GetPawnViewLocation();
}

void ASCharacter::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    float TargetFOV = bWantsToZoom ? ZoomedFOV : DefaultFOV;

    float NewFOV = FMath::FInterpTo(CameraComp->FieldOfView, TargetFOV, DeltaTime, ZoomInterpSpeed);

    CameraComp->SetFieldOfView(NewFOV);
}

void ASCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);

    PlayerInputComponent->BindAxis("MoveForward", this, &ASCharacter::MoveForward);
    PlayerInputComponent->BindAxis("MoveRight", this, &ASCharacter::MoveRight);

    PlayerInputComponent->BindAxis("LookUp", this, &ASCharacter::AddControllerPitchInput);
    PlayerInputComponent->BindAxis("Turn", this, &ASCharacter::AddControllerYawInput);

    PlayerInputComponent->BindAction("Crouch", IE_Pressed, this, &ASCharacter::BeginCrouch);
    PlayerInputComponent->BindAction("Crouch", IE_Released, this, &ASCharacter::EndCrouch);
    
    PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);

    PlayerInputComponent->BindAction("Zoom", IE_Pressed, this, &ASCharacter::BeginZoom);
    PlayerInputComponent->BindAction("Zoom", IE_Released, this, &ASCharacter::EndZoom);

    PlayerInputComponent->BindAction("Fire", IE_Pressed, this, &ASCharacter::StartFire);
    PlayerInputComponent->BindAction("Fire", IE_Released, this, &ASCharacter::StopFire);
}

void ASCharacter::OnHealthChanged(USHealthComponent* ReceivedHealthComp, float Health, float HealthDelta, const UDamageType* DamageType, AController* InstigatedBy, AActor* DamageCauser)
{
    if (Health <= 0.0f && !bDied)
    {
        bDied = true;
        GetMovementComponent()->StopMovementImmediately();
        GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
        DetachFromControllerPendingDestroy();

        SetLifeSpan(10.0f);
    }
}

void ASCharacter::MoveForward(float Value)
{
    AddMovementInput(GetActorForwardVector() * Value);
}

void ASCharacter::MoveRight(float Value)
{
    AddMovementInput(GetActorRightVector() * Value);
}

void ASCharacter::BeginCrouch()
{
    Crouch();
}

void ASCharacter::EndCrouch()
{
    UnCrouch();
}

void ASCharacter::BeginZoom()
{
    bWantsToZoom = true;
}

void ASCharacter::EndZoom()
{
    bWantsToZoom = false;
}

void ASCharacter::StartFire()
{
    if (CurrentWeapon)
    {
        CurrentWeapon->StartFire();
    }
}

void ASCharacter::StopFire()
{
    if (CurrentWeapon)
    {
        CurrentWeapon->StopFire();
    }
}

void ASCharacter::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);

    DOREPLIFETIME(ASCharacter, CurrentWeapon);
    DOREPLIFETIME(ASCharacter, bDied);
}

