// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "Character/WHDPlayerCharacter.h"

#include "Ability/Character/AbilityCharacterInventoryBase.h"
#include "Ability/Character/States/AbilityCharacterState_Fall.h"
#include "Ability/Character/States/AbilityCharacterState_Jump.h"
#include "Ability/Character/States/AbilityCharacterState_Static.h"
#include "Ability/Character/States/AbilityCharacterState_Walk.h"
#include "Ability/Components/AbilitySystemComponentBase.h"
#include "Character/CharacterModuleStatics.h"
#include "Character/State/WHDPlayerCharacterState_Death.h"
#include "Character/State/WHDPlayerCharacterState_Spawn.h"
#include "Common/WHDCommonTypes.h"
#include "Common/Interaction/InteractionComponent.h"
#include "Common/Widget/Interaction/WHDWidgetCommonInteractionBox.h"
#include "Components/SkeletalMeshComponent.h"
#include "FSM/Components/FSMComponent.h"
#include "Voxel/Voxels/Auxiliary/VoxelInteractAuxiliary.h"
#include "Widget/WidgetModuleStatics.h"

//////////////////////////////////////////////////////////////////////////
// AWHDPlayerCharacter

AWHDPlayerCharacter::AWHDPlayerCharacter(const FObjectInitializer& ObjectInitializer) :
	Super(ObjectInitializer.SetDefaultSubobjectClass<UAbilitySystemComponentBase>("AbilitySystem").
		SetDefaultSubobjectClass<UCharacterAttributeSetBase>("AttributeSet").
		SetDefaultSubobjectClass<UAbilityCharacterInventoryBase>("Inventory"))
{
	GetMesh()->SetRelativeLocation(FVector(0.f, 0.f, -70.f));

	Interaction->SetRelativeLocation(FVector(0.f, 0.f, -39.f));

	FSM->bAutoSwitchDefault = true;

	FSM->DefaultState = UWHDPlayerCharacterState_Spawn::StaticClass();
	FSM->FinalState = UWHDPlayerCharacterState_Death::StaticClass();

	FSM->States.Empty();
	FSM->States.Add(UWHDPlayerCharacterState_Death::StaticClass());
	FSM->States.Add(UWHDPlayerCharacterState_Spawn::StaticClass());
	FSM->States.Add(UAbilityCharacterState_Fall::StaticClass());
	FSM->States.Add(UAbilityCharacterState_Jump::StaticClass());
	FSM->States.Add(UAbilityCharacterState_Static::StaticClass());
	FSM->States.Add(UAbilityCharacterState_Walk::StaticClass());

	AutoPossessAI = EAutoPossessAI::Disabled;
}

void AWHDPlayerCharacter::OnInitialize_Implementation()
{
	Super::OnInitialize_Implementation();

	FInventorySaveData InventorySaveData;
	InventorySaveData.InventoryClass = UAbilityCharacterInventoryBase::StaticClass();
	InventorySaveData.SplitItems.Add(ESlotSplitType::Shortcut, 10);
	
	Inventory->LoadSaveData(&InventorySaveData);
}

void AWHDPlayerCharacter::OnRefresh_Implementation(float DeltaSeconds)
{
	Super::OnRefresh_Implementation(DeltaSeconds);
}

void AWHDPlayerCharacter::LoadData(FSaveData* InSaveData, EPhase InPhase)
{
	ACharacterBase::LoadData(InSaveData, InPhase);
}

FSaveData* AWHDPlayerCharacter::ToData()
{
	return ACharacterBase::ToData();
}

bool AWHDPlayerCharacter::CanInteract(EInteractAction InInteractAction, IInteractionAgentInterface* InInteractionAgent)
{
	switch (InInteractAction)
	{
		case (EInteractAction)EWHDInteractAction::Switch:
		{
			if(Cast<AWHDPlayerCharacter>(InInteractionAgent))
			{
				return true;
			}
		}
		default: break;
	}
	return Super::CanInteract(InInteractAction, InInteractionAgent);
}

void AWHDPlayerCharacter::OnEnterInteract(IInteractionAgentInterface* InInteractionAgent)
{
	Super::OnEnterInteract(InInteractionAgent);

	if(UWidgetModuleStatics::GetUserWidget<UWHDWidgetCommonInteractionBox>())
	{
		UWidgetModuleStatics::GetUserWidget<UWHDWidgetCommonInteractionBox>()->ShowInteractActions(Cast<UObject>(InInteractionAgent), GetInteractableActions());
	}
}

void AWHDPlayerCharacter::OnLeaveInteract(IInteractionAgentInterface* InInteractionAgent)
{
	Super::OnLeaveInteract(InInteractionAgent);

	if(UWidgetModuleStatics::GetUserWidget<UWHDWidgetCommonInteractionBox>())
	{
		UWidgetModuleStatics::GetUserWidget<UWHDWidgetCommonInteractionBox>()->HideInteractActions();
	}
}

void AWHDPlayerCharacter::OnInteract(EInteractAction InInteractAction, IInteractionAgentInterface* InInteractionAgent, bool bPassivity)
{
	Super::OnInteract(InInteractAction, InInteractionAgent, bPassivity);

	if(bPassivity)
	{
		switch (InInteractAction)
		{
			case (EInteractAction)EWHDInteractAction::Switch:
			{
				UCharacterModuleStatics::SwitchCharacter(this, true);
				break;
			}
			default: break;
		}
	}
	else
	{
		if(UWidgetModuleStatics::GetUserWidget<UWHDWidgetCommonInteractionBox>())
		{
			UWidgetModuleStatics::GetUserWidget<UWHDWidgetCommonInteractionBox>()->ShowInteractActions(Cast<UObject>(InInteractionAgent), GetInteractableActions());
		}
	}
}

bool AWHDPlayerCharacter::OnGenerateVoxel(const FVoxelHitResult& InVoxelHitResult)
{
	if(!GenerateVoxelID.IsValid()) return false;
	
	FItemQueryData ItemQueryData = Inventory->QueryItemByRange(EItemQueryType::Remove, FAbilityItem(GenerateVoxelID, 1), -1);
	if(ItemQueryData.IsValid())
	{
		if(Super::OnGenerateVoxel(InVoxelHitResult))
		{
			Inventory->RemoveItemByQueryData(ItemQueryData);
			return true;
		}
	}
	return false;
}

bool AWHDPlayerCharacter::OnInteractVoxel(const FVoxelHitResult& InVoxelHitResult, EInputInteractAction InInteractAction)
{
	return Super::OnInteractVoxel(InVoxelHitResult, InInteractAction);
}
