// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Input/Manager/DefaultInputManagerBase.h"
#include "Voxel/VoxelModuleTypes.h"

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
	virtual void OnAction1Pressed();

	UFUNCTION()
	virtual void OnAction1Released();

	UFUNCTION()
	virtual void OnAction2Pressed();

	UFUNCTION()
	virtual void OnAction2Released();

	UFUNCTION()
	virtual void DoInteractAction1();

	UFUNCTION()
	virtual void DoInteractAction2();

	UFUNCTION()
	virtual void DoInteractAction3();

	UFUNCTION()
	virtual void DoInteractAction4();

	UFUNCTION()
	virtual void DoInteractAction5();

	UFUNCTION()
	virtual void PrevInventorySlot();

	UFUNCTION()
	virtual void NextInventorySlot();
	
protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "InputStats")
	EVoxelRaycastType VoxelRaycastType;
};
