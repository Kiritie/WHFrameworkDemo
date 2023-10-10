// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.ADWCharacter

#pragma once

#include "Ability/Character/AbilityCharacterBase.h"
#include "WHDPlayerCharacter.generated.h"

class UVoxel;
class UInputComponent;
class USpringArmComponent;
class UCameraComponent;
class USkeletalMeshComponent;

/**
 * ��ҽ�ɫ
 */
UCLASS()
class WHFRAMEWORKDEMO_API AWHDPlayerCharacter : public AAbilityCharacterBase
{
	GENERATED_UCLASS_BODY()

public:
	virtual void OnInitialize_Implementation() override;

	virtual void OnRefresh_Implementation(float DeltaSeconds) override;

protected:
	virtual bool CanInteract(EInteractAction InInteractAction, IInteractionAgentInterface* InInteractionAgent) override;

	virtual void OnEnterInteract(IInteractionAgentInterface* InInteractionAgent) override;

	virtual void OnLeaveInteract(IInteractionAgentInterface* InInteractionAgent) override;
	
	virtual void OnInteract(EInteractAction InInteractAction, IInteractionAgentInterface* InInteractionAgent, bool bPassivity) override;

	virtual bool OnInteractVoxel(const FVoxelHitResult& InVoxelHitResult, EInputInteractAction InInteractAction) override;

protected:
	UPROPERTY(EditAnywhere, Category = "CharacterStats")
	bool bFloorToChunk;
};
