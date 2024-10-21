// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Ability/Inventory/Widget/WidgetAbilityInventoryBase.h"
#include "WHDWidgetCommonInventoryBar.generated.h"


/**
 * ��Ʒ��
 */
UCLASS()
class WHFRAMEWORKDEMO_API UWHDWidgetCommonInventoryBar : public UWidgetAbilityInventoryBase
{
	GENERATED_BODY()

public:
	UWHDWidgetCommonInventoryBar(const FObjectInitializer& ObjectInitializer);

public:
	virtual void OnInitialize(UObject* InOwner, const TArray<FParameter>& InParams) override;

	virtual void OnOpen(const TArray<FParameter>& InParams, bool bInstant) override;

	virtual void OnClose(bool bInstant) override;

	virtual void OnRefresh() override;

	UFUNCTION()
	virtual void OnInventorySlotSelected(UAbilityInventorySlotBase* InInventorySlot);

public:
	UFUNCTION(BlueprintCallable)
	void PrevInventorySlot();

	UFUNCTION(BlueprintCallable)
	void NextInventorySlot();
	
	UFUNCTION(BlueprintCallable)
	void SelectInventorySlot(int32 InSlotIndex, bool bRefreshInventory = true);

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Components", meta = (BindWidget, OptionalWidget = false))
	class UOverlay* ShortcutContent;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	int32 SelectedSlotIndex;

public:
	UFUNCTION(BlueprintPure)
	UWidgetAbilityInventorySlotBase* GetSelectedSlot() const;
	
	UFUNCTION(BlueprintPure)
	FAbilityItem GetSelectedItem() const;

	UFUNCTION(BlueprintPure)
	int32 GetSelectedSlotIndex() const { return SelectedSlotIndex; }
};
