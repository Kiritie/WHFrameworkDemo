// Fill out your copyright notice in the Description page of Project Settings.

#include "Input/WHDVoxelInputManager.h"

#include "Character/WHDPlayerCharacter.h"
#include "Common/CommonStatics.h"
#include "Common/WHDCommonTypes.h"
#include "Common/Widget/Inventory/WHDWidgetCommonInventoryBar.h"
#include "Input/Components/InputComponentBase.h"
#include "Voxel/VoxelModuleStatics.h"
#include "Voxel/Voxels/Voxel.h"
#include "Widget/WidgetModuleStatics.h"

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

	InInputComponent->BindInputAction(GameplayTags::Input_Primary, ETriggerEvent::Started, this, &UWHDVoxelInputManager::OnPrimaryPressed);
	InInputComponent->BindInputAction(GameplayTags::Input_Primary, ETriggerEvent::Completed, this, &UWHDVoxelInputManager::OnPrimaryReleased);

	InInputComponent->BindInputAction(GameplayTags::Input_Secondary, ETriggerEvent::Started, this, &UWHDVoxelInputManager::OnSecondaryPressed);
	InInputComponent->BindInputAction(GameplayTags::Input_Secondary, ETriggerEvent::Completed, this, &UWHDVoxelInputManager::OnSecondaryReleased);

	InInputComponent->BindInputAction(GameplayTags::Input_PrevInventorySlot, ETriggerEvent::Started, this, &UWHDVoxelInputManager::PrevInventorySlot);
	InInputComponent->BindInputAction(GameplayTags::Input_NextInventorySlot, ETriggerEvent::Started, this, &UWHDVoxelInputManager::NextInventorySlot);
}

void UWHDVoxelInputManager::OnPrimaryPressed()
{
	AWHDPlayerCharacter* PlayerCharacter = UCommonStatics::GetPlayerPawn<AWHDPlayerCharacter>();

	if(!PlayerCharacter) return;

	FVoxelHitResult VoxelHitResult;
	if(UVoxelModuleStatics::VoxelRaycastSinge(VoxelRaycastType, 100000.f, {}, VoxelHitResult))
	{
		VoxelHitResult.GetVoxel().OnAgentInteract(PlayerCharacter, EInputInteractAction::Primary, VoxelHitResult);
	}
}

void UWHDVoxelInputManager::OnPrimaryReleased()
{
}

void UWHDVoxelInputManager::OnSecondaryPressed()
{
	AWHDPlayerCharacter* PlayerCharacter = UCommonStatics::GetPlayerPawn<AWHDPlayerCharacter>();

	if(!PlayerCharacter) return;

	FVoxelHitResult VoxelHitResult;
	if(UVoxelModuleStatics::VoxelRaycastSinge(VoxelRaycastType, 100000.f, {}, VoxelHitResult))
	{
		VoxelHitResult.GetVoxel().OnAgentInteract(PlayerCharacter, EInputInteractAction::Secondary, VoxelHitResult);
	}
}

void UWHDVoxelInputManager::OnSecondaryReleased()
{
}

void UWHDVoxelInputManager::PrevInventorySlot()
{
	UWidgetModuleStatics::GetUserWidget<UWHDWidgetCommonInventoryBar>()->PrevInventorySlot();
}

void UWHDVoxelInputManager::NextInventorySlot()
{
	UWidgetModuleStatics::GetUserWidget<UWHDWidgetCommonInventoryBar>()->NextInventorySlot();
}
