// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Gameplay/WHGameState.h"
#include "WHDGameState.generated.h"

/**
 * 
 */
UCLASS()
class WHFRAMEWORKDEMO_API AWHDGameState : public AWHGameState
{
	GENERATED_BODY()

public:
	AWHDGameState();

	//////////////////////////////////////////////////////////////////////////
	/// WHActor
public:
	virtual void OnInitialize_Implementation() override;

	virtual void OnPreparatory_Implementation(EPhase InPhase) override;

	virtual void OnRefresh_Implementation(float DeltaSeconds) override;

	virtual void OnTermination_Implementation(EPhase InPhase) override;
};
