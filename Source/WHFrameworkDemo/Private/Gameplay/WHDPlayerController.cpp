// Fill out your copyright notice in the Description page of Project Settings.


#include "Gameplay/WHDPlayerController.h"

#include "Engine/World.h"
#include "Engine.h"
#include "Ability/AbilityModuleBPLibrary.h"
#include "Ability/Character/AbilityCharacterDataBase.h"
#include "Ability/Components/CharacterInteractionComponent.h"
#include "Ability/Components/InteractionComponent.h"
#include "Ability/Item/Equip/AbilityEquipDataBase.h"
#include "Ability/Item/Prop/AbilityPropDataBase.h"
#include "Ability/Item/Skill/AbilitySkillDataBase.h"
#include "Camera/CameraModuleBPLibrary.h"
#include "FSM/Components/FSMComponent.h"
#include "Gameplay/WHDGameInstance.h"
#include "Gameplay/WHDGameState.h"
#include "Gameplay/WHDGameMode.h"
#include "Global/GlobalBPLibrary.h"
#include "Input/InputModuleBPLibrary.h"
#include "Ability/Inventory/Slot/InventorySlot.h"
#include "Ability/Inventory/CharacterInventory.h"
#include "Ability/Inventory/Slot/InventorySkillSlot.h"
#include "Procedure/ProcedureModuleBPLibrary.h"
#include "SaveGame/SaveGameModuleBPLibrary.h"
#include "Voxel/VoxelModule.h"
#include "Voxel/Datas/VoxelData.h"
#include "Widget/WidgetModuleBPLibrary.h"
#include "ObjectPool/ObjectPoolModuleBPLibrary.h"
#include "Voxel/VoxelModuleBPLibrary.h"
#include "Voxel/Chunks/VoxelChunk.h"
#include "Voxel/Voxels/Voxel.h"
#include "Camera/CameraModule.h"

AWHDPlayerController::AWHDPlayerController()
{
}

void AWHDPlayerController::OnInitialize_Implementation()
{
	Super::OnInitialize_Implementation();
}

void AWHDPlayerController::OnPreparatory_Implementation(EPhase InPhase)
{
	Super::OnPreparatory_Implementation(InPhase);
}

void AWHDPlayerController::OnRefresh_Implementation(float DeltaSeconds)
{
	Super::OnRefresh_Implementation(DeltaSeconds);
}

void AWHDPlayerController::OnTermination_Implementation(EPhase InPhase)
{
	Super::OnTermination_Implementation(InPhase);
}

void AWHDPlayerController::LoadData(FSaveData* InSaveData, EPhase InPhase)
{
}

FSaveData* AWHDPlayerController::ToData(bool bRefresh)
{
	return nullptr;
}

void AWHDPlayerController::UnloadData(EPhase InPhase)
{
}
