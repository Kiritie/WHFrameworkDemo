// Fill out your copyright notice in the Description page of Project Settings.


#include "Gameplay/WHDPlayerController.h"

#include "SaveGame/SaveGameModuleStatics.h"

AWHDPlayerController::AWHDPlayerController()
{
}

void AWHDPlayerController::OnInitialize_Implementation()
{
	Super::OnInitialize_Implementation();
}

void AWHDPlayerController::OnPreparatory_Implementation(EPhase InPhase)
{
	Super::OnPreparatory_Implementation(InPhase);
}

void AWHDPlayerController::OnRefresh_Implementation(float DeltaSeconds)
{
	Super::OnRefresh_Implementation(DeltaSeconds);
}

void AWHDPlayerController::OnTermination_Implementation(EPhase InPhase)
{
	Super::OnTermination_Implementation(InPhase);
}
