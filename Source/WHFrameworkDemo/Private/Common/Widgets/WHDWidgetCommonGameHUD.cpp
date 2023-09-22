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

void UWHDWidgetCommonGameHUD::OnCreate_Implementation(UObject* InOwner)
{
	Super::OnCreate_Implementation(InOwner);

	UEventModuleBPLibrary::SubscribeEvent(UEventHandle_ChangeInputMode::StaticClass(), this, FName("OnChangeInputMode"));
}

void UWHDWidgetCommonGameHUD::OnInitialize_Implementation(UObject* InOwner)
{
	Super::OnInitialize_Implementation(InOwner);
}

void UWHDWidgetCommonGameHUD::OnOpen_Implementation(const TArray<FParameter>& InParams, bool bInstant)
{
	Super::OnOpen_Implementation(InParams, bInstant);
}

void UWHDWidgetCommonGameHUD::OnClose_Implementation(bool bInstant)
{
	Super::OnClose_Implementation(bInstant);
}

void UWHDWidgetCommonGameHUD::OnRefresh_Implementation()
{
	Super::OnRefresh_Implementation();
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
