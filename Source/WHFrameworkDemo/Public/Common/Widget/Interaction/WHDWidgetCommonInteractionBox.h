// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Widget/Screen/UserWidgetBase.h"
#include "WHDWidgetCommonInteractionBox.generated.h"

class IInteractionAgentInterface;
/**
 * 交互框
 */
UCLASS()
class WHFRAMEWORKDEMO_API UWHDWidgetCommonInteractionBox : public UUserWidgetBase
{
	GENERATED_BODY()

public:
	UWHDWidgetCommonInteractionBox(const FObjectInitializer& ObjectInitializer);

public:
	virtual void OnCreate(UObject* InOwner, const TArray<FParameter>& InParams) override;

	virtual void OnInitialize(UObject* InOwner, const TArray<FParameter>& InParams) override;

	virtual void OnOpen(const TArray<FParameter>& InParams, bool bInstant) override;

	virtual void OnRefresh() override;

	virtual void OnClose(bool bInstant) override;

public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void ShowInteractActions(const TScriptInterface<IInteractionAgentInterface>& InInteractionAgent, const TArray<EInteractAction>& InActions);
	
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void HideInteractActions();

protected:
	UFUNCTION()
	ESlateVisibility GetNextKeyTipsVisibility();

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Components", meta = (BindWidget, OptionalWidget = false))
	class UWidgetAbilityItemBase* PreviewItem;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Components", meta = (BindWidget, OptionalWidget = false))
	class UWidgetKeyTipsItemBase* NextKeyTips;

private:
	TScriptInterface<IInteractionAgentInterface> InteractionAgent;
};
