// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.ADWCharacter

#pragma once

#include "Character/Base/CharacterBase.h"
#include "Gameplay/WHPlayerInterface.h"
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
class WHFRAMEWORKDEMO_API AWHDPlayerCharacter : public ACharacterBase
{
	GENERATED_BODY()

public:
	AWHDPlayerCharacter();

public:
	virtual void OnInitialize_Implementation() override;

	virtual void OnRefresh_Implementation(float DeltaSeconds) override;

protected:
	virtual void OnSpawn_Implementation(const TArray<FParameter>& InParams) override;

	virtual void OnDespawn_Implementation(bool bRecovery) override;
	
protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CharacterStats")
	bool bFloorToChunk;
};
