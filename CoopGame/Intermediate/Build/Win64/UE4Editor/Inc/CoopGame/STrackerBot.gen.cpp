// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "CoopGame/Public/AI/STrackerBot.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSTrackerBot() {}
// Cross Module References
	COOPGAME_API UClass* Z_Construct_UClass_ASTrackerBot_NoRegister();
	COOPGAME_API UClass* Z_Construct_UClass_ASTrackerBot();
	ENGINE_API UClass* Z_Construct_UClass_APawn();
	UPackage* Z_Construct_UPackage__Script_CoopGame();
	COOPGAME_API UClass* Z_Construct_UClass_USHealthComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UDamageType_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_AController_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UParticleSystem_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_USphereComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_USoundCue_NoRegister();
// End Cross Module References
	DEFINE_FUNCTION(ASTrackerBot::execOnRep_PowerLevel)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->OnRep_PowerLevel();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASTrackerBot::execOnHealthChanged)
	{
		P_GET_OBJECT(USHealthComponent,Z_Param_ReceivedHealthComp);
		P_GET_PROPERTY(FFloatProperty,Z_Param_Health);
		P_GET_PROPERTY(FFloatProperty,Z_Param_HealthDelta);
		P_GET_OBJECT(UDamageType,Z_Param_DamageType);
		P_GET_OBJECT(AController,Z_Param_InstigatedBy);
		P_GET_OBJECT(AActor,Z_Param_DamageCauser);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->OnHealthChanged(Z_Param_ReceivedHealthComp,Z_Param_Health,Z_Param_HealthDelta,Z_Param_DamageType,Z_Param_InstigatedBy,Z_Param_DamageCauser);
		P_NATIVE_END;
	}
	void ASTrackerBot::StaticRegisterNativesASTrackerBot()
	{
		UClass* Class = ASTrackerBot::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "OnHealthChanged", &ASTrackerBot::execOnHealthChanged },
			{ "OnRep_PowerLevel", &ASTrackerBot::execOnRep_PowerLevel },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_ASTrackerBot_OnHealthChanged_Statics
	{
		struct STrackerBot_eventOnHealthChanged_Parms
		{
			USHealthComponent* ReceivedHealthComp;
			float Health;
			float HealthDelta;
			const UDamageType* DamageType;
			AController* InstigatedBy;
			AActor* DamageCauser;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ReceivedHealthComp_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ReceivedHealthComp;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Health;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_HealthDelta;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_DamageType_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_DamageType;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_InstigatedBy;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_DamageCauser;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASTrackerBot_OnHealthChanged_Statics::NewProp_ReceivedHealthComp_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ASTrackerBot_OnHealthChanged_Statics::NewProp_ReceivedHealthComp = { "ReceivedHealthComp", nullptr, (EPropertyFlags)0x0010000000080080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(STrackerBot_eventOnHealthChanged_Parms, ReceivedHealthComp), Z_Construct_UClass_USHealthComponent_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_ASTrackerBot_OnHealthChanged_Statics::NewProp_ReceivedHealthComp_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_ASTrackerBot_OnHealthChanged_Statics::NewProp_ReceivedHealthComp_MetaData)) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ASTrackerBot_OnHealthChanged_Statics::NewProp_Health = { "Health", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(STrackerBot_eventOnHealthChanged_Parms, Health), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ASTrackerBot_OnHealthChanged_Statics::NewProp_HealthDelta = { "HealthDelta", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(STrackerBot_eventOnHealthChanged_Parms, HealthDelta), METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASTrackerBot_OnHealthChanged_Statics::NewProp_DamageType_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ASTrackerBot_OnHealthChanged_Statics::NewProp_DamageType = { "DamageType", nullptr, (EPropertyFlags)0x0010000000000082, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(STrackerBot_eventOnHealthChanged_Parms, DamageType), Z_Construct_UClass_UDamageType_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_ASTrackerBot_OnHealthChanged_Statics::NewProp_DamageType_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_ASTrackerBot_OnHealthChanged_Statics::NewProp_DamageType_MetaData)) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ASTrackerBot_OnHealthChanged_Statics::NewProp_InstigatedBy = { "InstigatedBy", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(STrackerBot_eventOnHealthChanged_Parms, InstigatedBy), Z_Construct_UClass_AController_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ASTrackerBot_OnHealthChanged_Statics::NewProp_DamageCauser = { "DamageCauser", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(STrackerBot_eventOnHealthChanged_Parms, DamageCauser), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASTrackerBot_OnHealthChanged_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASTrackerBot_OnHealthChanged_Statics::NewProp_ReceivedHealthComp,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASTrackerBot_OnHealthChanged_Statics::NewProp_Health,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASTrackerBot_OnHealthChanged_Statics::NewProp_HealthDelta,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASTrackerBot_OnHealthChanged_Statics::NewProp_DamageType,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASTrackerBot_OnHealthChanged_Statics::NewProp_InstigatedBy,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASTrackerBot_OnHealthChanged_Statics::NewProp_DamageCauser,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASTrackerBot_OnHealthChanged_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/AI/STrackerBot.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ASTrackerBot_OnHealthChanged_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASTrackerBot, nullptr, "OnHealthChanged", nullptr, nullptr, sizeof(STrackerBot_eventOnHealthChanged_Parms), Z_Construct_UFunction_ASTrackerBot_OnHealthChanged_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASTrackerBot_OnHealthChanged_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASTrackerBot_OnHealthChanged_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASTrackerBot_OnHealthChanged_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASTrackerBot_OnHealthChanged()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ASTrackerBot_OnHealthChanged_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASTrackerBot_OnRep_PowerLevel_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASTrackerBot_OnRep_PowerLevel_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/AI/STrackerBot.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ASTrackerBot_OnRep_PowerLevel_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASTrackerBot, nullptr, "OnRep_PowerLevel", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASTrackerBot_OnRep_PowerLevel_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASTrackerBot_OnRep_PowerLevel_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASTrackerBot_OnRep_PowerLevel()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ASTrackerBot_OnRep_PowerLevel_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_ASTrackerBot_NoRegister()
	{
		return ASTrackerBot::StaticClass();
	}
	struct Z_Construct_UClass_ASTrackerBot_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MeshComp_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_MeshComp;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_HealthComp_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_HealthComp;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MovementForce_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_MovementForce;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_RequiredDistanceToTarget_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_RequiredDistanceToTarget;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bUseVelocityChange_MetaData[];
#endif
		static void NewProp_bUseVelocityChange_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bUseVelocityChange;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ExplosionEffect_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ExplosionEffect;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_SphereComp_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_SphereComp;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ExplosionRadius_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_ExplosionRadius;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ExplosionDamage_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_ExplosionDamage;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_SelftDamageInterval_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_SelftDamageInterval;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_SelfDestructSound_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_SelfDestructSound;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ExplodeSound_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ExplodeSound;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_AllianceShereComp_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_AllianceShereComp;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MaxPowerLevel_MetaData[];
#endif
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_MaxPowerLevel;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ExtraDamagePerAlly_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_ExtraDamagePerAlly;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CurrentPowerLevel_MetaData[];
#endif
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_CurrentPowerLevel;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ASTrackerBot_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_APawn,
		(UObject* (*)())Z_Construct_UPackage__Script_CoopGame,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_ASTrackerBot_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_ASTrackerBot_OnHealthChanged, "OnHealthChanged" }, // 4187217690
		{ &Z_Construct_UFunction_ASTrackerBot_OnRep_PowerLevel, "OnRep_PowerLevel" }, // 2634816618
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASTrackerBot_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "AI/STrackerBot.h" },
		{ "ModuleRelativePath", "Public/AI/STrackerBot.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASTrackerBot_Statics::NewProp_MeshComp_MetaData[] = {
		{ "Category", "Components" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/AI/STrackerBot.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASTrackerBot_Statics::NewProp_MeshComp = { "MeshComp", nullptr, (EPropertyFlags)0x00200800000b0009, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ASTrackerBot, MeshComp), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ASTrackerBot_Statics::NewProp_MeshComp_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASTrackerBot_Statics::NewProp_MeshComp_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASTrackerBot_Statics::NewProp_HealthComp_MetaData[] = {
		{ "Category", "Components" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/AI/STrackerBot.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASTrackerBot_Statics::NewProp_HealthComp = { "HealthComp", nullptr, (EPropertyFlags)0x00200800000b0009, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ASTrackerBot, HealthComp), Z_Construct_UClass_USHealthComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ASTrackerBot_Statics::NewProp_HealthComp_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASTrackerBot_Statics::NewProp_HealthComp_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASTrackerBot_Statics::NewProp_MovementForce_MetaData[] = {
		{ "Category", "Components" },
		{ "ModuleRelativePath", "Public/AI/STrackerBot.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ASTrackerBot_Statics::NewProp_MovementForce = { "MovementForce", nullptr, (EPropertyFlags)0x0020080000010001, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ASTrackerBot, MovementForce), METADATA_PARAMS(Z_Construct_UClass_ASTrackerBot_Statics::NewProp_MovementForce_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASTrackerBot_Statics::NewProp_MovementForce_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASTrackerBot_Statics::NewProp_RequiredDistanceToTarget_MetaData[] = {
		{ "Category", "Components" },
		{ "ModuleRelativePath", "Public/AI/STrackerBot.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ASTrackerBot_Statics::NewProp_RequiredDistanceToTarget = { "RequiredDistanceToTarget", nullptr, (EPropertyFlags)0x0020080000010001, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ASTrackerBot, RequiredDistanceToTarget), METADATA_PARAMS(Z_Construct_UClass_ASTrackerBot_Statics::NewProp_RequiredDistanceToTarget_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASTrackerBot_Statics::NewProp_RequiredDistanceToTarget_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASTrackerBot_Statics::NewProp_bUseVelocityChange_MetaData[] = {
		{ "Category", "Components" },
		{ "ModuleRelativePath", "Public/AI/STrackerBot.h" },
	};
#endif
	void Z_Construct_UClass_ASTrackerBot_Statics::NewProp_bUseVelocityChange_SetBit(void* Obj)
	{
		((ASTrackerBot*)Obj)->bUseVelocityChange = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ASTrackerBot_Statics::NewProp_bUseVelocityChange = { "bUseVelocityChange", nullptr, (EPropertyFlags)0x0020080000010001, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(ASTrackerBot), &Z_Construct_UClass_ASTrackerBot_Statics::NewProp_bUseVelocityChange_SetBit, METADATA_PARAMS(Z_Construct_UClass_ASTrackerBot_Statics::NewProp_bUseVelocityChange_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASTrackerBot_Statics::NewProp_bUseVelocityChange_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASTrackerBot_Statics::NewProp_ExplosionEffect_MetaData[] = {
		{ "Category", "Explosion" },
		{ "ModuleRelativePath", "Public/AI/STrackerBot.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASTrackerBot_Statics::NewProp_ExplosionEffect = { "ExplosionEffect", nullptr, (EPropertyFlags)0x0020080000010001, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ASTrackerBot, ExplosionEffect), Z_Construct_UClass_UParticleSystem_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ASTrackerBot_Statics::NewProp_ExplosionEffect_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASTrackerBot_Statics::NewProp_ExplosionEffect_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASTrackerBot_Statics::NewProp_SphereComp_MetaData[] = {
		{ "Category", "Explosion" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/AI/STrackerBot.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASTrackerBot_Statics::NewProp_SphereComp = { "SphereComp", nullptr, (EPropertyFlags)0x0020080000090009, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ASTrackerBot, SphereComp), Z_Construct_UClass_USphereComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ASTrackerBot_Statics::NewProp_SphereComp_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASTrackerBot_Statics::NewProp_SphereComp_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASTrackerBot_Statics::NewProp_ExplosionRadius_MetaData[] = {
		{ "Category", "Explosion" },
		{ "ModuleRelativePath", "Public/AI/STrackerBot.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ASTrackerBot_Statics::NewProp_ExplosionRadius = { "ExplosionRadius", nullptr, (EPropertyFlags)0x0020080000010001, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ASTrackerBot, ExplosionRadius), METADATA_PARAMS(Z_Construct_UClass_ASTrackerBot_Statics::NewProp_ExplosionRadius_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASTrackerBot_Statics::NewProp_ExplosionRadius_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASTrackerBot_Statics::NewProp_ExplosionDamage_MetaData[] = {
		{ "Category", "Explosion" },
		{ "ModuleRelativePath", "Public/AI/STrackerBot.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ASTrackerBot_Statics::NewProp_ExplosionDamage = { "ExplosionDamage", nullptr, (EPropertyFlags)0x0020080000010001, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ASTrackerBot, ExplosionDamage), METADATA_PARAMS(Z_Construct_UClass_ASTrackerBot_Statics::NewProp_ExplosionDamage_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASTrackerBot_Statics::NewProp_ExplosionDamage_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASTrackerBot_Statics::NewProp_SelftDamageInterval_MetaData[] = {
		{ "Category", "Explosion" },
		{ "ModuleRelativePath", "Public/AI/STrackerBot.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ASTrackerBot_Statics::NewProp_SelftDamageInterval = { "SelftDamageInterval", nullptr, (EPropertyFlags)0x0020080000010001, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ASTrackerBot, SelftDamageInterval), METADATA_PARAMS(Z_Construct_UClass_ASTrackerBot_Statics::NewProp_SelftDamageInterval_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASTrackerBot_Statics::NewProp_SelftDamageInterval_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASTrackerBot_Statics::NewProp_SelfDestructSound_MetaData[] = {
		{ "Category", "Explosion" },
		{ "ModuleRelativePath", "Public/AI/STrackerBot.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASTrackerBot_Statics::NewProp_SelfDestructSound = { "SelfDestructSound", nullptr, (EPropertyFlags)0x0020080000010001, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ASTrackerBot, SelfDestructSound), Z_Construct_UClass_USoundCue_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ASTrackerBot_Statics::NewProp_SelfDestructSound_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASTrackerBot_Statics::NewProp_SelfDestructSound_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASTrackerBot_Statics::NewProp_ExplodeSound_MetaData[] = {
		{ "Category", "Explosion" },
		{ "ModuleRelativePath", "Public/AI/STrackerBot.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASTrackerBot_Statics::NewProp_ExplodeSound = { "ExplodeSound", nullptr, (EPropertyFlags)0x0020080000010001, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ASTrackerBot, ExplodeSound), Z_Construct_UClass_USoundCue_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ASTrackerBot_Statics::NewProp_ExplodeSound_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASTrackerBot_Statics::NewProp_ExplodeSound_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASTrackerBot_Statics::NewProp_AllianceShereComp_MetaData[] = {
		{ "Category", "ExtraDamageAlliance" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/AI/STrackerBot.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASTrackerBot_Statics::NewProp_AllianceShereComp = { "AllianceShereComp", nullptr, (EPropertyFlags)0x00200800000a0009, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ASTrackerBot, AllianceShereComp), Z_Construct_UClass_USphereComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ASTrackerBot_Statics::NewProp_AllianceShereComp_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASTrackerBot_Statics::NewProp_AllianceShereComp_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASTrackerBot_Statics::NewProp_MaxPowerLevel_MetaData[] = {
		{ "Category", "ExtraDamageAlliance" },
		{ "ModuleRelativePath", "Public/AI/STrackerBot.h" },
	};
#endif
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UClass_ASTrackerBot_Statics::NewProp_MaxPowerLevel = { "MaxPowerLevel", nullptr, (EPropertyFlags)0x0020080000010001, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ASTrackerBot, MaxPowerLevel), METADATA_PARAMS(Z_Construct_UClass_ASTrackerBot_Statics::NewProp_MaxPowerLevel_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASTrackerBot_Statics::NewProp_MaxPowerLevel_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASTrackerBot_Statics::NewProp_ExtraDamagePerAlly_MetaData[] = {
		{ "Category", "ExtraDamageAlliance" },
		{ "ModuleRelativePath", "Public/AI/STrackerBot.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ASTrackerBot_Statics::NewProp_ExtraDamagePerAlly = { "ExtraDamagePerAlly", nullptr, (EPropertyFlags)0x0020080000010001, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ASTrackerBot, ExtraDamagePerAlly), METADATA_PARAMS(Z_Construct_UClass_ASTrackerBot_Statics::NewProp_ExtraDamagePerAlly_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASTrackerBot_Statics::NewProp_ExtraDamagePerAlly_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASTrackerBot_Statics::NewProp_CurrentPowerLevel_MetaData[] = {
		{ "ModuleRelativePath", "Public/AI/STrackerBot.h" },
	};
#endif
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UClass_ASTrackerBot_Statics::NewProp_CurrentPowerLevel = { "CurrentPowerLevel", "OnRep_PowerLevel", (EPropertyFlags)0x0020080100000020, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ASTrackerBot, CurrentPowerLevel), METADATA_PARAMS(Z_Construct_UClass_ASTrackerBot_Statics::NewProp_CurrentPowerLevel_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASTrackerBot_Statics::NewProp_CurrentPowerLevel_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ASTrackerBot_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASTrackerBot_Statics::NewProp_MeshComp,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASTrackerBot_Statics::NewProp_HealthComp,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASTrackerBot_Statics::NewProp_MovementForce,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASTrackerBot_Statics::NewProp_RequiredDistanceToTarget,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASTrackerBot_Statics::NewProp_bUseVelocityChange,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASTrackerBot_Statics::NewProp_ExplosionEffect,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASTrackerBot_Statics::NewProp_SphereComp,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASTrackerBot_Statics::NewProp_ExplosionRadius,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASTrackerBot_Statics::NewProp_ExplosionDamage,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASTrackerBot_Statics::NewProp_SelftDamageInterval,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASTrackerBot_Statics::NewProp_SelfDestructSound,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASTrackerBot_Statics::NewProp_ExplodeSound,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASTrackerBot_Statics::NewProp_AllianceShereComp,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASTrackerBot_Statics::NewProp_MaxPowerLevel,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASTrackerBot_Statics::NewProp_ExtraDamagePerAlly,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASTrackerBot_Statics::NewProp_CurrentPowerLevel,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ASTrackerBot_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ASTrackerBot>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ASTrackerBot_Statics::ClassParams = {
		&ASTrackerBot::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_ASTrackerBot_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_ASTrackerBot_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_ASTrackerBot_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ASTrackerBot_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ASTrackerBot()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ASTrackerBot_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ASTrackerBot, 3470266429);
	template<> COOPGAME_API UClass* StaticClass<ASTrackerBot>()
	{
		return ASTrackerBot::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ASTrackerBot(Z_Construct_UClass_ASTrackerBot, &ASTrackerBot::StaticClass, TEXT("/Script/CoopGame"), TEXT("ASTrackerBot"), false, nullptr, nullptr, nullptr);

	void ASTrackerBot::ValidateGeneratedRepEnums(const TArray<struct FRepRecord>& ClassReps) const
	{
		static const FName Name_CurrentPowerLevel(TEXT("CurrentPowerLevel"));

		const bool bIsValid = true
			&& Name_CurrentPowerLevel == ClassReps[(int32)ENetFields_Private::CurrentPowerLevel].Property->GetFName();

		checkf(bIsValid, TEXT("UHT Generated Rep Indices do not match runtime populated Rep Indices for properties in ASTrackerBot"));
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ASTrackerBot);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
