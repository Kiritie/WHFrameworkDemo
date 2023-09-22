// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "Gameplay/WHDGameMode.h"
#include "Gameplay/WHDPlayerController.h"
#include "Gameplay/WHDGameState.h"
#include "Kismet/GameplayStatics.h"
#include "SaveGame/SaveGameModuleBPLibrary.h"

AWHDGameMode::AWHDGameMode()
{
	// set default pawn class to our Blueprinted character
	DefaultPawnClass = APawn::StaticClass();
	PlayerControllerClass = AWHDPlayerController::StaticClass();
	GameStateClass = AWHDGameState::StaticClass();
}

void AWHDGameMode::OnInitialize_Implementation()
{
	Super::OnInitialize_Implementation();
}

void AWHDGameMode::OnPreparatory_Implementation(EPhase InPhase)
{
	Super::OnPreparatory_Implementation(InPhase);
}

void AWHDGameMode::OnRefresh_Implementation(float DeltaSeconds)
{
	Super::OnRefresh_Implementation(DeltaSeconds);
}

void AWHDGameMode::OnTermination_Implementation(EPhase InPhase)
{
	Super::OnTermination_Implementation(InPhase);
}
