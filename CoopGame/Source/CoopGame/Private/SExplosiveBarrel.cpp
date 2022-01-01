#include "SExplosiveBarrel.h"
#include "CoopGame/Public/Components/SHealthComponent.h"
#include "Kismet/GameplayStatics.h"
#include "PhysicsEngine/RadialForceComponent.h"
#include "Net/UnrealNetwork.h"

ASExplosiveBarrel::ASExplosiveBarrel()
{
    ExplosionImpulse = 400;
    AreaOfEffect = 250;

    HealthComp = CreateDefaultSubobject<USHealthComponent>(TEXT("Health Component"));
    HealthComp->OnHealthChanged.AddDynamic(this, &ASExplosiveBarrel::OnHealthChanged);

    MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh Component"));
    MeshComp->SetSimulatePhysics(true);
    MeshComp->SetCollisionObjectType(ECC_PhysicsBody);
    RootComponent = MeshComp;

    RadialForceComp = CreateDefaultSubobject<URadialForceComponent>(TEXT("RadialForce Component"));
    RadialForceComp->SetupAttachment(MeshComp);
    RadialForceComp->Radius = AreaOfEffect;
    RadialForceComp->bImpulseVelChange = true;
    RadialForceComp->bAutoActivate = false;
    RadialForceComp->bIgnoreOwningActor = true;

    SetReplicates(true);
    SetReplicateMovement(true);
}

void ASExplosiveBarrel::OnRep_BarrelExplode()
{
    //FX
    UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), ExplosionEffect, GetActorLocation());

    //Set Material
    MeshComp->SetMaterial(0, ExplodedMaterial);
}

void ASExplosiveBarrel::OnHealthChanged(USHealthComponent* ReceivedHealthComp, float Health, float HealthDelta, const UDamageType* DamageType, AController* InstigatedBy, AActor* DamageCauser)
{
    if (bExploded) return;

    if (Health <= 0.0f)
    {
        bExploded = true;
        OnRep_BarrelExplode();

        //Radial impulse
        RadialForceComp->FireImpulse();

        if (HasAuthority())
        {
            //Deal damage
            TArray<AActor*> IgnoreActors;
            IgnoreActors.Add(this);
            UGameplayStatics::ApplyRadialDamage(GetWorld(), BaseDamage, GetActorLocation(), AreaOfEffect, DamageTypeClass, IgnoreActors);
        }
    }
}

void ASExplosiveBarrel::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);

    DOREPLIFETIME_CONDITION(ASExplosiveBarrel, bExploded, COND_SkipOwner);
}
