#include "SWeapon.h"

#include "DrawDebugHelpers.h"
#include "Kismet/GameplayStatics.h"
#include "Particles/ParticleSystem.h"
#include "Particles/ParticleSystemComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "CoopGame/CoopGame.h"
#include "TimerManager.h"
#include "Net/UnrealNetwork.h"

static int32 DebugWeaponDrawing = 0;
FAutoConsoleVariableRef CVARDebugWeaponDrawing (
    TEXT("COOP.DebugHitscanWeapons"), 
    DebugWeaponDrawing, 
    TEXT("Draw Debug Lines for Hitscan Weapons"), 
    ECVF_Cheat);

ASWeapon::ASWeapon()
{
    MeshComp = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Mesh Component"));
    RootComponent = MeshComp;

    MuzzleSocketName = "MuzzleSocket";
    TracerTargetName = "BeamEnd";

    BaseDamage = 20.0f;
    RateOfFire = 600.0f;
    BulletSpread = 2.0f;

    SetReplicates(true);

    NetUpdateFrequency = 66.0f;
    MinNetUpdateFrequency = 33.0f;
}

void ASWeapon::BeginPlay()
{
    Super::BeginPlay();

    TimeBetweenShots = 60 / RateOfFire;
}

void ASWeapon::StartFire()
{
    float FirstDelay = FMath::Max(0.0f, LastFireTime + TimeBetweenShots - GetWorld()->TimeSeconds);
    GetWorldTimerManager().SetTimer(TimerHandle_TimeBetweenShots, this, &ASWeapon::Fire, TimeBetweenShots, true, FirstDelay);
}

void ASWeapon::StopFire()
{
    GetWorldTimerManager().ClearTimer(TimerHandle_TimeBetweenShots);
}

void ASWeapon::Fire()
{
    if (!HasAuthority())
    {
        ServerFire();
    }

    AActor* MyOwner = GetOwner();
    if (!MyOwner) return;

    FVector EyeLocation;
    FRotator EyeRotation;
    MyOwner->GetActorEyesViewPoint(EyeLocation, EyeRotation);
    
    FVector ShotDirection = EyeRotation.Vector();

    float HalfRad = FMath::DegreesToRadians(BulletSpread);
    ShotDirection = FMath::VRandCone(ShotDirection, HalfRad, HalfRad);

    FVector TraceEnd = EyeLocation + (ShotDirection * 10000);
    FVector TracerEndPoint = TraceEnd;

    FCollisionQueryParams QueryParams;
    QueryParams.AddIgnoredActor(MyOwner);
    QueryParams.AddIgnoredActor(this);
    QueryParams.bTraceComplex = true;
    QueryParams.bReturnPhysicalMaterial = true;

    FHitResult Hit;
    EPhysicalSurface SurfaceType = SurfaceType_Default;
    if (GetWorld()->LineTraceSingleByChannel(Hit, EyeLocation, TraceEnd, COLLISION_WEAPON, QueryParams))
    {
        TracerEndPoint = Hit.ImpactPoint;

        SurfaceType = UGameplayStatics::GetSurfaceType(Hit);
        float DamageToApply = BaseDamage;
        if (SurfaceType == SURFACE_FLESH_VULNERABLE)
        {
            DamageToApply *= 4.0f;
        }

        PlayerImpactEffect(SurfaceType, Hit.ImpactPoint);

        AActor* HitActor = Hit.GetActor();
        UGameplayStatics::ApplyPointDamage(HitActor, DamageToApply, ShotDirection, Hit, MyOwner->GetInstigatorController(), MyOwner, DamageType);
    }

    if (HasAuthority())
    {
        HitScanTrace.TraceTo = TracerEndPoint;
        HitScanTrace.SurfaceType = SurfaceType;
    }

    PlayMuzzleEffect();
    PlayHitscanEffects(TracerEndPoint);
    ShakeCamera();

    if (DebugWeaponDrawing > 0)
    {
        DrawDebugLine(GetWorld(), EyeLocation, TraceEnd, FColor::White, false, 1.0f, 0, 1.0f);
    }

    LastFireTime = GetWorld()->TimeSeconds;
}

void ASWeapon::ServerFire_Implementation()
{
    Fire();
}

bool ASWeapon::ServerFire_Validate()
{
    return true;
}

void ASWeapon::OnRep_HitScanTrace()
{
    PlayHitscanEffects(HitScanTrace.TraceTo);
    PlayMuzzleEffect();
    PlayerImpactEffect(HitScanTrace.SurfaceType, HitScanTrace.TraceTo);
}

void ASWeapon::PlayMuzzleEffect()
{
    if (MuzzleEffect)
    {
        UGameplayStatics::SpawnEmitterAttached(MuzzleEffect, MeshComp, MuzzleSocketName);
    }
}

void ASWeapon::PlayHitscanEffects(FVector TracerEndPoint)
{
    if (TracerEffect)
    {
        FVector MuzzleLocation = MeshComp->GetSocketLocation(MuzzleSocketName);
        UParticleSystemComponent* ParticleInstance = UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), TracerEffect, MuzzleLocation);

        if (ParticleInstance)
        {
            ParticleInstance->SetVectorParameter(TracerTargetName, TracerEndPoint);
        }
    }
}

void ASWeapon::ShakeCamera()
{
    APawn* MyOwner = Cast<APawn>(GetOwner());
    if (MyOwner)
    {
        APlayerController* PlayerController = Cast<APlayerController>(MyOwner->GetController());
        if (PlayerController)
        {
            PlayerController->ClientStartCameraShake(FireCamShake);
        }
    }
}

void ASWeapon::PlayerImpactEffect(const EPhysicalSurface SurfaceType, FVector ImpactPoint)
{
    UParticleSystem* SelectedEffect = nullptr;
    switch (SurfaceType)
    {
    case SURFACE_FLESH_DEFAULT:
    case SURFACE_FLESH_VULNERABLE:
        SelectedEffect = FleshImpactEffect;
        break;
    default:
        SelectedEffect = DefaultImpactEffect;
        break;
    }

    if (SelectedEffect)
    {
        FVector ShootDirection = ImpactPoint - MeshComp->GetSocketLocation(MuzzleSocketName);
        ShootDirection.Normalize();
        UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), SelectedEffect, ImpactPoint, ShootDirection.Rotation());
    }
}


void ASWeapon::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);

    DOREPLIFETIME_CONDITION(ASWeapon, HitScanTrace, COND_SkipOwner);
}
