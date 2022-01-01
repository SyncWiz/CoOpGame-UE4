// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AActor;
#ifdef COOPGAME_SPowerupActor_generated_h
#error "SPowerupActor.generated.h already included, missing '#pragma once' in SPowerupActor.h"
#endif
#define COOPGAME_SPowerupActor_generated_h

#define CoopGame_Source_CoopGame_Public_SPowerupActor_h_10_SPARSE_DATA
#define CoopGame_Source_CoopGame_Public_SPowerupActor_h_10_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execOnRep_PowerupActive); \
	DECLARE_FUNCTION(execOnTickPowerUp);


#define CoopGame_Source_CoopGame_Public_SPowerupActor_h_10_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execOnRep_PowerupActive); \
	DECLARE_FUNCTION(execOnTickPowerUp);


#define CoopGame_Source_CoopGame_Public_SPowerupActor_h_10_EVENT_PARMS \
	struct SPowerupActor_eventOnActivated_Parms \
	{ \
		AActor* ActivateFor; \
	}; \
	struct SPowerupActor_eventOnPowerUpActiveChanged_Parms \
	{ \
		bool bNewIsActive; \
	};


#define CoopGame_Source_CoopGame_Public_SPowerupActor_h_10_CALLBACK_WRAPPERS
#define CoopGame_Source_CoopGame_Public_SPowerupActor_h_10_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesASPowerupActor(); \
	friend struct Z_Construct_UClass_ASPowerupActor_Statics; \
public: \
	DECLARE_CLASS(ASPowerupActor, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/CoopGame"), NO_API) \
	DECLARE_SERIALIZER(ASPowerupActor) \
	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override; \
	enum class ENetFields_Private : uint16 \
	{ \
		NETFIELD_REP_START=(uint16)((int32)Super::ENetFields_Private::NETFIELD_REP_END + (int32)1), \
		bIsPowerupActive=NETFIELD_REP_START, \
		NETFIELD_REP_END=bIsPowerupActive	}; \
	NO_API virtual void ValidateGeneratedRepEnums(const TArray<struct FRepRecord>& ClassReps) const override;


#define CoopGame_Source_CoopGame_Public_SPowerupActor_h_10_INCLASS \
private: \
	static void StaticRegisterNativesASPowerupActor(); \
	friend struct Z_Construct_UClass_ASPowerupActor_Statics; \
public: \
	DECLARE_CLASS(ASPowerupActor, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/CoopGame"), NO_API) \
	DECLARE_SERIALIZER(ASPowerupActor) \
	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override; \
	enum class ENetFields_Private : uint16 \
	{ \
		NETFIELD_REP_START=(uint16)((int32)Super::ENetFields_Private::NETFIELD_REP_END + (int32)1), \
		bIsPowerupActive=NETFIELD_REP_START, \
		NETFIELD_REP_END=bIsPowerupActive	}; \
	NO_API virtual void ValidateGeneratedRepEnums(const TArray<struct FRepRecord>& ClassReps) const override;


#define CoopGame_Source_CoopGame_Public_SPowerupActor_h_10_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ASPowerupActor(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ASPowerupActor) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ASPowerupActor); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ASPowerupActor); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ASPowerupActor(ASPowerupActor&&); \
	NO_API ASPowerupActor(const ASPowerupActor&); \
public:


#define CoopGame_Source_CoopGame_Public_SPowerupActor_h_10_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ASPowerupActor(ASPowerupActor&&); \
	NO_API ASPowerupActor(const ASPowerupActor&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ASPowerupActor); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ASPowerupActor); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ASPowerupActor)


#define CoopGame_Source_CoopGame_Public_SPowerupActor_h_10_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__PowerUpInterval() { return STRUCT_OFFSET(ASPowerupActor, PowerUpInterval); } \
	FORCEINLINE static uint32 __PPO__TotalNbOfTicks() { return STRUCT_OFFSET(ASPowerupActor, TotalNbOfTicks); } \
	FORCEINLINE static uint32 __PPO__bIsPowerupActive() { return STRUCT_OFFSET(ASPowerupActor, bIsPowerupActive); }


#define CoopGame_Source_CoopGame_Public_SPowerupActor_h_7_PROLOG \
	CoopGame_Source_CoopGame_Public_SPowerupActor_h_10_EVENT_PARMS


#define CoopGame_Source_CoopGame_Public_SPowerupActor_h_10_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	CoopGame_Source_CoopGame_Public_SPowerupActor_h_10_PRIVATE_PROPERTY_OFFSET \
	CoopGame_Source_CoopGame_Public_SPowerupActor_h_10_SPARSE_DATA \
	CoopGame_Source_CoopGame_Public_SPowerupActor_h_10_RPC_WRAPPERS \
	CoopGame_Source_CoopGame_Public_SPowerupActor_h_10_CALLBACK_WRAPPERS \
	CoopGame_Source_CoopGame_Public_SPowerupActor_h_10_INCLASS \
	CoopGame_Source_CoopGame_Public_SPowerupActor_h_10_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define CoopGame_Source_CoopGame_Public_SPowerupActor_h_10_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	CoopGame_Source_CoopGame_Public_SPowerupActor_h_10_PRIVATE_PROPERTY_OFFSET \
	CoopGame_Source_CoopGame_Public_SPowerupActor_h_10_SPARSE_DATA \
	CoopGame_Source_CoopGame_Public_SPowerupActor_h_10_RPC_WRAPPERS_NO_PURE_DECLS \
	CoopGame_Source_CoopGame_Public_SPowerupActor_h_10_CALLBACK_WRAPPERS \
	CoopGame_Source_CoopGame_Public_SPowerupActor_h_10_INCLASS_NO_PURE_DECLS \
	CoopGame_Source_CoopGame_Public_SPowerupActor_h_10_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> COOPGAME_API UClass* StaticClass<class ASPowerupActor>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID CoopGame_Source_CoopGame_Public_SPowerupActor_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
