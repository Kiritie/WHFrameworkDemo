// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "Gameplay/WHDGameMode.h"

#include "Common/CommonStatics.h"
#include "Common/Widget/WHDWidgetCommonGameHUD.h"
#include "Gameplay/WHDPlayerController.h"
#include "Gameplay/WHDGameState.h"
#include "Widget/WidgetModuleStatics.h"

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

void AWHDGameMode::OnPreparatory_Implementation()
{
	Super::OnPreparatory_Implementation();

	if(UWHDWidgetCommonGameHUD* GameHUD = UWidgetModuleStatics::CreateUserWidget<UWHDWidgetCommonGameHUD>(UCommonStatics::GetPlayerPawn()))
	{
		GameHUD->Open();
	}
}

void AWHDGameMode::OnRefresh_Implementation(float DeltaSeconds)
{
	Super::OnRefresh_Implementation(DeltaSeconds);
}

void AWHDGameMode::OnTermination_Implementation()
{
	Super::OnTermination_Implementation();
}
