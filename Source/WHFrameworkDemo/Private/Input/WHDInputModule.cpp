// Fill out your copyright notice in the Description page of Project Settings.


#include "Input/WHDInputModule.h"
#include "Camera/CameraModule.h"
#include "Character/WHDPlayerCharacter.h"
#include "Common/CommonBPLibrary.h"
#include "Common/WHDCommonTypes.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Input/InputModule.h"
#include "Input/InputModuleBPLibrary.h"
#include "Input/Components/InputComponentBase.h"
#include "Kismet/KismetMathLibrary.h"
#include "Voxel/VoxelModuleBPLibrary.h"
#include "Voxel/Voxels/Voxel.h"

IMPLEMENTATION_MODULE(AWHDInputModule)

// ParamSets default values
AWHDInputModule::AWHDInputModule()
{
	VoxelRaycastType = EVoxelRaycastType::FromAimPoint;
}

#if WITH_EDITOR
void AWHDInputModule::OnGenerate()
{
	Super::OnGenerate();
}

void AWHDInputModule::OnDestroy()
{
	Super::OnDestroy();
}
#endif

void AWHDInputModule::OnInitialize_Implementation()
{
	Super::OnInitialize_Implementation();
}

void AWHDInputModule::OnPreparatory_Implementation(EPhase InPhase)
{
	Super::OnPreparatory_Implementation(InPhase);
}

void AWHDInputModule::OnRefresh_Implementation(float DeltaSeconds)
{
	Super::OnRefresh_Implementation(DeltaSeconds);
}

void AWHDInputModule::OnPause_Implementation()
{
	Super::OnPause_Implementation();
}

void AWHDInputModule::OnUnPause_Implementation()
{
	Super::OnUnPause_Implementation();
}

void AWHDInputModule::OnBindAction_Implementation(UInputComponentBase* InInputComponent, UPlayerMappableInputConfig* InInputConfig)
{
	Super::OnBindAction_Implementation(InInputComponent, InInputConfig);

	InInputComponent->BindInputAction(InInputConfig, GameplayTags::InputTag_Jump, ETriggerEvent::Started, this, &AWHDInputModule::OnJumpPressed);
	InInputComponent->BindInputAction(InInputConfig, GameplayTags::InputTag_Jump, ETriggerEvent::Completed, this, &AWHDInputModule::OnJumpReleased);
	
	InInputComponent->BindInputAction(InInputConfig, GameplayTags::InputTag_Interact1, ETriggerEvent::Started, this, &AWHDInputModule::DoInteractAction1);
	InInputComponent->BindInputAction(InInputConfig, GameplayTags::InputTag_Interact2, ETriggerEvent::Started, this, &AWHDInputModule::DoInteractAction2);
	InInputComponent->BindInputAction(InInputConfig, GameplayTags::InputTag_Interact3, ETriggerEvent::Started, this, &AWHDInputModule::DoInteractAction3);
	InInputComponent->BindInputAction(InInputConfig, GameplayTags::InputTag_Interact4, ETriggerEvent::Started, this, &AWHDInputModule::DoInteractAction4);
	InInputComponent->BindInputAction(InInputConfig, GameplayTags::InputTag_Interact5, ETriggerEvent::Started, this, &AWHDInputModule::DoInteractAction5);
	InInputComponent->BindInputAction(InInputConfig, GameplayTags::InputTag_PrevInventorySlot, ETriggerEvent::Started, this, &AWHDInputModule::PrevInventorySlot);
	InInputComponent->BindInputAction(InInputConfig, GameplayTags::InputTag_NextInventorySlot, ETriggerEvent::Started, this, &AWHDInputModule::NextInventorySlot);
}

void AWHDInputModule::OnJumpPressed()
{
	AWHDPlayerCharacter* PlayerCharacter = UCommonBPLibrary::GetPlayerPawn<AWHDPlayerCharacter>();

	if(!PlayerCharacter) return;

	PlayerCharacter->Jump();
}

void AWHDInputModule::OnJumpReleased()
{
	AWHDPlayerCharacter* PlayerCharacter = UCommonBPLibrary::GetPlayerPawn<AWHDPlayerCharacter>();

	if(!PlayerCharacter) return;

	// PlayerCharacter->UnJump();
}

void AWHDInputModule::OnAction1Pressed()
{
	AWHDPlayerCharacter* PlayerCharacter = UCommonBPLibrary::GetPlayerPawn<AWHDPlayerCharacter>();

	if(!PlayerCharacter) return;

	FVoxelHitResult voxelHitResult;
	if(UVoxelModuleBPLibrary::VoxelRaycastSinge(VoxelRaycastType, 100000.f, {}, voxelHitResult))
	{
		voxelHitResult.GetVoxel().OnAgentInteract(PlayerCharacter, EInputInteractAction::Action1, voxelHitResult);
	}
}

void AWHDInputModule::OnAction1Released()
{
}

void AWHDInputModule::OnAction2Pressed()
{
	AWHDPlayerCharacter* PlayerCharacter = UCommonBPLibrary::GetPlayerPawn<AWHDPlayerCharacter>();

	if(!PlayerCharacter) return;

	FVoxelHitResult voxelHitResult;
	if(UVoxelModuleBPLibrary::VoxelRaycastSinge(VoxelRaycastType, 100000.f, {}, voxelHitResult))
	{
		voxelHitResult.GetVoxel().OnAgentInteract(PlayerCharacter, EInputInteractAction::Action2, voxelHitResult);
	}
}

void AWHDInputModule::OnAction2Released()
{
}

void AWHDInputModule::DoInteractAction1()
{
	AWHDPlayerCharacter* PlayerCharacter = UCommonBPLibrary::GetPlayerPawn<AWHDPlayerCharacter>();
	
	if(!PlayerCharacter || !PlayerCharacter->GetInteractingAgent()) return;
	
	if(PlayerCharacter->GetInteractableActions().IsValidIndex(0))
	{
		PlayerCharacter->DoInteract(PlayerCharacter->GetInteractableActions()[0]);
	}
}

void AWHDInputModule::DoInteractAction2()
{
	AWHDPlayerCharacter* PlayerCharacter = UCommonBPLibrary::GetPlayerPawn<AWHDPlayerCharacter>();
	
	if(!PlayerCharacter || !PlayerCharacter->GetInteractingAgent()) return;
	
	if(PlayerCharacter->GetInteractableActions().IsValidIndex(1))
	{
		PlayerCharacter->DoInteract(PlayerCharacter->GetInteractableActions()[1]);
	}
}

void AWHDInputModule::DoInteractAction3()
{
	AWHDPlayerCharacter* PlayerCharacter = UCommonBPLibrary::GetPlayerPawn<AWHDPlayerCharacter>();
	
	if(!PlayerCharacter || !PlayerCharacter->GetInteractingAgent()) return;
	
	if(PlayerCharacter->GetInteractableActions().IsValidIndex(2))
	{
		PlayerCharacter->DoInteract(PlayerCharacter->GetInteractableActions()[2]);
	}
}

void AWHDInputModule::DoInteractAction4()
{
	AWHDPlayerCharacter* PlayerCharacter = UCommonBPLibrary::GetPlayerPawn<AWHDPlayerCharacter>();
	
	if(!PlayerCharacter || !PlayerCharacter->GetInteractingAgent()) return;
	
	if(PlayerCharacter->GetInteractableActions().IsValidIndex(3))
	{
		PlayerCharacter->DoInteract(PlayerCharacter->GetInteractableActions()[3]);
	}
}

void AWHDInputModule::DoInteractAction5()
{
	AWHDPlayerCharacter* PlayerCharacter = UCommonBPLibrary::GetPlayerPawn<AWHDPlayerCharacter>();
	
	if(!PlayerCharacter || !PlayerCharacter->GetInteractingAgent()) return;
	
	if(PlayerCharacter->GetInteractableActions().IsValidIndex(4))
	{
		PlayerCharacter->DoInteract(PlayerCharacter->GetInteractableActions()[4]);
	}
}

void AWHDInputModule::PrevInventorySlot()
{
}

void AWHDInputModule::NextInventorySlot()
{
}
