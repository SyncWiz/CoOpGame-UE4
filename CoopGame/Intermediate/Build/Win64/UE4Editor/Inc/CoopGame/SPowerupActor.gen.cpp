// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "CoopGame/Public/SPowerupActor.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSPowerupActor() {}
// Cross Module References
	COOPGAME_API UClass* Z_Construct_UClass_ASPowerupActor_NoRegister();
	COOPGAME_API UClass* Z_Construct_UClass_ASPowerupActor();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_CoopGame();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
// End Cross Module References
	DEFINE_FUNCTION(ASPowerupActor::execOnRep_PowerupActive)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->OnRep_PowerupActive();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASPowerupActor::execOnTickPowerUp)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->OnTickPowerUp();
		P_NATIVE_END;
	}
	static FName NAME_ASPowerupActor_OnActivated = FName(TEXT("OnActivated"));
	void ASPowerupActor::OnActivated(AActor* ActivateFor)
	{
		SPowerupActor_eventOnActivated_Parms Parms;
		Parms.ActivateFor=ActivateFor;
		ProcessEvent(FindFunctionChecked(NAME_ASPowerupActor_OnActivated),&Parms);
	}
	static FName NAME_ASPowerupActor_OnExpired = FName(TEXT("OnExpired"));
	void ASPowerupActor::OnExpired()
	{
		ProcessEvent(FindFunctionChecked(NAME_ASPowerupActor_OnExpired),NULL);
	}
	static FName NAME_ASPowerupActor_OnPowerUpActiveChanged = FName(TEXT("OnPowerUpActiveChanged"));
	void ASPowerupActor::OnPowerUpActiveChanged(bool bNewIsActive)
	{
		SPowerupActor_eventOnPowerUpActiveChanged_Parms Parms;
		Parms.bNewIsActive=bNewIsActive ? true : false;
		ProcessEvent(FindFunctionChecked(NAME_ASPowerupActor_OnPowerUpActiveChanged),&Parms);
	}
	static FName NAME_ASPowerupActor_OnPowerUpTicked = FName(TEXT("OnPowerUpTicked"));
	void ASPowerupActor::OnPowerUpTicked()
	{
		ProcessEvent(FindFunctionChecked(NAME_ASPowerupActor_OnPowerUpTicked),NULL);
	}
	void ASPowerupActor::StaticRegisterNativesASPowerupActor()
	{
		UClass* Class = ASPowerupActor::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "OnRep_PowerupActive", &ASPowerupActor::execOnRep_PowerupActive },
			{ "OnTickPowerUp", &ASPowerupActor::execOnTickPowerUp },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_ASPowerupActor_OnActivated_Statics
	{
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ActivateFor;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ASPowerupActor_OnActivated_Statics::NewProp_ActivateFor = { "ActivateFor", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SPowerupActor_eventOnActivated_Parms, ActivateFor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASPowerupActor_OnActivated_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASPowerupActor_OnActivated_Statics::NewProp_ActivateFor,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASPowerupActor_OnActivated_Statics::Function_MetaDataParams[] = {
		{ "Category", "PowerUps" },
		{ "ModuleRelativePath", "Public/SPowerupActor.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ASPowerupActor_OnActivated_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASPowerupActor, nullptr, "OnActivated", nullptr, nullptr, sizeof(SPowerupActor_eventOnActivated_Parms), Z_Construct_UFunction_ASPowerupActor_OnActivated_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASPowerupActor_OnActivated_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASPowerupActor_OnActivated_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASPowerupActor_OnActivated_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASPowerupActor_OnActivated()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ASPowerupActor_OnActivated_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASPowerupActor_OnExpired_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASPowerupActor_OnExpired_Statics::Function_MetaDataParams[] = {
		{ "Category", "PowerUps" },
		{ "ModuleRelativePath", "Public/SPowerupActor.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ASPowerupActor_OnExpired_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASPowerupActor, nullptr, "OnExpired", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASPowerupActor_OnExpired_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASPowerupActor_OnExpired_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASPowerupActor_OnExpired()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ASPowerupActor_OnExpired_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASPowerupActor_OnPowerUpActiveChanged_Statics
	{
		static void NewProp_bNewIsActive_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bNewIsActive;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_ASPowerupActor_OnPowerUpActiveChanged_Statics::NewProp_bNewIsActive_SetBit(void* Obj)
	{
		((SPowerupActor_eventOnPowerUpActiveChanged_Parms*)Obj)->bNewIsActive = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ASPowerupActor_OnPowerUpActiveChanged_Statics::NewProp_bNewIsActive = { "bNewIsActive", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SPowerupActor_eventOnPowerUpActiveChanged_Parms), &Z_Construct_UFunction_ASPowerupActor_OnPowerUpActiveChanged_Statics::NewProp_bNewIsActive_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASPowerupActor_OnPowerUpActiveChanged_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASPowerupActor_OnPowerUpActiveChanged_Statics::NewProp_bNewIsActive,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASPowerupActor_OnPowerUpActiveChanged_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/SPowerupActor.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ASPowerupActor_OnPowerUpActiveChanged_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASPowerupActor, nullptr, "OnPowerUpActiveChanged", nullptr, nullptr, sizeof(SPowerupActor_eventOnPowerUpActiveChanged_Parms), Z_Construct_UFunction_ASPowerupActor_OnPowerUpActiveChanged_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASPowerupActor_OnPowerUpActiveChanged_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASPowerupActor_OnPowerUpActiveChanged_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASPowerupActor_OnPowerUpActiveChanged_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASPowerupActor_OnPowerUpActiveChanged()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ASPowerupActor_OnPowerUpActiveChanged_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASPowerupActor_OnPowerUpTicked_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASPowerupActor_OnPowerUpTicked_Statics::Function_MetaDataParams[] = {
		{ "Category", "PowerUps" },
		{ "ModuleRelativePath", "Public/SPowerupActor.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ASPowerupActor_OnPowerUpTicked_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASPowerupActor, nullptr, "OnPowerUpTicked", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASPowerupActor_OnPowerUpTicked_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASPowerupActor_OnPowerUpTicked_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASPowerupActor_OnPowerUpTicked()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ASPowerupActor_OnPowerUpTicked_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASPowerupActor_OnRep_PowerupActive_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASPowerupActor_OnRep_PowerupActive_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/SPowerupActor.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ASPowerupActor_OnRep_PowerupActive_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASPowerupActor, nullptr, "OnRep_PowerupActive", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASPowerupActor_OnRep_PowerupActive_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASPowerupActor_OnRep_PowerupActive_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASPowerupActor_OnRep_PowerupActive()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ASPowerupActor_OnRep_PowerupActive_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASPowerupActor_OnTickPowerUp_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASPowerupActor_OnTickPowerUp_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/SPowerupActor.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ASPowerupActor_OnTickPowerUp_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASPowerupActor, nullptr, "OnTickPowerUp", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASPowerupActor_OnTickPowerUp_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASPowerupActor_OnTickPowerUp_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASPowerupActor_OnTickPowerUp()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ASPowerupActor_OnTickPowerUp_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_ASPowerupActor_NoRegister()
	{
		return ASPowerupActor::StaticClass();
	}
	struct Z_Construct_UClass_ASPowerupActor_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_PowerUpInterval_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_PowerUpInterval;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_TotalNbOfTicks_MetaData[];
#endif
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_TotalNbOfTicks;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bIsPowerupActive_MetaData[];
#endif
		static void NewProp_bIsPowerupActive_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bIsPowerupActive;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ASPowerupActor_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_CoopGame,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_ASPowerupActor_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_ASPowerupActor_OnActivated, "OnActivated" }, // 3359905462
		{ &Z_Construct_UFunction_ASPowerupActor_OnExpired, "OnExpired" }, // 198167864
		{ &Z_Construct_UFunction_ASPowerupActor_OnPowerUpActiveChanged, "OnPowerUpActiveChanged" }, // 281585530
		{ &Z_Construct_UFunction_ASPowerupActor_OnPowerUpTicked, "OnPowerUpTicked" }, // 524301207
		{ &Z_Construct_UFunction_ASPowerupActor_OnRep_PowerupActive, "OnRep_PowerupActive" }, // 579149156
		{ &Z_Construct_UFunction_ASPowerupActor_OnTickPowerUp, "OnTickPowerUp" }, // 4083147014
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASPowerupActor_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "SPowerupActor.h" },
		{ "ModuleRelativePath", "Public/SPowerupActor.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASPowerupActor_Statics::NewProp_PowerUpInterval_MetaData[] = {
		{ "Category", "PowerUps" },
		{ "Comment", "/* Time between PowerUp ticks */" },
		{ "ModuleRelativePath", "Public/SPowerupActor.h" },
		{ "ToolTip", "Time between PowerUp ticks" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ASPowerupActor_Statics::NewProp_PowerUpInterval = { "PowerUpInterval", nullptr, (EPropertyFlags)0x0020080000010001, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ASPowerupActor, PowerUpInterval), METADATA_PARAMS(Z_Construct_UClass_ASPowerupActor_Statics::NewProp_PowerUpInterval_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASPowerupActor_Statics::NewProp_PowerUpInterval_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASPowerupActor_Statics::NewProp_TotalNbOfTicks_MetaData[] = {
		{ "Category", "PowerUps" },
		{ "Comment", "/* Total times we apply the PowerUp effect */" },
		{ "ModuleRelativePath", "Public/SPowerupActor.h" },
		{ "ToolTip", "Total times we apply the PowerUp effect" },
	};
#endif
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UClass_ASPowerupActor_Statics::NewProp_TotalNbOfTicks = { "TotalNbOfTicks", nullptr, (EPropertyFlags)0x0020080000010001, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ASPowerupActor, TotalNbOfTicks), METADATA_PARAMS(Z_Construct_UClass_ASPowerupActor_Statics::NewProp_TotalNbOfTicks_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASPowerupActor_Statics::NewProp_TotalNbOfTicks_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASPowerupActor_Statics::NewProp_bIsPowerupActive_MetaData[] = {
		{ "ModuleRelativePath", "Public/SPowerupActor.h" },
	};
#endif
	void Z_Construct_UClass_ASPowerupActor_Statics::NewProp_bIsPowerupActive_SetBit(void* Obj)
	{
		((ASPowerupActor*)Obj)->bIsPowerupActive = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ASPowerupActor_Statics::NewProp_bIsPowerupActive = { "bIsPowerupActive", "OnRep_PowerupActive", (EPropertyFlags)0x0020080100000020, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(ASPowerupActor), &Z_Construct_UClass_ASPowerupActor_Statics::NewProp_bIsPowerupActive_SetBit, METADATA_PARAMS(Z_Construct_UClass_ASPowerupActor_Statics::NewProp_bIsPowerupActive_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASPowerupActor_Statics::NewProp_bIsPowerupActive_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ASPowerupActor_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASPowerupActor_Statics::NewProp_PowerUpInterval,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASPowerupActor_Statics::NewProp_TotalNbOfTicks,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASPowerupActor_Statics::NewProp_bIsPowerupActive,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ASPowerupActor_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ASPowerupActor>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ASPowerupActor_Statics::ClassParams = {
		&ASPowerupActor::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_ASPowerupActor_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_ASPowerupActor_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_ASPowerupActor_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ASPowerupActor_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ASPowerupActor()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ASPowerupActor_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ASPowerupActor, 1420057750);
	template<> COOPGAME_API UClass* StaticClass<ASPowerupActor>()
	{
		return ASPowerupActor::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ASPowerupActor(Z_Construct_UClass_ASPowerupActor, &ASPowerupActor::StaticClass, TEXT("/Script/CoopGame"), TEXT("ASPowerupActor"), false, nullptr, nullptr, nullptr);

	void ASPowerupActor::ValidateGeneratedRepEnums(const TArray<struct FRepRecord>& ClassReps) const
	{
		static const FName Name_bIsPowerupActive(TEXT("bIsPowerupActive"));

		const bool bIsValid = true
			&& Name_bIsPowerupActive == ClassReps[(int32)ENetFields_Private::bIsPowerupActive].Property->GetFName();

		checkf(bIsValid, TEXT("UHT Generated Rep Indices do not match runtime populated Rep Indices for properties in ASPowerupActor"));
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ASPowerupActor);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
