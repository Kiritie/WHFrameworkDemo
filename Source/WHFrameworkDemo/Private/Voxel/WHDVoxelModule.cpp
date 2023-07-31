// Fill out your copyright notice in the Description page of Project Settings.


#include "Voxel/WHDVoxelModule.h"

#include "TimerManager.h"
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
#include "SaveGame/General/WHDVoxelSaveGame.h"
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
void AWHDVoxelModule::OnGenerate()
{
	Super::OnGenerate();
}

void AWHDVoxelModule::OnDestroy()
{
	Super::OnDestroy();
}
#endif

void AWHDVoxelModule::OnInitialize_Implementation()
{
	Super::OnInitialize_Implementation();
}

void AWHDVoxelModule::OnPreparatory_Implementation(EPhase InPhase)
{
	Super::OnPreparatory_Implementation(InPhase);

	if(InPhase == EPhase::Final)
	{
		if(!USaveGameModuleBPLibrary::GetSaveGame<UWHDVoxelSaveGame>()->IsSaved())
		{
			LoadSaveData(NewData(true), EPhase::Primary);
		}
		else
		{
			LoadSaveData(USaveGameModuleBPLibrary::GetSaveGame<UWHDVoxelSaveGame>()->GetSaveData(), EPhase::Primary);
		}
	}
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

ECollisionChannel AWHDVoxelModule::GetChunkTraceType() const
{
	return ECollisionChannel::ECC_GameTraceChannel9;
}

ECollisionChannel AWHDVoxelModule::GetVoxelTraceType() const
{
	return ECollisionChannel::ECC_GameTraceChannel10;
}
