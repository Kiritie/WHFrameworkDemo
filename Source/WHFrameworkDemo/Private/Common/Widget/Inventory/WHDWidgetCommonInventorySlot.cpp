// Fill out your copyright notice in the Description page of Project Settings.

#include "Common/Widget/Inventory/WHDWidgetCommonInventorySlot.h"

#include "Ability/Item/AbilityItemDataBase.h"
#include "Components/Image.h"
#include "Components/TextBlock.h"
#include "Ability/Inventory/Slot/AbilityInventorySlotBase.h"
#include "Blueprint/WidgetBlueprintLibrary.h"
#include "Kismet/KismetTextLibrary.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "Input/Widget/WidgetKeyTipsItemBase.h"
#include "Widget/WidgetModuleStatics.h"

UWHDWidgetCommonInventorySlot::UWHDWidgetCommonInventorySlot(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
}

void UWHDWidgetCommonInventorySlot::NativePreConstruct()
{
	Super::NativePreConstruct();

	if(ImgMask)
	{
		MaskMatInst = ImgMask->GetDynamicMaterial();
		MaskMatInst->SetVectorParameterValue(FName("Color"), FLinearColor(0.f, 0.f, 0.f, 0.3f));
		MaskMatInst->SetScalarParameterValue(FName("Progress"), 0.5f);
	}
}

void UWHDWidgetCommonInventorySlot::NativeConstruct()
{
	Super::NativeConstruct();
}

bool UWHDWidgetCommonInventorySlot::NativeOnDrop(const FGeometry& InGeometry, const FDragDropEvent& InDragDropEvent, UDragDropOperation* InOperation)
{
	return Super::NativeOnDrop(InGeometry, InDragDropEvent, InOperation);
}

void UWHDWidgetCommonInventorySlot::NativeOnDragEnter(const FGeometry& InGeometry, const FDragDropEvent& InDragDropEvent, UDragDropOperation* InOperation)
{
	Super::NativeOnDragEnter(InGeometry, InDragDropEvent, InOperation);
}

void UWHDWidgetCommonInventorySlot::NativeOnDragLeave(const FDragDropEvent& InDragDropEvent, UDragDropOperation* InOperation)
{
	Super::NativeOnDragLeave(InDragDropEvent, InOperation);
}

void UWHDWidgetCommonInventorySlot::NativeOnDragDetected(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent, UDragDropOperation*& OutOperation)
{
	Super::NativeOnDragDetected(InGeometry, InMouseEvent, OutOperation);
}

void UWHDWidgetCommonInventorySlot::NativeOnMouseEnter(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
	Super::NativeOnMouseEnter(InGeometry, InMouseEvent);
}

void UWHDWidgetCommonInventorySlot::NativeOnMouseLeave(const FPointerEvent& InMouseEvent)
{
	Super::NativeOnMouseLeave(InMouseEvent);
}

FReply UWHDWidgetCommonInventorySlot::NativeOnMouseMove(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
	return Super::NativeOnMouseMove(InGeometry, InMouseEvent);
}

FReply UWHDWidgetCommonInventorySlot::NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
	if(InMouseEvent.GetEffectingButton() == FKey("LeftMouseButton"))
	{
		if(InMouseEvent.IsLeftShiftDown())
		{
			MoveItem(-1);
			return FReply::Handled();
		}
	}
	else if(InMouseEvent.GetEffectingButton() == FKey("RightMouseButton"))
	{
		if(InMouseEvent.IsLeftShiftDown())
		{
			UseItem(-1);
		}
		else
		{
			UseItem(1);
		}
		return FReply::Handled();
	}
	else if(InMouseEvent.GetEffectingButton() == FKey("MiddleMouseButton"))
	{
		if(InMouseEvent.IsLeftShiftDown())
		{
			DiscardItem(-1);
		}
		else
		{
			DiscardItem(1);
		}
		return FReply::Handled();
	}
	return Super::NativeOnMouseButtonDown(InGeometry, InMouseEvent);
}

void UWHDWidgetCommonInventorySlot::OnCreate(UUserWidgetBase* InOwner, const TArray<FParameter>& InParams)
{
	Super::OnCreate(InOwner, InParams);
}

void UWHDWidgetCommonInventorySlot::OnInitialize(const TArray<FParameter>& InParams)
{
	Super::OnInitialize(InParams);

	if(InParams.IsValidIndex(1))
	{
		if(KeyTipsItem)
		{
			KeyTipsItem->SetKeyMappingName(InParams[1]);
		}
	}
}

void UWHDWidgetCommonInventorySlot::OnRefresh()
{
	Super::OnRefresh();

	if(!OwnerSlot) return;

	if(!IsEmpty())
	{
		const auto& ItemData = GetItem().GetData();
		ImgIcon->SetVisibility(ESlateVisibility::Visible);
		ImgIcon->SetBrushResourceObject(ItemData.Icon);
		if(TxtCount)
		{
			if(GetItem().Count > 1)
			{
				TxtCount->SetVisibility(ESlateVisibility::Visible);
				TxtCount->SetText(FText::FromString(FString::FromInt(GetItem().Count)));
			}
			else
			{
				TxtCount->SetVisibility(ESlateVisibility::Hidden);
			}
		}
	}
	else
	{
		ImgIcon->SetVisibility(ESlateVisibility::Hidden);
		if(TxtCount)
		{
			TxtCount->SetVisibility(ESlateVisibility::Hidden);
		}
	}
}

void UWHDWidgetCommonInventorySlot::OnActivated_Implementation()
{
	Super::OnActivated_Implementation();
}

void UWHDWidgetCommonInventorySlot::OnDeactived_Implementation()
{
	Super::OnDeactived_Implementation();
}

void UWHDWidgetCommonInventorySlot::StartCooldown_Implementation()
{
	Super::StartCooldown_Implementation();
}

void UWHDWidgetCommonInventorySlot::StopCooldown_Implementation()
{
	Super::StopCooldown_Implementation();

	if(ImgMask)
	{
		ImgMask->SetVisibility(ESlateVisibility::Hidden);
	}
	if(TxtCooldown)
	{
		TxtCooldown->SetVisibility(ESlateVisibility::Hidden);
	}
}

void UWHDWidgetCommonInventorySlot::OnCooldown_Implementation()
{
	if(!OwnerSlot) return;

	const FAbilityInfo AbilityInfo = OwnerSlot->GetAbilityInfo();
	if(AbilityInfo.IsCooldownning())
	{
		if(ImgMask)
		{
			ImgMask->SetVisibility(ESlateVisibility::Visible);
		}
		if(TxtCooldown)
		{
			TxtCooldown->SetVisibility(ESlateVisibility::Visible);
			TxtCooldown->SetText(UKismetTextLibrary::Conv_DoubleToText(AbilityInfo.CooldownRemaining, ERoundingMode::HalfToEven, false, true, 1, 324, 0, 1));
		}
		if(MaskMatInst)
		{
			MaskMatInst->SetScalarParameterValue(FName("Progress"), 1.f - AbilityInfo.CooldownRemaining / AbilityInfo.CooldownDuration);
		}
	}
	else
	{
		StopCooldown();
	}
}
