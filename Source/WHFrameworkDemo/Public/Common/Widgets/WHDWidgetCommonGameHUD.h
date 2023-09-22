// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Ability/AbilityModuleTypes.h"
#include "Widget/Screen/UMG/UserWidgetBase.h"
#include "WHDWidgetCommonGameHUD.generated.h"

class AWHDPlayerCharacter;

/**
 * 游戏主界面
 */
UCLASS()
class WHFRAMEWORKDEMO_API UWHDWidgetCommonGameHUD : public UUserWidgetBase
{
	GENERATED_BODY()

public:
	UWHDWidgetCommonGameHUD(const FObjectInitializer& ObjectInitializer);

public:
	virtual void OnCreate_Implementation(UObject* InOwner) override;

	virtual void OnInitialize_Implementation(UObject* InOwner) override;

	virtual void OnOpen_Implementation(const TArray<FParameter>& InParams, bool bInstant) override;

	virtual void OnRefresh_Implementation() override;

	virtual void OnClose_Implementation(bool bInstant) override;
	
	virtual FReply NativeOnKeyDown(const FGeometry& InGeometry, const FKeyEvent& InKeyEvent) override;

public:
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	void SetCrosshairVisible(bool bValue);

	UFUNCTION(BlueprintImplementableEvent)
	void ShowInteractActions(const TArray<EInteractAction>& InActions);
		
	UFUNCTION(BlueprintImplementableEvent)
	void HideInteractActions();

protected:
	UFUNCTION()
	void OnChangeInputMode(UObject* InSender, class UEventHandle_ChangeInputMode* InEventHandle);
};
