#include "AI/STrackerBot.h"

#include "Kismet/GameplayStatics.h"
#include "NavigationSystem/Public/NavigationPath.h"
#include "NavigationSystem/Public/NavigationSystem.h"
#include "GameFramework/Character.h"
#include "DrawDebugHelpers.h"
#include "CoopGame/Public/Components/SHealthComponent.h"
#include "Kismet/GameplayStatics.h"
#include "CoopGame/Public/SCharacter.h"
#include "Components/SphereComponent.h"
#include "Sound/SoundCue.h"
#include "Net/UnrealNetwork.h"
#include "EngineUtils.h"

static int32 DebugTrackerBotDrawing = 0;
FAutoConsoleVariableRef CVARDebugTrackerInfo(
    TEXT("COOP.DebugTrackerBots"),
    DebugTrackerBotDrawing,
    TEXT("Draw Debug Tracker Bot Info"),
    ECVF_Cheat);


ASTrackerBot::ASTrackerBot()
{
    PrimaryActorTick.bCanEverTick = true;

    MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh Component"));
    MeshComp->SetCanEverAffectNavigation(false);
    MeshComp->SetSimulatePhysics(true);
    RootComponent = MeshComp;

    HealthComp = CreateDefaultSubobject<USHealthComponent>(TEXT("Health Component"));
    HealthComp->OnHealthChanged.AddDynamic(this, &ASTrackerBot::OnHealthChanged);

    SphereComp = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere Component"));
    SphereComp->SetSphereRadius(200);
    SphereComp->SetupAttachment(RootComponent);
    SphereComp->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
    SphereComp->SetCollisionResponseToAllChannels(ECR_Ignore);
    SphereComp->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);

    AllianceShereComp = CreateDefaultSubobject<USphereComponent>(TEXT("Alliance Sphere Component"));
    AllianceShereComp->SetSphereRadius(600);
    AllianceShereComp->SetupAttachment(MeshComp);


    bUseVelocityChange = false;
    MovementForce = 1000.0f;
    RequiredDistanceToTarget = 100.0f;
    ExplosionDamage = 60.0f;
    ExplosionRadius = 350.0f;
    SelftDamageInterval = 0.25f;
    MaxPowerLevel = 4.0f;
    ExtraDamagePerAlly = 10.0f;
}

void ASTrackerBot::BeginPlay()
{
    Super::BeginPlay();

    if (HasAuthority())
    {
        NextPathPoint = GetNextPathPoint();
    }
}

void ASTrackerBot::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    if (!HasAuthority() || bExploded) return;

    float DistanceToTarget = (GetActorLocation() - NextPathPoint).Size();
    if (DistanceToTarget <= RequiredDistanceToTarget)
    {
        NextPathPoint = GetNextPathPoint();
    }
    else
    {
        FVector ForceDirection = NextPathPoint - GetActorLocation();
        ForceDirection.Normalize();

        MeshComp->AddForce(ForceDirection * MovementForce, NAME_None, bUseVelocityChange);

        if (DebugTrackerBotDrawing)
        {
            DrawDebugDirectionalArrow(GetWorld(), GetActorLocation(), GetActorLocation() + ForceDirection, 32, FColor::Yellow, false, 0.0f, 0, 1.0f);
        }
    }

    if (DebugTrackerBotDrawing)
    {
        DrawDebugSphere(GetWorld(), NextPathPoint, 20, 12, FColor::Yellow, false, 0.0f, 1.0f);
    }

    TArray<AActor*> OverlappingActors;
    AllianceShereComp->GetOverlappingActors(OverlappingActors);
    int PowerLevelToUpdate = 0;
    for (int32 i = 0; i < OverlappingActors.Num(); ++i)
    {
        AActor* CurrentActor = OverlappingActors[i];
        ASTrackerBot* CurrentTrackerBot = Cast<ASTrackerBot>(CurrentActor);
        if(CurrentTrackerBot == this) continue;

        if (CurrentTrackerBot)
        {
            PowerLevelToUpdate++;
        }
    }

    CurrentPowerLevel = FMath::Clamp(PowerLevelToUpdate, 0, MaxPowerLevel);
    OnRep_PowerLevel();
}

void ASTrackerBot::NotifyActorBeginOverlap(AActor* OtherActor)
{
    Super::NotifyActorBeginOverlap(OtherActor);

    if (bStartedSelfDestruction || bExploded) return;

    ASCharacter* PlayerPawn = Cast<ASCharacter>(OtherActor);
    if (PlayerPawn && !USHealthComponent::IsFriendly(OtherActor, this))
    {
        bStartedSelfDestruction = true;
        UGameplayStatics::SpawnSoundAttached(SelfDestructSound, RootComponent);

        if (!HasAuthority()) return;

        GetWorldTimerManager().SetTimer(TimerHandle_SelfDamage, this, &ASTrackerBot::DamageSelf, SelftDamageInterval, true, 0.0f);
    }
}

void ASTrackerBot::OnHealthChanged(USHealthComponent* ReceivedHealthComp, float Health, float HealthDelta, const UDamageType* DamageType, AController* InstigatedBy, AActor* DamageCauser)
{
    if (MatInst == nullptr)
    {
        MatInst = MeshComp->CreateAndSetMaterialInstanceDynamicFromMaterial(0, MeshComp->GetMaterial(0));
    }

    if (MatInst)
    {
        MatInst->SetScalarParameterValue("LastTimeDamageTaken", GetWorld()->TimeSeconds);
    }

    if (Health <= 0.0f)
    {
        SelfDestruct();
    }
}

void ASTrackerBot::OnRep_PowerLevel()
{
    if (MatInst == nullptr)
    {
        MatInst = MeshComp->CreateAndSetMaterialInstanceDynamicFromMaterial(0, MeshComp->GetMaterial(0));
    }

    if (MatInst)
    {
        MatInst->SetScalarParameterValue("PowerLevelAlpha", CurrentPowerLevel / (float) MaxPowerLevel);
    }
}

FVector ASTrackerBot::GetNextPathPoint()
{
    AActor* BestTarget = nullptr;
    float NearestTargetDistance = FLT_MAX;

    for (TActorIterator<APawn> It(GetWorld(), APawn::StaticClass()); It; ++It)
    {
        APawn* TestPawn = *It;
        if (TestPawn == nullptr || USHealthComponent::IsFriendly(TestPawn, this))
        {
            continue;
        }

        USHealthComponent* TestPawnHealthComp = Cast<USHealthComponent>(TestPawn->GetComponentByClass(USHealthComponent::StaticClass()));
        if (TestPawnHealthComp && TestPawnHealthComp->GetHealth() > 0.0f)
        {
            float Distance = (TestPawn->GetActorLocation() - GetActorLocation()).Size();
            if (Distance < NearestTargetDistance)
            {
                BestTarget = TestPawn;
                NearestTargetDistance = Distance;
            }
        }
    }

    if (BestTarget)
    {
        UNavigationPath* NavPath = UNavigationSystemV1::FindPathToActorSynchronously(this, GetActorLocation(), BestTarget);

        GetWorldTimerManager().ClearTimer(TimerHandle_RefreshPath);
        GetWorldTimerManager().SetTimer(TimerHandle_RefreshPath, this, &ASTrackerBot::RefreshPath, 5.0f, false);

        if (!NavPath) return GetActorLocation();
        if (NavPath->PathPoints.Num() > 1)
        {
            return NavPath->PathPoints[1];
        }
    }

    return GetActorLocation();
}

void ASTrackerBot::SelfDestruct()
{
    if (bExploded) return;

    bExploded = true;
    UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), ExplosionEffect, GetActorLocation());
    
    UGameplayStatics::PlaySoundAtLocation(this, ExplodeSound, GetActorLocation());

    MeshComp->SetVisibility(false, true);
    MeshComp->SetSimulatePhysics(false);
    MeshComp->SetCollisionEnabled(ECollisionEnabled::NoCollision);

    SphereComp->SetCollisionEnabled(ECollisionEnabled::NoCollision);
    AllianceShereComp->SetCollisionEnabled(ECollisionEnabled::NoCollision);

    if (!HasAuthority()) return;

    TArray<AActor*> IgnoredActors;
    IgnoredActors.Add(this);

    float DamageToApply = ExplosionDamage + (CurrentPowerLevel * ExtraDamagePerAlly);
    UGameplayStatics::ApplyRadialDamage(this, DamageToApply, GetActorLocation(), ExplosionRadius, nullptr, IgnoredActors, this, GetInstigatorController(), true);

    if (DebugTrackerBotDrawing)
    {
        DrawDebugSphere(GetWorld(), GetActorLocation(), ExplosionRadius, 12, FColor::Red, false, 2.0f, 0, 1.0f);
    }

    SetLifeSpan(2.0f);
}

void ASTrackerBot::DamageSelf()
{
    UGameplayStatics::ApplyDamage(this, 20, GetInstigatorController(), this, nullptr);
}

void ASTrackerBot::RefreshPath()
{
    NextPathPoint = GetNextPathPoint();
}

void ASTrackerBot::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);

    DOREPLIFETIME(ASTrackerBot, CurrentPowerLevel);
}

