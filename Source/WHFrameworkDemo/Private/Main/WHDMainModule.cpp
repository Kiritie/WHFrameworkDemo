// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "Main/WHDMainModule.h"

#include "Ability/AbilityModule.h"
#include "Ability/WHDAbilityModule.h"
#include "AI/AIModule.h"
#include "Asset/AssetModule.h"
#include "Audio/AudioModule.h"
#include "Camera/CameraModule.h"
#include "Character/CharacterModule.h"
#include "Debug/DebugModule.h"
#include "Event/EventModule.h"
#include "FSM/FSMModule.h"
#include "Animation/AnimationModule.h"
#include "Common/CommonBPLibrary.h"
#include "Input/WHDInputModule.h"
#include "Media/MediaModule.h"
#include "Network/NetworkModule.h"
#include "ObjectPool/ObjectPoolModule.h"
#include "Parameter/ParameterModule.h"
#include "Procedure/ProcedureModule.h"
#include "SaveGame/SaveGameModule.h"
#include "Scene/SceneModule.h"
#include "Step/StepModule.h"
#include "Task/TaskModule.h"
#include "Voxel/WHDVoxelModule.h"
#include "WebRequest/WebRequestModule.h"
#include "Widget/WidgetModule.h"

IMPLEMENTATION_MAIN_MODULE(AWHDMainModule)

AWHDMainModule::AWHDMainModule()
{
	ModuleClasses = TArray<TSubclassOf<AModuleBase>>();
	ModuleClasses.Add(AWHDAbilityModule::StaticClass());
	ModuleClasses.Add(AAIModule::StaticClass());
	ModuleClasses.Add(AAnimationModule::StaticClass());
	ModuleClasses.Add(AAssetModule::StaticClass());
	ModuleClasses.Add(AAudioModule::StaticClass());
	ModuleClasses.Add(ACameraModule::StaticClass());
	ModuleClasses.Add(ACharacterModule::StaticClass());
	ModuleClasses.Add(ADebugModule::StaticClass());
	ModuleClasses.Add(AEventModule::StaticClass());
	ModuleClasses.Add(AFSMModule::StaticClass());
	ModuleClasses.Add(AWHDInputModule::StaticClass());
	ModuleClasses.Add(AMediaModule::StaticClass());
	ModuleClasses.Add(ANetworkModule::StaticClass());
	ModuleClasses.Add(AObjectPoolModule::StaticClass());
	ModuleClasses.Add(AParameterModule::StaticClass());
	ModuleClasses.Add(AProcedureModule::StaticClass());
	ModuleClasses.Add(AReferencePoolModule::StaticClass());
	ModuleClasses.Add(ASaveGameModule::StaticClass());
	ModuleClasses.Add(ASceneModule::StaticClass());
	ModuleClasses.Add(AStepModule::StaticClass());
	ModuleClasses.Add(ATaskModule::StaticClass());
	ModuleClasses.Add(AWHDVoxelModule::StaticClass());
	ModuleClasses.Add(AWebRequestModule::StaticClass());
	ModuleClasses.Add(AWidgetModule::StaticClass());
}

AWHDMainModule::~AWHDMainModule()
{
	TERMINATION_MAIN_MODULE(AWHDMainModule)
}

#if WITH_EDITOR
void AWHDMainModule::OnGenerate()
{
	Super::OnGenerate();
}

void AWHDMainModule::OnDestroy()
{
	Super::OnDestroy();
}
#endif

void AWHDMainModule::OnInitialize_Implementation()
{
	Super::OnInitialize_Implementation();
}

void AWHDMainModule::OnPreparatory_Implementation(EPhase InPhase)
{
	Super::OnPreparatory_Implementation(InPhase);
}

void AWHDMainModule::OnRefresh_Implementation(float DeltaSeconds)
{
	Super::OnRefresh_Implementation(DeltaSeconds);
}

void AWHDMainModule::OnPause_Implementation()
{
	Super::OnPause_Implementation();
}

void AWHDMainModule::OnUnPause_Implementation()
{
	Super::OnUnPause_Implementation();
}

void AWHDMainModule::OnTermination_Implementation(EPhase InPhase)
{
	Super::OnTermination_Implementation(InPhase);
}

