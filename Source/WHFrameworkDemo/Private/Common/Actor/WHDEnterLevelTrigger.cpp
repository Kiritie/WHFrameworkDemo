
// Fill out your copyright notice in the Description page of Project Settings.

#include "Common/Actor/WHDEnterLevelTrigger.h"

#include "Camera/CameraModuleStatics.h"
#include "Character/WHDPlayerCharacter.h"
#include "Common/WHDCommonTypes.h"
#include "Common/Interaction/InteractionComponent.h"
#include "Components/TextRenderComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AWHDEnterLevelTrigger::AWHDEnterLevelTrigger()
{
	PrimaryActorTick.bCanEverTick = true;
	
	Interaction = CreateDefaultSubobject<UInteractionComponent>(FName("Interaction"));
	Interaction->SetupAttachment(RootComponent);
	Interaction->AddInteractAction((EInteractAction)EWHDInteractAction::Enter);

	Text = CreateDefaultSubobject<UTextRenderComponent>(FName("Text"));
	Text->SetupAttachment(RootComponent);
	Text->SetRelativeLocation(FVector(0.f, 0.f, 100.f));
	Text->SetRelativeScale3D(FVector(-1.f, -1.f, 1.f));

	static ConstructorHelpers::FObjectFinder<UMaterialInterface> TextMatFinder(TEXT("/Script/Engine.MaterialInstanceConstant'/WHFramework/Common/Materials/M_DefaultText_Unlit.M_DefaultText_Unlit'"));
	if(TextMatFinder.Succeeded())
	{
		Text->SetMaterial(0, TextMatFinder.Object);
	}

	Text->WorldSize = 100.f;
	Text->HorizontalAlignment = EHTA_Center;
	Text->VerticalAlignment = EVRTA_TextCenter;
}

void AWHDEnterLevelTrigger::OnRefresh_Implementation(float DeltaSeconds)
{
	Super::OnRefresh_Implementation(DeltaSeconds);

	const FRotator TargetRotation = UCameraModuleStatics::GetCameraRotation(true);
	Text->SetWorldRotation(FRotator(0.f, TargetRotation.Yaw, 0.f));
}

bool AWHDEnterLevelTrigger::CanInteract(EInteractAction InInteractAction, IInteractionAgentInterface* InInteractionAgent)
{
	switch (InInteractAction)
	{
		case (EInteractAction)EWHDInteractAction::Enter:
		{
			if(Cast<AWHDPlayerCharacter>(InInteractionAgent))
			{
				return true;
			}
		}
		default: break;
	}
	return false;
}

void AWHDEnterLevelTrigger::OnEnterInteract(IInteractionAgentInterface* InInteractionAgent)
{
}

void AWHDEnterLevelTrigger::OnLeaveInteract(IInteractionAgentInterface* InInteractionAgent)
{
}

void AWHDEnterLevelTrigger::OnInteract(EInteractAction InInteractAction, IInteractionAgentInterface* InInteractionAgent, bool bPassivity)
{
	if(!bPassivity) return;
	
	switch (InInteractAction)
	{
		case (EInteractAction)EWHDInteractAction::Enter:
		{
			if(!Level.IsNull())
			{
				UGameplayStatics::OpenLevelBySoftObjectPtr(this, Level);
			}
			break;
		}
		default: break;
	}
}

UInteractionComponent* AWHDEnterLevelTrigger::GetInteractionComponent() const
{
	return Interaction;
}