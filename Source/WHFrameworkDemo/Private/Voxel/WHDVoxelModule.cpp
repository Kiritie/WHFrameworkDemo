// Fill out your copyright notice in the Description page of Project Settings.


#include "Voxel/WHDVoxelModule.h"

#include "Components/StaticMeshComponent.h"
#include "Voxel/WHDVoxelChunk.h"
#include "Voxel/VoxelModuleBPLibrary.h"
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

void AWHDVoxelModule::OnTermination_Implementation(EPhase InPhase)
{
	Super::OnTermination_Implementation(InPhase);
}

ECollisionChannel AWHDVoxelModule::GetChunkTraceChannel() const
{
	return ECollisionChannel::ECC_GameTraceChannel9;
}

ECollisionChannel AWHDVoxelModule::GetVoxelTraceChannel() const
{
	return ECollisionChannel::ECC_GameTraceChannel10;
}
