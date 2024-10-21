// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WHDInputManager.h"
#include "Voxel/VoxelModuleTypes.h"

#include "WHDVoxelInputManager.generated.h"

UCLASS()
class WHFRAMEWORKDEMO_API UWHDVoxelInputManager : public UWHDInputManager
{
	GENERATED_BODY()
	
public:	
	// ParamSets default values for this actor's properties
	UWHDVoxelInputManager();
	
public:
	virtual void OnInitialize() override;

	virtual void OnBindAction(UInputComponentBase* InInputComponent) override;

protected:
	UFUNCTION()
	virtual void OnPrimaryPressed();

	UFUNCTION()
	virtual void OnPrimaryReleased();

	UFUNCTION()
	virtual void OnSecondaryPressed();

	UFUNCTION()
	virtual void OnSecondaryReleased();

	UFUNCTION()
	virtual void PrevInventorySlot();

	UFUNCTION()
	virtual void NextInventorySlot();
	
protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "InputStats")
	EVoxelRaycastType VoxelRaycastType;
};
