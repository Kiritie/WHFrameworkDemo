// Fill out your copyright notice in the Description page of Project Settings.


#include "Common/Widgets/WHDWidgetCommonGameHUD.h"

#include "Character/WHDPlayerCharacter.h"
#include "Event/EventModuleBPLibrary.h"
#include "Event/Handle/Input/EventHandle_ChangeInputMode.h"
#include "Widget/WidgetModule.h"


UWHDWidgetCommonGameHUD::UWHDWidgetCommonGameHUD(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	WidgetName = FName("GameHUD");
	WidgetType = EWidgetType::Permanent;
	WidgetInputMode = EInputMode::GameOnly;

	WidgetRefreshType = EWidgetRefreshType::Tick;

	SetIsFocusable(true);
}

void UWHDWidgetCommonGameHUD::OnCreate(UObject* InOwner)
{
	Super::OnCreate(InOwner);

	UEventModuleBPLibrary::SubscribeEvent(UEventHandle_ChangeInputMode::StaticClass(), this, FName("OnChangeInputMode"));
}

void UWHDWidgetCommonGameHUD::OnInitialize(UObject* InOwner)
{
	Super::OnInitialize(InOwner);
}

void UWHDWidgetCommonGameHUD::OnOpen(const TArray<FParameter>& InParams, bool bInstant)
{
	Super::OnOpen(InParams, bInstant);
}

void UWHDWidgetCommonGameHUD::OnClose(bool bInstant)
{
	Super::OnClose(bInstant);
}

void UWHDWidgetCommonGameHUD::OnRefresh()
{
	Super::OnRefresh();
}

FReply UWHDWidgetCommonGameHUD::NativeOnKeyDown(const FGeometry& InGeometry, const FKeyEvent& InKeyEvent)
{
	if(InKeyEvent.GetKey() == FKey("Escape"))
	{
		if(TemporaryChild)
		{
			TemporaryChild->Close();
			return FReply::Handled();
		}
	}
	return FReply::Unhandled();
}

void UWHDWidgetCommonGameHUD::OnChangeInputMode(UObject* InSender, UEventHandle_ChangeInputMode* InEventHandle)
{
	if(AWHDPlayerCharacter* OwnerCharacter = Cast<AWHDPlayerCharacter>(OwnerObject))
	{
		if(!OwnerCharacter->IsDead() && InEventHandle->InputMode == EInputMode::GameOnly)
		{
			SetCrosshairVisible(true);
		}
		else
		{
			SetCrosshairVisible(false);
		}
	}
	else
	{
		SetCrosshairVisible(true);
	}
}
