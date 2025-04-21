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
	virtual void OnPrimaryPressed_Implementation() override;

	virtual void OnPrimaryRepeated_Implementation() override;

	virtual void OnPrimaryReleased_Implementation() override;

	virtual void OnSecondaryPressed_Implementation() override;

	virtual void OnSecondaryRepeated_Implementation() override;

	virtual void OnSecondaryReleased_Implementation() override;
	
protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EVoxelRaycastType VoxelRaycastType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float InteractDistance;
};
