// Fill out your copyright notice in the Description page of Project Settings.


#include "Input/WHDInputModule.h"
#include "Camera/CameraModule.h"
#include "Character/WHDPlayerCharacter.h"
#include "Common/CommonBPLibrary.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Input/InputModule.h"
#include "Input/InputModuleBPLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"
#include "Voxel/VoxelModuleBPLibrary.h"
#include "Voxel/Voxels/Voxel.h"
#include "Widget/WidgetModuleBPLibrary.h"

IMPLEMENTATION_MODULE(AWHDInputModule)

// ParamSets default values
AWHDInputModule::AWHDInputModule()
{
	ActionMappings.Add(FInputActionMapping("Jump", IE_Pressed, this, "OnJumpPressed"));
	ActionMappings.Add(FInputActionMapping("Jump", IE_Released, this, "OnJumpReleased"));

	ActionMappings.Add(FInputActionMapping("Action1", IE_Pressed, this, "OnAction1Pressed"));
	ActionMappings.Add(FInputActionMapping("Action1", IE_Released, this, "OnAction1Released"));

	ActionMappings.Add(FInputActionMapping("Action2", IE_Pressed, this, "OnAction2Pressed"));
	ActionMappings.Add(FInputActionMapping("Action2", IE_Released, this, "OnAction2Released"));
	
	ActionMappings.Add(FInputActionMapping("Interact1", IE_Pressed, this, "DoInteractAction1"));
	ActionMappings.Add(FInputActionMapping("Interact2", IE_Pressed, this, "DoInteractAction2"));
	ActionMappings.Add(FInputActionMapping("Interact3", IE_Pressed, this, "DoInteractAction3"));
	ActionMappings.Add(FInputActionMapping("Interact4", IE_Pressed, this, "DoInteractAction4"));
	ActionMappings.Add(FInputActionMapping("Interact5", IE_Pressed, this, "DoInteractAction5"));

	ActionMappings.Add(FInputActionMapping("PrevInventorySlot", IE_Pressed, this, "PrevInventorySlot"));
	ActionMappings.Add(FInputActionMapping("NextInventorySlot", IE_Pressed, this, "NextInventorySlot"));

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

void AWHDInputModule::OnJumpPressed(FKey Key)
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
