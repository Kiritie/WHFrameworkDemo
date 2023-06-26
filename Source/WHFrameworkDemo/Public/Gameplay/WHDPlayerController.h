// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Gameplay/WHPlayerController.h"
#include "SaveGame/Base/SaveDataInterface.h"

#include "WHDPlayerController.generated.h"

/**
 * 玩家角色控制器
 */
UCLASS()
class WHFRAMEWORKDEMO_API AWHDPlayerController : public AWHPlayerController, public ISaveDataInterface
{
	GENERATED_BODY()

	friend class ADWCharacter;
	friend class ADWPlayerCharacter;

public:
	AWHDPlayerController();

	//////////////////////////////////////////////////////////////////////////
	/// WHActor
public:
	virtual void OnInitialize_Implementation() override;

	virtual void OnPreparatory_Implementation(EPhase InPhase) override;

	virtual void OnRefresh_Implementation(float DeltaSeconds) override;

	virtual void OnTermination_Implementation() override;

protected:
	virtual void LoadData(FSaveData* InSaveData, EPhase InPhase = EPhase::Final) override;

	virtual FSaveData* ToData() override;

	virtual void UnloadData(EPhase InPhase = EPhase::Final) override;
};
