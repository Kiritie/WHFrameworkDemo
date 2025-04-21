// Fill out your copyright notice in the Description page of Project Settings.

#include "Input/WHDVoxelInputManager.h"

#include "Character/WHDPlayerCharacter.h"
#include "Common/CommonStatics.h"
#include "Voxel/VoxelModuleStatics.h"
#include "Voxel/Voxels/Voxel.h"

// ParamSets default values
UWHDVoxelInputManager::UWHDVoxelInputManager()
{
	VoxelRaycastType = EVoxelRaycastType::FromAimPoint;
	InteractDistance = 500.f;
}

void UWHDVoxelInputManager::OnInitialize()
{
	Super::OnInitialize();
}

void UWHDVoxelInputManager::OnBindAction(UInputComponentBase* InInputComponent)
{
	Super::OnBindAction(InInputComponent);
}

void UWHDVoxelInputManager::OnPrimaryPressed_Implementation()
{
	AWHDPlayerCharacter* PlayerCharacter = UCommonStatics::GetPlayerPawn<AWHDPlayerCharacter>();

	if(!PlayerCharacter) return;

	FVoxelHitResult VoxelHitResult;
	if(UVoxelModuleStatics::VoxelRaycastSinge(VoxelRaycastType, InteractDistance, {}, VoxelHitResult))
	{
		PlayerCharacter->InteractVoxel(EInputInteractAction::Primary, EInputInteractEvent::Started, VoxelHitResult);
	}
}

void UWHDVoxelInputManager::OnPrimaryRepeated_Implementation()
{
	AWHDPlayerCharacter* PlayerCharacter = UCommonStatics::GetPlayerPawn<AWHDPlayerCharacter>();

	if(!PlayerCharacter) return;

	FVoxelHitResult VoxelHitResult;
	if(UVoxelModuleStatics::VoxelRaycastSinge(VoxelRaycastType, InteractDistance, {}, VoxelHitResult))
	{
		PlayerCharacter->InteractVoxel(EInputInteractAction::Primary, EInputInteractEvent::Triggered, VoxelHitResult);
	}
}

void UWHDVoxelInputManager::OnPrimaryReleased_Implementation()
{
	AWHDPlayerCharacter* PlayerCharacter = UCommonStatics::GetPlayerPawn<AWHDPlayerCharacter>();

	if(!PlayerCharacter) return;

	FVoxelHitResult VoxelHitResult;
	if(UVoxelModuleStatics::VoxelRaycastSinge(VoxelRaycastType, InteractDistance, {}, VoxelHitResult))
	{
		PlayerCharacter->InteractVoxel(EInputInteractAction::Primary, EInputInteractEvent::Completed, VoxelHitResult);
	}
	else
	{
		PlayerCharacter->UnInteractVoxel(EInputInteractAction::Primary, EInputInteractEvent::Completed);
	}
}

void UWHDVoxelInputManager::OnSecondaryPressed_Implementation()
{
	AWHDPlayerCharacter* PlayerCharacter = UCommonStatics::GetPlayerPawn<AWHDPlayerCharacter>();

	if(!PlayerCharacter) return;

	FVoxelHitResult VoxelHitResult;
	if(UVoxelModuleStatics::VoxelRaycastSinge(VoxelRaycastType, InteractDistance, {}, VoxelHitResult))
	{
		PlayerCharacter->InteractVoxel(EInputInteractAction::Secondary, EInputInteractEvent::Started, VoxelHitResult);
	}
}

void UWHDVoxelInputManager::OnSecondaryRepeated_Implementation()
{
	AWHDPlayerCharacter* PlayerCharacter = UCommonStatics::GetPlayerPawn<AWHDPlayerCharacter>();

	if(!PlayerCharacter) return;

	FVoxelHitResult VoxelHitResult;
	if(UVoxelModuleStatics::VoxelRaycastSinge(VoxelRaycastType, InteractDistance, {}, VoxelHitResult))
	{
		PlayerCharacter->InteractVoxel(EInputInteractAction::Secondary, EInputInteractEvent::Triggered, VoxelHitResult);
	}
}

void UWHDVoxelInputManager::OnSecondaryReleased_Implementation()
{
	AWHDPlayerCharacter* PlayerCharacter = UCommonStatics::GetPlayerPawn<AWHDPlayerCharacter>();

	if(!PlayerCharacter) return;

	FVoxelHitResult VoxelHitResult;
	if(UVoxelModuleStatics::VoxelRaycastSinge(VoxelRaycastType, InteractDistance, {}, VoxelHitResult))
	{
		PlayerCharacter->InteractVoxel(EInputInteractAction::Secondary, EInputInteractEvent::Completed, VoxelHitResult);
	}
	else
	{
		PlayerCharacter->UnInteractVoxel(EInputInteractAction::Secondary, EInputInteractEvent::Completed);
	}
}
