// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "Gameplay/WHDGameState.h"
#include "SaveGame/SaveGameModuleBPLibrary.h"

AWHDGameState::AWHDGameState()
{
	// set default pawn class to our Blueprinted character
	
}

void AWHDGameState::OnInitialize_Implementation()
{
	Super::OnInitialize_Implementation();
}

void AWHDGameState::OnPreparatory_Implementation(EPhase InPhase)
{
	Super::OnPreparatory_Implementation(InPhase);
}

void AWHDGameState::OnRefresh_Implementation(float DeltaSeconds)
{
	Super::OnRefresh_Implementation(DeltaSeconds);
}

void AWHDGameState::OnTermination_Implementation(EPhase InPhase)
{
	Super::OnTermination_Implementation(InPhase);
}
