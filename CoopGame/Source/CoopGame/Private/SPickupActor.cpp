#include "SPickupActor.h"
#include "Components/SphereComponent.h"
#include "Components/DecalComponent.h"
#include "CoopGame/Public/SPowerupActor.h"
#include "CoopGame/Public/SCharacter.h"
#include "TimerManager.h"

ASPickupActor::ASPickupActor()
{
    SphereComp = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere Component"));
    SphereComp->SetSphereRadius(75.0f);
    RootComponent = SphereComp;


    DecalComp = CreateDefaultSubobject<UDecalComponent>(TEXT("Decal Component"));
    DecalComp->SetRelativeRotation(FRotator(90.0f, 0.0f, 0.0f));
    DecalComp->DecalSize = FVector(64.0f, 75.0f, 75.0f);
    DecalComp->SetupAttachment(RootComponent);

    CooldownDuration = 10.0f;
    SetReplicates(true);
}

void ASPickupActor::NotifyActorBeginOverlap(AActor* OtherActor)
{
    Super::NotifyActorBeginOverlap(OtherActor);

    ASCharacter* PlayerCharacter = Cast<ASCharacter>(OtherActor);

    if (PlayerCharacter && PowerUpInstance && HasAuthority())
    {
        PowerUpInstance->ActivatePowerUp(OtherActor);
        PowerUpInstance = nullptr;

        GetWorldTimerManager().SetTimer(TimerHandle_RespawnTimer, this, &ASPickupActor::Respawn, CooldownDuration);
    }
}

void ASPickupActor::BeginPlay()
{
    Super::BeginPlay();

    if (!HasAuthority()) return;
    Respawn();
}

void ASPickupActor::Respawn()
{
    if (!PowerUpClass)
    {
        UE_LOG(LogTemp, Warning, TEXT("PowerUpClass is nullptr in %. Please update your Blueprint"), *GetName());
        return;
    }

    FActorSpawnParameters SpawnParams;
    SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

    PowerUpInstance = GetWorld()->SpawnActor<ASPowerupActor>(PowerUpClass, GetTransform(), SpawnParams);
}
