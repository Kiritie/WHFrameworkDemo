// Fill out your copyright notice in the Description page of Project Settings.

#include "Input/WHDVoxelInputManager.h"

#include "Character/WHDPlayerCharacter.h"
#include "Common/CommonStatics.h"
#include "Common/WHDCommonTypes.h"
#include "Input/Components/InputComponentBase.h"
#include "Voxel/VoxelModuleStatics.h"
#include "Voxel/Voxels/Voxel.h"

// ParamSets default values
UWHDVoxelInputManager::UWHDVoxelInputManager()
{
	VoxelRaycastType = EVoxelRaycastType::FromAimPoint;
}

void UWHDVoxelInputManager::OnInitialize()
{
	Super::OnInitialize();
}

void UWHDVoxelInputManager::OnBindAction(UInputComponentBase* InInputComponent)
{
	Super::OnBindAction(InInputComponent);

	InInputComponent->BindInputAction(GameplayTags::InputTag_Primary, ETriggerEvent::Started, this, &UWHDVoxelInputManager::OnPrimaryPressed);
	InInputComponent->BindInputAction(GameplayTags::InputTag_Primary, ETriggerEvent::Completed, this, &UWHDVoxelInputManager::OnPrimaryReleased);

	InInputComponent->BindInputAction(GameplayTags::InputTag_Minor, ETriggerEvent::Started, this, &UWHDVoxelInputManager::OnMinorPressed);
	InInputComponent->BindInputAction(GameplayTags::InputTag_Minor, ETriggerEvent::Completed, this, &UWHDVoxelInputManager::OnMinorReleased);

	InInputComponent->BindInputAction(GameplayTags::InputTag_PrevInventorySlot, ETriggerEvent::Started, this, &UWHDVoxelInputManager::PrevInventorySlot);
	InInputComponent->BindInputAction(GameplayTags::InputTag_NextInventorySlot, ETriggerEvent::Started, this, &UWHDVoxelInputManager::NextInventorySlot);
}

void UWHDVoxelInputManager::OnPrimaryPressed()
{
	AWHDPlayerCharacter* PlayerCharacter = UCommonStatics::GetPlayerPawn<AWHDPlayerCharacter>();

	if(!PlayerCharacter) return;

	FVoxelHitResult voxelHitResult;
	if(UVoxelModuleStatics::VoxelRaycastSinge(VoxelRaycastType, 100000.f, {}, voxelHitResult))
	{
		voxelHitResult.GetVoxel().OnAgentInteract(PlayerCharacter, EInputInteractAction::Action1, voxelHitResult);
	}
}

void UWHDVoxelInputManager::OnPrimaryReleased()
{
}

void UWHDVoxelInputManager::OnMinorPressed()
{
	AWHDPlayerCharacter* PlayerCharacter = UCommonStatics::GetPlayerPawn<AWHDPlayerCharacter>();

	if(!PlayerCharacter) return;

	FVoxelHitResult voxelHitResult;
	if(UVoxelModuleStatics::VoxelRaycastSinge(VoxelRaycastType, 100000.f, {}, voxelHitResult))
	{
		voxelHitResult.GetVoxel().OnAgentInteract(PlayerCharacter, EInputInteractAction::Action2, voxelHitResult);
	}
}

void UWHDVoxelInputManager::OnMinorReleased()
{
}

void UWHDVoxelInputManager::PrevInventorySlot()
{
}

void UWHDVoxelInputManager::NextInventorySlot()
{
}
