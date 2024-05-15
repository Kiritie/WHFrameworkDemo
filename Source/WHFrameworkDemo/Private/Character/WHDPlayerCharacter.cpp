// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "Character/WHDPlayerCharacter.h"

#include "Ability/Character/AbilityCharacterInventoryBase.h"
#include "Ability/Components/AbilitySystemComponentBase.h"
#include "Camera/CameraComponent.h"
#include "Character/CharacterModuleStatics.h"
#include "Common/WHDCommonTypes.h"
#include "Common/Interaction/InteractionComponent.h"
#include "Common/Widgets/WHDWidgetCommonGameHUD.h"
#include "Components/CapsuleComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "GameFramework/PawnMovementComponent.h"
#include "Voxel/VoxelModule.h"
#include "Voxel/VoxelModuleStatics.h"
#include "Voxel/Voxels/Auxiliary/VoxelInteractAuxiliary.h"
#include "Widget/WidgetModuleStatics.h"

//////////////////////////////////////////////////////////////////////////
// AWHDPlayerCharacter

AWHDPlayerCharacter::AWHDPlayerCharacter(const FObjectInitializer& ObjectInitializer) :
	Super(ObjectInitializer.SetDefaultSubobjectClass<UAbilitySystemComponentBase>("AbilitySystem").
		SetDefaultSubobjectClass<UCharacterAttributeSetBase>("AttributeSet").
		SetDefaultSubobjectClass<UAbilityCharacterInventoryBase>("Inventory"))
{
	Interaction->SetRelativeLocation(FVector(0.f, 0.f, -39.f));

	GetMesh()->SetRelativeLocation(FVector(0.f, 0.f, -70.f));

	AutoPossessAI = EAutoPossessAI::Disabled;
}

void AWHDPlayerCharacter::OnInitialize_Implementation()
{
	Super::OnInitialize_Implementation();

	if(bFloorToChunk)
	{
		GetMovementComponent()->SetActive(false);
	}
}

void AWHDPlayerCharacter::OnRefresh_Implementation(float DeltaSeconds)
{
	Super::OnRefresh_Implementation(DeltaSeconds);

	if(bFloorToChunk && GetActorLocation().Z <= 0.f && UVoxelModule::Get().IsBasicGenerated())
	{
		FHitResult HitResult;
		const FVector ChunkSize = UVoxelModuleStatics::GetWorldData().GetChunkRealSize();
		if(UVoxelModuleStatics::VoxelAgentTraceSingle(GetActorLocation(), FVector2D(ChunkSize.X, ChunkSize.Y), GetCapsuleComponent()->GetScaledCapsuleRadius(), GetCapsuleComponent()->GetScaledCapsuleHalfHeight(), {}, HitResult, false, 10, true))
		{
			SetActorLocation(HitResult.Location);
			GetMovementComponent()->SetActive(true);
			GetMovementComponent()->Velocity = FVector::ZeroVector;
		}
	}
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

	if(UWidgetModuleStatics::GetUserWidget<UWHDWidgetCommonGameHUD>())
	{
		UWidgetModuleStatics::GetUserWidget<UWHDWidgetCommonGameHUD>()->ShowInteractActions(GetInteractableActions());
	}
}

void AWHDPlayerCharacter::OnLeaveInteract(IInteractionAgentInterface* InInteractionAgent)
{
	Super::OnLeaveInteract(InInteractionAgent);

	if(UWidgetModuleStatics::GetUserWidget<UWHDWidgetCommonGameHUD>())
	{
		UWidgetModuleStatics::GetUserWidget<UWHDWidgetCommonGameHUD>()->HideInteractActions();
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
		if(UWidgetModuleStatics::GetUserWidget<UWHDWidgetCommonGameHUD>())
		{
			UWidgetModuleStatics::GetUserWidget<UWHDWidgetCommonGameHUD>()->ShowInteractActions(GetInteractableActions());
		}
	}
}

bool AWHDPlayerCharacter::OnInteractVoxel(const FVoxelHitResult& InVoxelHitResult, EInputInteractAction InInteractAction)
{
	return Super::OnInteractVoxel(InVoxelHitResult, InInteractAction);
}
