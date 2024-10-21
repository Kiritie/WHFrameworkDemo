// Fill out your copyright notice in the Description page of Project Settings.

#include "Common/Widget/Inventory/WHDWidgetCommonInventoryBar.h"

#include "Ability/Inventory/AbilityInventoryBase.h"
#include "Ability/Inventory/Slot/AbilityInventorySlotBase.h"
#include "Ability/Inventory/Widget/WidgetAbilityInventorySlotBase.h"
#include "Components/Overlay.h"
#include "Components/OverlaySlot.h"

UWHDWidgetCommonInventoryBar::UWHDWidgetCommonInventoryBar(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	WidgetName = FName("CommonInventoryBar");
	ParentName = FName("CommonGameHUD");
	ParentSlot = FName("Slot_CommonInventoryBar");
	
	WidgetCreateType = EWidgetCreateType::AutoCreateAndOpen;

	WidgetZOrder = 2;

	SelectedSlotIndex = 0;

	UISlotDatas.Add(ESlotSplitType::Shortcut);

	SetIsFocusable(true);
}

void UWHDWidgetCommonInventoryBar::OnInitialize(UObject* InOwner, const TArray<FParameter>& InParams)
{
	if(GetInventory())
	{
		GetInventory()->OnSlotSelected.RemoveDynamic(this, &UWHDWidgetCommonInventoryBar::OnInventorySlotSelected);
	}

	Super::OnInitialize(InOwner, InParams);

	if(!InOwner) return;
	
	if(ShortcutContent && UISlotDatas.Contains(ESlotSplitType::Shortcut))
	{
		const auto ShortcutSlots = GetInventory()->GetSlotsBySplitType(ESlotSplitType::Shortcut);
		if(UISlotDatas[ESlotSplitType::Shortcut].Slots.Num() != ShortcutSlots.Num())
		{
			ShortcutContent->ClearChildren();
			UISlotDatas[ESlotSplitType::Shortcut].Slots.Empty();
			for(int32 i = 0; i < ShortcutSlots.Num(); i++)
			{
				if(UWidgetAbilityInventorySlotBase* ShortcutSlot = CreateSubWidget<UWidgetAbilityInventorySlotBase>({ ShortcutSlots[i], FString::Printf(TEXT("SelectInventorySlot%d"), i + 1) }, UISlotDatas[ESlotSplitType::Shortcut].Class))
				{
					ShortcutSlot->SetVisibility(ESlateVisibility::Collapsed);
					if(UOverlaySlot* OverlaySlot = ShortcutContent->AddChildToOverlay(ShortcutSlot))
					{
						// OverlaySlot->SetPadding(FMargin(0.f, 0.f, 5.f, 0.f));
					}
					UISlotDatas[ESlotSplitType::Shortcut].Slots.Add(ShortcutSlot);
				}
			}
		}
		else
		{
			for(int32 i = 0; i < UISlotDatas[ESlotSplitType::Shortcut].Slots.Num(); i++)
			{
				UISlotDatas[ESlotSplitType::Shortcut].Slots[i]->OnInitialize({ ShortcutSlots[i], FString::Printf(TEXT("SelectInventorySlot%d"), i + 1) });
			}
		}
	}

	GetInventory()->OnSlotSelected.AddDynamic(this, &UWHDWidgetCommonInventoryBar::OnInventorySlotSelected);

	if(UAbilityInventorySlotBase* SelectedSlot = GetInventory()->GetSelectedSlot(ESlotSplitType::Shortcut))
	{
		SelectInventorySlot(SelectedSlot->GetSlotIndex(), false);
	}
	else
	{
		SelectInventorySlot(0);
	}
}

void UWHDWidgetCommonInventoryBar::OnOpen(const TArray<FParameter>& InParams, bool bInstant)
{
	Super::OnOpen(InParams, bInstant);
}

void UWHDWidgetCommonInventoryBar::OnClose(bool bInstant)
{
	Super::OnClose(bInstant);
}

void UWHDWidgetCommonInventoryBar::OnRefresh()
{
	Super::OnRefresh();
}

void UWHDWidgetCommonInventoryBar::OnInventorySlotSelected(UAbilityInventorySlotBase* InInventorySlot)
{
	if(InInventorySlot)
	{
		SelectInventorySlot(InInventorySlot->GetSlotIndex(), false);
	}
}

void UWHDWidgetCommonInventoryBar::PrevInventorySlot()
{
	auto SplitUISlots = GetSplitUISlots(ESlotSplitType::Shortcut);
	if(SelectedSlotIndex > 0)
	{
		SelectInventorySlot(SelectedSlotIndex - 1);
	}
	else
	{
		SelectInventorySlot(SplitUISlots.Num() - 1);
	}
}

void UWHDWidgetCommonInventoryBar::NextInventorySlot()
{
	auto SplitUISlots = GetSplitUISlots(ESlotSplitType::Shortcut);
	if (SelectedSlotIndex < SplitUISlots.Num() - 1)
	{
		SelectInventorySlot(SelectedSlotIndex + 1);
	}
	else
	{
		SelectInventorySlot(0);
	}
}

void UWHDWidgetCommonInventoryBar::SelectInventorySlot(int32 InSlotIndex, bool bRefreshInventory)
{
	if(UWidgetAbilityInventorySlotBase* SelectedSlot = GetSelectedSlot())
	{
		SelectedSlot->SetVisibility(ESlateVisibility::Collapsed);
	}
	SelectedSlotIndex = InSlotIndex;
	if(UWidgetAbilityInventorySlotBase* SelectedSlot = GetSelectedSlot())
	{
		if(bRefreshInventory)
		{
			GetInventory()->SetSelectedSlot(ESlotSplitType::Shortcut, SelectedSlot->GetOwnerSlot());
		}
		SelectedSlot->SetVisibility(ESlateVisibility::HitTestInvisible);
	}
}

UWidgetAbilityInventorySlotBase* UWHDWidgetCommonInventoryBar::GetSelectedSlot() const
{
	auto SplitUISlots = GetSplitUISlots(ESlotSplitType::Shortcut);
	if(SplitUISlots.IsValidIndex(SelectedSlotIndex))
	{
		return SplitUISlots[SelectedSlotIndex];
	}
	return nullptr;
}

FAbilityItem UWHDWidgetCommonInventoryBar::GetSelectedItem() const
{
	if (GetSelectedSlot())
	{
		return GetSelectedSlot()->GetItem();
	}
	return FAbilityItem::Empty;
}
