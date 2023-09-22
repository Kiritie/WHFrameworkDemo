// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "Character/WHDPlayerCharacter.h"

#include "Ability/Character/AbilityCharacterInventoryBase.h"
#include "Ability/Components/AbilitySystemComponentBase.h"
#include "Camera/CameraComponent.h"
#include "Character/CharacterModuleBPLibrary.h"
#include "Common/CommonBPLibrary.h"
#include "Common/WHDCommonTypes.h"
#include "Common/Interaction/InteractionComponent.h"
#include "Common/Widgets/WHDWidgetCommonGameHUD.h"
#include "Components/CapsuleComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "GameFramework/PawnMovementComponent.h"
#include "Voxel/VoxelModule.h"
#include "Voxel/VoxelModuleBPLibrary.h"
#include "Voxel/Voxels/Auxiliary/VoxelInteractAuxiliary.h"
#include "Widget/WidgetModuleBPLibrary.h"

//////////////////////////////////////////////////////////////////////////
// AWHDPlayerCharacter

AWHDPlayerCharacter::AWHDPlayerCharacter()
{
	AbilitySystem = CreateDefaultSubobject<UAbilitySystemComponentBase>(FName("AbilitySystem"));

	AttributeSet = CreateDefaultSubobject<UCharacterAttributeSetBase>(FName("AttributeSet"));

	Inventory = CreateDefaultSubobject<UAbilityCharacterInventoryBase>(FName("Inventory"));

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

	if(bFloorToChunk && GetActorLocation().Z <= 0.f && AVoxelModule::Get()->IsBasicGenerated())
	{
		FHitResult HitResult;
		const FVector ChunkSize = UVoxelModuleBPLibrary::GetWorldData().GetChunkRealSize();
		if(UVoxelModuleBPLibrary::VoxelAgentTraceSingle(GetActorLocation(), FVector2D(ChunkSize.X, ChunkSize.Y), GetCapsuleComponent()->GetScaledCapsuleRadius(), GetCapsuleComponent()->GetScaledCapsuleHalfHeight(), {}, HitResult, false, 10, true))
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
		case EWHDInteractAction::Switch:
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

	if(UCommonBPLibrary::GetPlayerPawn() == this)
	{
		if(UWidgetModuleBPLibrary::GetUserWidget<UWHDWidgetCommonGameHUD>())
		{
			UWidgetModuleBPLibrary::GetUserWidget<UWHDWidgetCommonGameHUD>()->ShowInteractActions(GetInteractableActions(InInteractionAgent));
		}
	}
}

void AWHDPlayerCharacter::OnLeaveInteract(IInteractionAgentInterface* InInteractionAgent)
{
	Super::OnLeaveInteract(InInteractionAgent);

	if(UCommonBPLibrary::GetPlayerPawn() == this)
	{
		if(GetInteractingAgent() == InInteractionAgent && UWidgetModuleBPLibrary::GetUserWidget<UWHDWidgetCommonGameHUD>())
		{
			UWidgetModuleBPLibrary::GetUserWidget<UWHDWidgetCommonGameHUD>()->HideInteractActions();
		}
	}
}

void AWHDPlayerCharacter::OnInteract(EInteractAction InInteractAction, IInteractionAgentInterface* InInteractionAgent, bool bPassivity)
{
	Super::OnInteract(InInteractAction, InInteractionAgent, bPassivity);

	if(bPassivity)
	{
		switch (InInteractAction)
		{
			case EWHDInteractAction::Switch:
			{
				UCharacterModuleBPLibrary::SwitchCharacter(this, true);
				break;
			}
			default: break;
		}
	}
	else
	{
		if(UWidgetModuleBPLibrary::GetUserWidget<UWHDWidgetCommonGameHUD>())
		{
			UWidgetModuleBPLibrary::GetUserWidget<UWHDWidgetCommonGameHUD>()->ShowInteractActions(GetInteractableActions(InInteractionAgent));
		}
	}
}

bool AWHDPlayerCharacter::OnInteractVoxel(const FVoxelHitResult& InVoxelHitResult, EInputInteractAction InInteractAction)
{
	if(UCommonBPLibrary::GetPlayerPawn() == this)
	{
		switch(InInteractAction)
		{
			case EInputInteractAction::Action2:
			{
				if(AVoxelInteractAuxiliary* InteractionAgent = Cast<AVoxelInteractAuxiliary>(InVoxelHitResult.VoxelItem.Auxiliary))
				{
					if(UWidgetModuleBPLibrary::GetUserWidget<UWHDWidgetCommonGameHUD>())
					{
						UWidgetModuleBPLibrary::GetUserWidget<UWHDWidgetCommonGameHUD>()->ShowInteractActions(GetInteractableActions(InteractionAgent));
					}
				}
				break;
			}
			default: break;
		}
	}
	return Super::OnInteractVoxel(InVoxelHitResult, InInteractAction);
}
