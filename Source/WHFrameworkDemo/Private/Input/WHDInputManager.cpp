// Fill out your copyright notice in the Description page of Project Settings.

#include "Input/WHDInputManager.h"

#include "Character/WHDPlayerCharacter.h"
#include "Common/CommonStatics.h"
#include "Common/WHDCommonTypes.h"
#include "Input/Components/InputComponentBase.h"
#include "Voxel/VoxelModuleStatics.h"
#include "Voxel/Voxels/Voxel.h"

// ParamSets default values
UWHDInputManager::UWHDInputManager()
{
	VoxelRaycastType = EVoxelRaycastType::FromAimPoint;
}

void UWHDInputManager::OnInitialize()
{
	Super::OnInitialize();
}

void UWHDInputManager::OnBindAction(UInputComponentBase* InInputComponent)
{
	Super::OnBindAction(InInputComponent);

	InInputComponent->BindInputAction(GameplayTags::InputTag_Interact1, ETriggerEvent::Started, this, &UWHDInputManager::DoInteractAction1);
	InInputComponent->BindInputAction(GameplayTags::InputTag_Interact2, ETriggerEvent::Started, this, &UWHDInputManager::DoInteractAction2);
	InInputComponent->BindInputAction(GameplayTags::InputTag_Interact3, ETriggerEvent::Started, this, &UWHDInputManager::DoInteractAction3);
	InInputComponent->BindInputAction(GameplayTags::InputTag_Interact4, ETriggerEvent::Started, this, &UWHDInputManager::DoInteractAction4);
	InInputComponent->BindInputAction(GameplayTags::InputTag_Interact5, ETriggerEvent::Started, this, &UWHDInputManager::DoInteractAction5);
	InInputComponent->BindInputAction(GameplayTags::InputTag_PrevInventorySlot, ETriggerEvent::Started, this, &UWHDInputManager::PrevInventorySlot);
	InInputComponent->BindInputAction(GameplayTags::InputTag_NextInventorySlot, ETriggerEvent::Started, this, &UWHDInputManager::NextInventorySlot);
}

void UWHDInputManager::OnAction1Pressed()
{
	AWHDPlayerCharacter* PlayerCharacter = UCommonStatics::GetPlayerPawn<AWHDPlayerCharacter>();

	if(!PlayerCharacter) return;

	FVoxelHitResult voxelHitResult;
	if(UVoxelModuleStatics::VoxelRaycastSinge(VoxelRaycastType, 100000.f, {}, voxelHitResult))
	{
		voxelHitResult.GetVoxel().OnAgentInteract(PlayerCharacter, EInputInteractAction::Action1, voxelHitResult);
	}
}

void UWHDInputManager::OnAction1Released()
{
}

void UWHDInputManager::OnAction2Pressed()
{
	AWHDPlayerCharacter* PlayerCharacter = UCommonStatics::GetPlayerPawn<AWHDPlayerCharacter>();

	if(!PlayerCharacter) return;

	FVoxelHitResult voxelHitResult;
	if(UVoxelModuleStatics::VoxelRaycastSinge(VoxelRaycastType, 100000.f, {}, voxelHitResult))
	{
		voxelHitResult.GetVoxel().OnAgentInteract(PlayerCharacter, EInputInteractAction::Action2, voxelHitResult);
	}
}

void UWHDInputManager::OnAction2Released()
{
}

void UWHDInputManager::DoInteractAction1()
{
	AWHDPlayerCharacter* PlayerCharacter = UCommonStatics::GetPlayerPawn<AWHDPlayerCharacter>();
	
	if(!PlayerCharacter || !PlayerCharacter->GetInteractingAgent()) return;
	
	if(PlayerCharacter->GetInteractableActions().IsValidIndex(0))
	{
		PlayerCharacter->DoInteract(PlayerCharacter->GetInteractableActions()[0]);
	}
}

void UWHDInputManager::DoInteractAction2()
{
	AWHDPlayerCharacter* PlayerCharacter = UCommonStatics::GetPlayerPawn<AWHDPlayerCharacter>();
	
	if(!PlayerCharacter || !PlayerCharacter->GetInteractingAgent()) return;
	
	if(PlayerCharacter->GetInteractableActions().IsValidIndex(1))
	{
		PlayerCharacter->DoInteract(PlayerCharacter->GetInteractableActions()[1]);
	}
}

void UWHDInputManager::DoInteractAction3()
{
	AWHDPlayerCharacter* PlayerCharacter = UCommonStatics::GetPlayerPawn<AWHDPlayerCharacter>();
	
	if(!PlayerCharacter || !PlayerCharacter->GetInteractingAgent()) return;
	
	if(PlayerCharacter->GetInteractableActions().IsValidIndex(2))
	{
		PlayerCharacter->DoInteract(PlayerCharacter->GetInteractableActions()[2]);
	}
}

void UWHDInputManager::DoInteractAction4()
{
	AWHDPlayerCharacter* PlayerCharacter = UCommonStatics::GetPlayerPawn<AWHDPlayerCharacter>();
	
	if(!PlayerCharacter || !PlayerCharacter->GetInteractingAgent()) return;
	
	if(PlayerCharacter->GetInteractableActions().IsValidIndex(3))
	{
		PlayerCharacter->DoInteract(PlayerCharacter->GetInteractableActions()[3]);
	}
}

void UWHDInputManager::DoInteractAction5()
{
	AWHDPlayerCharacter* PlayerCharacter = UCommonStatics::GetPlayerPawn<AWHDPlayerCharacter>();
	
	if(!PlayerCharacter || !PlayerCharacter->GetInteractingAgent()) return;
	
	if(PlayerCharacter->GetInteractableActions().IsValidIndex(4))
	{
		PlayerCharacter->DoInteract(PlayerCharacter->GetInteractableActions()[4]);
	}
}

void UWHDInputManager::PrevInventorySlot()
{
}

void UWHDInputManager::NextInventorySlot()
{
}
