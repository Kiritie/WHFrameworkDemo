// Fill out your copyright notice in the Description page of Project Settings.


#include "Voxel/WHDVoxelModule.h"

#include "Components/StaticMeshComponent.h"
#include "Gameplay/WHDGameState.h"
#include "Gameplay/WHDPlayerController.h"
#include "Global/GlobalBPLibrary.h"
#include "Procedure/ProcedureModuleBPLibrary.h"
#include "ReferencePool/ReferencePoolModuleBPLibrary.h"
#include "Voxel/WHDVoxelChunk.h"
#include "Voxel/VoxelModuleBPLibrary.h"
#include "Voxel/Chunks/VoxelChunk.h"
#include "Voxel/Datas/VoxelData.h"
#include "Widget/WidgetModuleBPLibrary.h"
#include "SaveGame/SaveGameModuleBPLibrary.h"
#include "UObject/ConstructorHelpers.h"
	
IMPLEMENTATION_MODULE(AWHDVoxelModule)

// Sets default values
AWHDVoxelModule::AWHDVoxelModule()
{
	ChunkSpawnClass = AWHDVoxelChunk::StaticClass();
}

AWHDVoxelModule::~AWHDVoxelModule()
{
	TERMINATION_MODULE(AWHDVoxelModule)
}

#if WITH_EDITOR
void AWHDVoxelModule::OnGenerate_Implementation()
{
	Super::OnGenerate_Implementation();
}

void AWHDVoxelModule::OnDestroy_Implementation()
{
	Super::OnDestroy_Implementation();
}
#endif

void AWHDVoxelModule::OnInitialize_Implementation()
{
	Super::OnInitialize_Implementation();
}

void AWHDVoxelModule::OnPreparatory_Implementation(EPhase InPhase)
{
	Super::OnPreparatory_Implementation(InPhase);
}

void AWHDVoxelModule::OnRefresh_Implementation(float DeltaSeconds)
{
	Super::OnRefresh_Implementation(DeltaSeconds);
}

void AWHDVoxelModule::OnPause_Implementation()
{
	Super::OnPause_Implementation();
}

void AWHDVoxelModule::OnUnPause_Implementation()
{
	Super::OnUnPause_Implementation();
}

void AWHDVoxelModule::OnTermination_Implementation()
{
	Super::OnTermination_Implementation();
}

void AWHDVoxelModule::LoadData(FSaveData* InSaveData, EPhase InPhase)
{
	Super::LoadData(InSaveData, InPhase);
}

FSaveData* AWHDVoxelModule::ToData()
{
	return Super::ToData();
}

void AWHDVoxelModule::UnloadData(EPhase InPhase)
{
	Super::UnloadData(InPhase);
}

void AWHDVoxelModule::OnWorldStateChanged()
{
	Super::OnWorldStateChanged();
}

void AWHDVoxelModule::GenerateVoxels()
{
	Super::GenerateVoxels();
}

void AWHDVoxelModule::GenerateWorld()
{
	Super::GenerateWorld();
}

void AWHDVoxelModule::BuildChunkMap(FIndex InIndex, int32 InStage)
{
	Super::BuildChunkMap(InIndex, InStage);
}

void AWHDVoxelModule::BuildChunkMesh(FIndex InIndex)
{
	Super::BuildChunkMesh(InIndex);
}

void AWHDVoxelModule::GenerateChunk(FIndex InIndex)
{
	Super::GenerateChunk(InIndex);
}

void AWHDVoxelModule::DestroyChunk(FIndex InIndex)
{
	Super::DestroyChunk(InIndex);
}

AVoxelChunk* AWHDVoxelModule::SpawnChunk(FIndex InIndex, bool bAddToQueue)
{
	return Super::SpawnChunk(InIndex, bAddToQueue);
}

ECollisionChannel AWHDVoxelModule::GetChunkTraceType() const
{
	return Super::GetChunkTraceType();
}

ECollisionChannel AWHDVoxelModule::GetVoxelTraceType() const
{
	return Super::GetVoxelTraceType();
}
