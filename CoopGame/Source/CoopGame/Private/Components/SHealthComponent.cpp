#include "Components/SHealthComponent.h"
#include "CoopGame/Public/SGameMode.h"
#include "Net/UnrealNetwork.h"

USHealthComponent::USHealthComponent()
{
    DefaultHealth = 100;
    bIsDead = false;
    TeamNumber = 255;
}

void USHealthComponent::Heal(float HealAmount)
{
    if (HealAmount <= 0.0f || Health <= 0.0f) return;

    Health = FMath::Clamp(Health + HealAmount, 0.0f, DefaultHealth);

    UE_LOG(LogTemp, Log, TEXT("Health Changed: %s (+%s)"), *FString::SanitizeFloat(Health), *FString::SanitizeFloat(HealAmount));

    OnHealthChanged.Broadcast(this, Health, -HealAmount, nullptr, nullptr, nullptr);
}

bool USHealthComponent::IsFriendly(AActor* ActorA, AActor* ActorB)
{
    if (ActorA == nullptr || ActorB == nullptr)
    {
        return true;
    }

    USHealthComponent* HealthCompA = Cast<USHealthComponent>(ActorA->GetComponentByClass(USHealthComponent::StaticClass()));
    USHealthComponent* HealthCompB = Cast<USHealthComponent>(ActorB->GetComponentByClass(USHealthComponent::StaticClass()));

    if (HealthCompA == nullptr || HealthCompB == nullptr) 
    {
        return true;
    }

    return HealthCompA->TeamNumber == HealthCompB->TeamNumber;
}

float USHealthComponent::GetHealth() const
{
    return Health;
}

void USHealthComponent::BeginPlay()
{
    Super::BeginPlay();
    
    //Only hook if we are server
    if (GetOwnerRole() == ROLE_Authority)
    {
        if (AActor* MyOwner = GetOwner())
        {
            MyOwner->OnTakeAnyDamage.AddDynamic(this, &USHealthComponent::HandleTakeAnyDamage);
        }
    }

    SetIsReplicated(true);
    Health = DefaultHealth;
}

void USHealthComponent::HandleTakeAnyDamage(AActor* DamagedActor, float Damage, const UDamageType* DamageType, AController* InstigatedBy, AActor* DamageCauser)
{
    if (Damage <= 0.0f || bIsDead) return;
    if (DamageCauser != DamagedActor && IsFriendly(GetOwner(), DamageCauser)) return;

    Health = FMath::Clamp(Health - Damage, 0.0f, DefaultHealth);
    UE_LOG(LogTemp, Log, TEXT("Health Changed: %s"), *FString::SanitizeFloat(Health));

    OnHealthChanged.Broadcast(this, Health, Damage, DamageType, InstigatedBy, DamageCauser);

    bIsDead = Health <= 0.0f;

    if (bIsDead)
    {
        ASGameMode* MyGameMode = Cast<ASGameMode>(GetWorld()->GetAuthGameMode());
        if (MyGameMode)
        {
            MyGameMode->OnActorKilled.Broadcast(GetOwner(), DamageCauser, InstigatedBy);
        }
    }
}

void USHealthComponent::OnRep_Health(float OldHealth)
{
    OnHealthChanged.Broadcast(this, Health, OldHealth - Health , nullptr, nullptr, nullptr);
}

void USHealthComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);

    DOREPLIFETIME(USHealthComponent, Health);
}
