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

public:
	virtual FEventReply OnWidgetInputKeyDown_Implementation(const FGeometry& InGeometry, const FKeyEvent& InKeyEvent) override;

	virtual FEventReply OnWidgetInputKeyUp_Implementation(const FGeometry& InGeometry, const FKeyEvent& InKeyEvent) override;

protected:
	UFUNCTION()
	virtual void OnJumpPressed(FKey Key);

	UFUNCTION()
	virtual void OnJumpReleased();

	UFUNCTION()
	virtual void OnPrimaryPressed();

	UFUNCTION()
	virtual void OnPrimaryReleased();

	UFUNCTION()
	virtual void OnMinorPressed();

	UFUNCTION()
	virtual void OnMinorReleased();

	UFUNCTION()
	virtual void PrevInventorySlot();

	UFUNCTION()
	virtual void NextInventorySlot();
	
protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "InputStats")
	EVoxelRaycastType VoxelRaycastType;
};
