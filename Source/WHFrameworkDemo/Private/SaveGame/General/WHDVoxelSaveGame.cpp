// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "SaveGame/General/WHDVoxelSaveGame.h"

UWHDVoxelSaveGame::UWHDVoxelSaveGame()
{
	SaveName = FName("General");
}

void UWHDVoxelSaveGame::OnCreate_Implementation(int32 InSaveIndex)
{
	Super::OnCreate_Implementation(InSaveIndex);
}

void UWHDVoxelSaveGame::OnLoad_Implementation(EPhase InPhase)
{
	Super::OnLoad_Implementation(InPhase);
}

void UWHDVoxelSaveGame::OnUnload_Implementation(EPhase InPhase)
{
	Super::OnUnload_Implementation(InPhase);
}

void UWHDVoxelSaveGame::OnRefresh_Implementation()
{
	Super::OnRefresh_Implementation();

	// WHDVoxelSaveData.WorldData = AVoxelModule::Get()->GetWorldData<FDefaultVoxelWorldSaveData>();
}
