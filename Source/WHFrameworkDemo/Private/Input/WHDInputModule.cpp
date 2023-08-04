// Fill out your copyright notice in the Description page of Project Settings.


#include "Input/WHDInputModule.h"

#include "Ability/Components/CharacterInteractionComponent.h"
#include "Ability/Inventory/CharacterInventory.h"
#include "Ability/Inventory/Slot/InventorySlot.h"
#include "Camera/CameraModule.h"
#include "Character/WHDPlayerCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/PawnMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Gameplay/WHPlayerInterface.h"
#include "Global/GlobalBPLibrary.h"
#include "Input/InputModule.h"
#include "Input/InputModuleBPLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"
#include "Main/MainModule.h"
#include "Math/MathBPLibrary.h"
#include "Media/MediaModuleNetworkComponent.h"
#include "Network/NetworkModuleNetworkComponent.h"
#include "Procedure/ProcedureModule.h"
#include "Procedure/ProcedureModuleBPLibrary.h"
#include "Procedure/ProcedureModuleNetworkComponent.h"
#include "Voxel/VoxelModuleBPLibrary.h"
#include "Voxel/Voxels/Voxel.h"
#include "Widget/WidgetModuleBPLibrary.h"

IMPLEMENTATION_MODULE(AWHDInputModule)

// ParamSets default values
AWHDInputModule::AWHDInputModule()
{
	ActionMappings.Add(FInputActionMapping("Jump", IE_Pressed, this, "OnJumpPressed"));
	ActionMappings.Add(FInputActionMapping("Jump", IE_Released, this, "OnJumpReleased"));

	ActionMappings.Add(FInputActionMapping("Primary", IE_Pressed, this, "OnPrimaryPressed"));
	ActionMappings.Add(FInputActionMapping("Primary", IE_Released, this, "OnPrimaryReleased"));

	ActionMappings.Add(FInputActionMapping("Minor", IE_Pressed, this, "OnMinorPressed"));
	ActionMappings.Add(FInputActionMapping("Minor", IE_Released, this, "OnMinorReleased"));

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

FEventReply AWHDInputModule::OnWidgetInputKeyDown_Implementation(const FGeometry& InGeometry, const FKeyEvent& InKeyEvent)
{
	return Super::OnWidgetInputKeyDown_Implementation(InGeometry, InKeyEvent);
}

FEventReply AWHDInputModule::OnWidgetInputKeyUp_Implementation(const FGeometry& InGeometry, const FKeyEvent& InKeyEvent)
{
	return Super::OnWidgetInputKeyUp_Implementation(InGeometry, InKeyEvent);
}

void AWHDInputModule::OnJumpPressed(FKey Key)
{
	AWHDPlayerCharacter* PlayerCharacter = UGlobalBPLibrary::GetPlayerPawn<AWHDPlayerCharacter>();

	if(!PlayerCharacter) return;

	PlayerCharacter->Jump();
}

void AWHDInputModule::OnJumpReleased()
{
	AWHDPlayerCharacter* PlayerCharacter = UGlobalBPLibrary::GetPlayerPawn<AWHDPlayerCharacter>();

	if(!PlayerCharacter) return;

	// PlayerCharacter->UnJump();
}

void AWHDInputModule::OnPrimaryPressed()
{
	AWHDPlayerCharacter* PlayerCharacter = UGlobalBPLibrary::GetPlayerPawn<AWHDPlayerCharacter>();

	if(!PlayerCharacter) return;

	FVoxelHitResult voxelHitResult;
	if(UVoxelModuleBPLibrary::VoxelRaycastSinge(VoxelRaycastType, 100000.f, {}, voxelHitResult))
	{
		voxelHitResult.GetVoxel().OnActionTrigger(PlayerCharacter, EVoxelActionType::Action1, voxelHitResult);
	}
}

void AWHDInputModule::OnPrimaryReleased()
{
}

void AWHDInputModule::OnMinorPressed()
{
	AWHDPlayerCharacter* PlayerCharacter = UGlobalBPLibrary::GetPlayerPawn<AWHDPlayerCharacter>();

	if(!PlayerCharacter) return;

	FVoxelHitResult voxelHitResult;
	if(UVoxelModuleBPLibrary::VoxelRaycastSinge(VoxelRaycastType, 100000.f, {}, voxelHitResult))
	{
		voxelHitResult.GetVoxel().OnActionTrigger(PlayerCharacter, EVoxelActionType::Action2, voxelHitResult);
	}
}

void AWHDInputModule::OnMinorReleased()
{
}

void AWHDInputModule::PrevInventorySlot()
{
}

void AWHDInputModule::NextInventorySlot()
{
}
