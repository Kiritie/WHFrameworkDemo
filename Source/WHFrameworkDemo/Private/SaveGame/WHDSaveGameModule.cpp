// Fill out your copyright notice in the Description page of Project Settings.


#include "SaveGame/WHDSaveGameModule.h"

#include "Camera/CameraModuleBPLibrary.h"
#include "Debug/DebugModuleTypes.h"
#include "Kismet/GameplayStatics.h"
#include "SaveGame/General/WHDVoxelSaveGame.h"
#include "SaveGame/SaveGameModuleBPLibrary.h"
	
IMPLEMENTATION_MODULE(AWHDSaveGameModule)

// ParamSets default values
AWHDSaveGameModule::AWHDSaveGameModule()
{
	GeneralSaveGame = UWHDVoxelSaveGame::StaticClass();
}

AWHDSaveGameModule::~AWHDSaveGameModule()
{
	TERMINATION_MODULE(AWHDSaveGameModule)
}

#if WITH_EDITOR
void AWHDSaveGameModule::OnGenerate()
{
	Super::OnGenerate();
}

void AWHDSaveGameModule::OnDestroy()
{
	Super::OnDestroy();
}
#endif

void AWHDSaveGameModule::OnInitialize_Implementation()
{
	Super::OnInitialize_Implementation();
}

void AWHDSaveGameModule::OnPreparatory_Implementation(EPhase InPhase)
{
	Super::OnPreparatory_Implementation(InPhase);
}

void AWHDSaveGameModule::OnRefresh_Implementation(float DeltaSeconds)
{
	Super::OnRefresh_Implementation(DeltaSeconds);
}

void AWHDSaveGameModule::OnPause_Implementation()
{
	Super::OnPause_Implementation();
}

void AWHDSaveGameModule::OnUnPause_Implementation()
{
	Super::OnUnPause_Implementation();
}

void AWHDSaveGameModule::OnTermination_Implementation()
{
	Super::OnTermination_Implementation();
}

void AWHDSaveGameModule::LoadData(FSaveData* InSaveData, EPhase InPhase)
{
	Super::LoadData(InSaveData, InPhase);
}

FSaveData* AWHDSaveGameModule::ToData(bool bRefresh)
{
	return Super::ToData(bRefresh);
}
