// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Input/Manager/DefaultInputManagerBase.h"

#include "WHDInputManager.generated.h"

UCLASS()
class WHFRAMEWORKDEMO_API UWHDInputManager : public UDefaultInputManagerBase
{
	GENERATED_BODY()
	
public:	
	// ParamSets default values for this actor's properties
	UWHDInputManager();
	
public:
	virtual void OnInitialize() override;

	virtual void OnBindAction(UInputComponentBase* InInputComponent) override;

protected:
	UFUNCTION()
	virtual void DoInteract1();

	UFUNCTION()
	virtual void DoInteract2();

	UFUNCTION()
	virtual void DoInteract3();

	UFUNCTION()
	virtual void DoInteract4();

	UFUNCTION()
	virtual void DoInteract5();

	UFUNCTION()
	virtual void NextInteract();

	UFUNCTION()
	virtual void SelectInventorySlot1();

	UFUNCTION()
	virtual void SelectInventorySlot2();

	UFUNCTION()
	virtual void SelectInventorySlot3();

	UFUNCTION()
	virtual void SelectInventorySlot4();

	UFUNCTION()
	virtual void SelectInventorySlot5();

	UFUNCTION()
	virtual void SelectInventorySlot6();

	UFUNCTION()
	virtual void SelectInventorySlot7();

	UFUNCTION()
	virtual void SelectInventorySlot8();

	UFUNCTION()
	virtual void SelectInventorySlot9();

	UFUNCTION()
	virtual void SelectInventorySlot10();

	UFUNCTION()
	virtual void PrevInventorySlot();

	UFUNCTION()
	virtual void NextInventorySlot();
};
