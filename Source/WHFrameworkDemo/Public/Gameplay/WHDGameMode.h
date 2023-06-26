// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Gameplay/WHGameMode.h"
#include "WHDGameMode.generated.h"

/**
 * 游戏模式基类
 */
UCLASS()
class WHFRAMEWORKDEMO_API AWHDGameMode : public AWHGameMode
{
	GENERATED_BODY()

public:
	AWHDGameMode();
	
	//////////////////////////////////////////////////////////////////////////
	/// WHActor
public:
	virtual void OnInitialize_Implementation() override;

	virtual void OnPreparatory_Implementation(EPhase InPhase) override;

	virtual void OnRefresh_Implementation(float DeltaSeconds) override;

	virtual void OnTermination_Implementation() override;

protected:
	virtual bool IsDefaultLifecycle_Implementation() const override { return true; }
};
