// Fill out your copyright notice in the Description page of Project Settings.

#include "Common/Widget/Interaction/WHDWidgetCommonInteractionBox.h"

#include "Ability/Item/Widget/WidgetAbilityItemBase.h"
#include "Ability/PickUp/AbilityPickUpBase.h"
#include "Input/Widget/WidgetKeyTipsItemBase.h"
#include "Voxel/Voxels/Auxiliary/VoxelInteractAuxiliary.h"
#include "Widget/WidgetModule.h"

UWHDWidgetCommonInteractionBox::UWHDWidgetCommonInteractionBox(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	WidgetName = FName("CommonInteractionBox");
	ParentName = FName("CommonGameHUD");
	ParentSlot = FName("Slot_CommonInteractionBox");
	WidgetType = EWidgetType::Permanent;
	WidgetCreateType = EWidgetCreateType::AutoCreateAndOpen;
	
	PreviewItem = nullptr;
	NextKeyTips = nullptr;
}

void UWHDWidgetCommonInteractionBox::OnCreate(UObject* InOwner, const TArray<FParameter>& InParams)
{
	Super::OnCreate(InOwner, InParams);

	NextKeyTips->VisibilityDelegate.BindDynamic(this, &UWHDWidgetCommonInteractionBox::GetNextKeyTipsVisibility);
}

void UWHDWidgetCommonInteractionBox::OnInitialize(UObject* InOwner, const TArray<FParameter>& InParams)
{
	Super::OnInitialize(InOwner, InParams);
}

void UWHDWidgetCommonInteractionBox::OnOpen(const TArray<FParameter>& InParams, bool bInstant)
{
	Super::OnOpen(InParams, bInstant);
}

void UWHDWidgetCommonInteractionBox::OnRefresh()
{
	Super::OnRefresh();
}

void UWHDWidgetCommonInteractionBox::OnClose(bool bInstant)
{
	Super::OnClose(bInstant);
}

void UWHDWidgetCommonInteractionBox::ShowInteractActions_Implementation(const TScriptInterface<IInteractionAgentInterface>& InInteractionAgent, const TArray<EInteractAction>& InActions)
{
	if(!InInteractionAgent || InActions.IsEmpty()) return;

	InteractionAgent = InInteractionAgent;

	FAbilityItem Item;
	
	if(AAbilityPickUpBase* PickUp = Cast<AAbilityPickUpBase>(InteractionAgent.GetObject()))
	{
		Item = PickUp->GetItem();
	}
	else if(AVoxelInteractAuxiliary* Auxiliary = Cast<AVoxelInteractAuxiliary>(InteractionAgent.GetObject()))
	{
		Item = FAbilityItem(Auxiliary->GetVoxelItem());
	}
	else if(IPrimaryEntityInterface* Entity = Cast<IPrimaryEntityInterface>(InteractionAgent.GetObject()))
	{
		Item = FAbilityItem(Entity->Execute_GetAssetID(InteractionAgent.GetObject()));
	}
	
	if(Item.IsValid() && InInteractionAgent.GetObject() != GetOwnerObject())
	{
		PreviewItem->Init({ &Item });
		PreviewItem->SetVisibility(ESlateVisibility::SelfHitTestInvisible);
	}
}

void UWHDWidgetCommonInteractionBox::HideInteractActions_Implementation()
{
	InteractionAgent = nullptr;

	PreviewItem->SetVisibility(ESlateVisibility::Collapsed);
}

ESlateVisibility UWHDWidgetCommonInteractionBox::GetNextKeyTipsVisibility()
{
	if(IInteractionAgentInterface* OwnerInteractionAgent = GetOwnerObject<IInteractionAgentInterface>())
	{
		if(InteractionAgent && OwnerInteractionAgent->GetOverlappingAgents().Num() > 1)
		{
			return ESlateVisibility::SelfHitTestInvisible;
		}
	}
	return ESlateVisibility::Collapsed;
}
