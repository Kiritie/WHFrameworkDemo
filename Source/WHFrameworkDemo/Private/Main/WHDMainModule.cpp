// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "Main/WHDMainModule.h"

#include "Ability/AbilityModule.h"
#include "AI/AIModule.h"
#include "Asset/AssetModule.h"
#include "Audio/AudioModule.h"
#include "Camera/CameraModule.h"
#include "Character/CharacterModule.h"
#include "Debug/DebugModule.h"
#include "Event/EventModule.h"
#include "FSM/FSMModule.h"
#include "Input/InputModule.h"
#include "LatentAction/LatentActionModule.h"
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
#include "Voxel/Voxels/Voxel.h"
#include "WebRequest/WebRequestModule.h"
#include "Widget/WidgetModule.h"

IMPLEMENTATION_MAIN_MODULE(AWHDMainModule)

AWHDMainModule::AWHDMainModule()
{
	ModuleClasses = TArray<TSubclassOf<AModuleBase>>();
	ModuleClasses.Add(AAbilityModule::StaticClass());
	ModuleClasses.Add(AAIModule::StaticClass());
	ModuleClasses.Add(AAssetModule::StaticClass());
	ModuleClasses.Add(AAudioModule::StaticClass());
	ModuleClasses.Add(ACameraModule::StaticClass());
	ModuleClasses.Add(ACharacterModule::StaticClass());
	ModuleClasses.Add(ADebugModule::StaticClass());
	ModuleClasses.Add(AEventModule::StaticClass());
	ModuleClasses.Add(AFSMModule::StaticClass());
	ModuleClasses.Add(AInputModule::StaticClass());
	ModuleClasses.Add(ALatentActionModule::StaticClass());
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

