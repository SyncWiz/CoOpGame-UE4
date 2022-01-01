// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class USHealthComponent;
class UDamageType;
class AController;
class AActor;
#ifdef COOPGAME_SExplosiveBarrel_generated_h
#error "SExplosiveBarrel.generated.h already included, missing '#pragma once' in SExplosiveBarrel.h"
#endif
#define COOPGAME_SExplosiveBarrel_generated_h

#define CoopGame_Source_CoopGame_Public_SExplosiveBarrel_h_17_SPARSE_DATA
#define CoopGame_Source_CoopGame_Public_SExplosiveBarrel_h_17_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execOnHealthChanged); \
	DECLARE_FUNCTION(execOnRep_BarrelExplode);


#define CoopGame_Source_CoopGame_Public_SExplosiveBarrel_h_17_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execOnHealthChanged); \
	DECLARE_FUNCTION(execOnRep_BarrelExplode);


#define CoopGame_Source_CoopGame_Public_SExplosiveBarrel_h_17_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesASExplosiveBarrel(); \
	friend struct Z_Construct_UClass_ASExplosiveBarrel_Statics; \
public: \
	DECLARE_CLASS(ASExplosiveBarrel, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/CoopGame"), NO_API) \
	DECLARE_SERIALIZER(ASExplosiveBarrel) \
	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override; \
	enum class ENetFields_Private : uint16 \
	{ \
		NETFIELD_REP_START=(uint16)((int32)Super::ENetFields_Private::NETFIELD_REP_END + (int32)1), \
		bExploded=NETFIELD_REP_START, \
		NETFIELD_REP_END=bExploded	}; \
	NO_API virtual void ValidateGeneratedRepEnums(const TArray<struct FRepRecord>& ClassReps) const override;


#define CoopGame_Source_CoopGame_Public_SExplosiveBarrel_h_17_INCLASS \
private: \
	static void StaticRegisterNativesASExplosiveBarrel(); \
	friend struct Z_Construct_UClass_ASExplosiveBarrel_Statics; \
public: \
	DECLARE_CLASS(ASExplosiveBarrel, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/CoopGame"), NO_API) \
	DECLARE_SERIALIZER(ASExplosiveBarrel) \
	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override; \
	enum class ENetFields_Private : uint16 \
	{ \
		NETFIELD_REP_START=(uint16)((int32)Super::ENetFields_Private::NETFIELD_REP_END + (int32)1), \
		bExploded=NETFIELD_REP_START, \
		NETFIELD_REP_END=bExploded	}; \
	NO_API virtual void ValidateGeneratedRepEnums(const TArray<struct FRepRecord>& ClassReps) const override;


#define CoopGame_Source_CoopGame_Public_SExplosiveBarrel_h_17_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ASExplosiveBarrel(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ASExplosiveBarrel) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ASExplosiveBarrel); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ASExplosiveBarrel); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ASExplosiveBarrel(ASExplosiveBarrel&&); \
	NO_API ASExplosiveBarrel(const ASExplosiveBarrel&); \
public:


#define CoopGame_Source_CoopGame_Public_SExplosiveBarrel_h_17_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ASExplosiveBarrel(ASExplosiveBarrel&&); \
	NO_API ASExplosiveBarrel(const ASExplosiveBarrel&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ASExplosiveBarrel); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ASExplosiveBarrel); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ASExplosiveBarrel)


#define CoopGame_Source_CoopGame_Public_SExplosiveBarrel_h_17_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__HealthComp() { return STRUCT_OFFSET(ASExplosiveBarrel, HealthComp); } \
	FORCEINLINE static uint32 __PPO__MeshComp() { return STRUCT_OFFSET(ASExplosiveBarrel, MeshComp); } \
	FORCEINLINE static uint32 __PPO__RadialForceComp() { return STRUCT_OFFSET(ASExplosiveBarrel, RadialForceComp); } \
	FORCEINLINE static uint32 __PPO__bExploded() { return STRUCT_OFFSET(ASExplosiveBarrel, bExploded); } \
	FORCEINLINE static uint32 __PPO__ExplosionImpulse() { return STRUCT_OFFSET(ASExplosiveBarrel, ExplosionImpulse); } \
	FORCEINLINE static uint32 __PPO__ExplosionEffect() { return STRUCT_OFFSET(ASExplosiveBarrel, ExplosionEffect); } \
	FORCEINLINE static uint32 __PPO__ExplodedMaterial() { return STRUCT_OFFSET(ASExplosiveBarrel, ExplodedMaterial); } \
	FORCEINLINE static uint32 __PPO__AreaOfEffect() { return STRUCT_OFFSET(ASExplosiveBarrel, AreaOfEffect); } \
	FORCEINLINE static uint32 __PPO__BaseDamage() { return STRUCT_OFFSET(ASExplosiveBarrel, BaseDamage); } \
	FORCEINLINE static uint32 __PPO__DamageTypeClass() { return STRUCT_OFFSET(ASExplosiveBarrel, DamageTypeClass); }


#define CoopGame_Source_CoopGame_Public_SExplosiveBarrel_h_14_PROLOG
#define CoopGame_Source_CoopGame_Public_SExplosiveBarrel_h_17_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	CoopGame_Source_CoopGame_Public_SExplosiveBarrel_h_17_PRIVATE_PROPERTY_OFFSET \
	CoopGame_Source_CoopGame_Public_SExplosiveBarrel_h_17_SPARSE_DATA \
	CoopGame_Source_CoopGame_Public_SExplosiveBarrel_h_17_RPC_WRAPPERS \
	CoopGame_Source_CoopGame_Public_SExplosiveBarrel_h_17_INCLASS \
	CoopGame_Source_CoopGame_Public_SExplosiveBarrel_h_17_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define CoopGame_Source_CoopGame_Public_SExplosiveBarrel_h_17_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	CoopGame_Source_CoopGame_Public_SExplosiveBarrel_h_17_PRIVATE_PROPERTY_OFFSET \
	CoopGame_Source_CoopGame_Public_SExplosiveBarrel_h_17_SPARSE_DATA \
	CoopGame_Source_CoopGame_Public_SExplosiveBarrel_h_17_RPC_WRAPPERS_NO_PURE_DECLS \
	CoopGame_Source_CoopGame_Public_SExplosiveBarrel_h_17_INCLASS_NO_PURE_DECLS \
	CoopGame_Source_CoopGame_Public_SExplosiveBarrel_h_17_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> COOPGAME_API UClass* StaticClass<class ASExplosiveBarrel>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID CoopGame_Source_CoopGame_Public_SExplosiveBarrel_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
