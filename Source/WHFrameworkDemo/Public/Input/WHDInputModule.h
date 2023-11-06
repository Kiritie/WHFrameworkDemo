// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Input/InputModule.h"
#include "Voxel/VoxelModuleTypes.h"

#include "WHDInputModule.generated.h"

UCLASS()
class WHFRAMEWORKDEMO_API AWHDInputModule : public AInputModule
{
	GENERATED_BODY()
	
	GENERATED_MODULE(AWHDInputModule)

public:	
	// ParamSets default values for this actor's properties
	AWHDInputModule();
	
	//////////////////////////////////////////////////////////////////////////
	/// Module
public:
#if WITH_EDITOR
	virtual void OnGenerate() override;

	virtual void OnDestroy() override;
#endif

	virtual void OnInitialize_Implementation() override;

	virtual void OnPreparatory_Implementation(EPhase InPhase) override;

	virtual void OnRefresh_Implementation(float DeltaSeconds) override;

	virtual void OnPause_Implementation() override;

	virtual void OnUnPause_Implementation() override;

protected:
	virtual void OnBindAction_Implementation(UInputComponentBase* InInputComponent, UPlayerMappableInputConfig* InInputConfig) override;

protected:
	UFUNCTION()
	virtual void OnJumpPressed();

	UFUNCTION()
	virtual void OnJumpReleased();

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
