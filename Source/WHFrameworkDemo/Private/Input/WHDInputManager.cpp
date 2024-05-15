// Fill out your copyright notice in the Description page of Project Settings.

#include "Input/WHDInputManager.h"

#include "Character/WHDPlayerCharacter.h"
#include "Common/CommonStatics.h"
#include "Common/WHDCommonTypes.h"
#include "Input/Components/InputComponentBase.h"

// ParamSets default values
UWHDInputManager::UWHDInputManager()
{
	
}

void UWHDInputManager::OnInitialize()
{
	Super::OnInitialize();
}

void UWHDInputManager::OnBindAction(UInputComponentBase* InInputComponent)
{
	Super::OnBindAction(InInputComponent);

	InInputComponent->BindInputAction(GameplayTags::InputTag_Interact1, ETriggerEvent::Started, this, &UWHDInputManager::DoInteract1);
	InInputComponent->BindInputAction(GameplayTags::InputTag_Interact2, ETriggerEvent::Started, this, &UWHDInputManager::DoInteract2);
	InInputComponent->BindInputAction(GameplayTags::InputTag_Interact3, ETriggerEvent::Started, this, &UWHDInputManager::DoInteract3);
	InInputComponent->BindInputAction(GameplayTags::InputTag_Interact4, ETriggerEvent::Started, this, &UWHDInputManager::DoInteract4);
	InInputComponent->BindInputAction(GameplayTags::InputTag_Interact5, ETriggerEvent::Started, this, &UWHDInputManager::DoInteract5);
}

void UWHDInputManager::DoInteract1()
{
	AWHDPlayerCharacter* PlayerCharacter = UCommonStatics::GetPlayerPawn<AWHDPlayerCharacter>();
	
	if(!PlayerCharacter || !PlayerCharacter->GetInteractingAgent()) return;
	
	if(PlayerCharacter->GetInteractableActions().IsValidIndex(0))
	{
		PlayerCharacter->DoInteract(PlayerCharacter->GetInteractableActions()[0]);
	}
}

void UWHDInputManager::DoInteract2()
{
	AWHDPlayerCharacter* PlayerCharacter = UCommonStatics::GetPlayerPawn<AWHDPlayerCharacter>();
	
	if(!PlayerCharacter || !PlayerCharacter->GetInteractingAgent()) return;
	
	if(PlayerCharacter->GetInteractableActions().IsValidIndex(1))
	{
		PlayerCharacter->DoInteract(PlayerCharacter->GetInteractableActions()[1]);
	}
}

void UWHDInputManager::DoInteract3()
{
	AWHDPlayerCharacter* PlayerCharacter = UCommonStatics::GetPlayerPawn<AWHDPlayerCharacter>();
	
	if(!PlayerCharacter || !PlayerCharacter->GetInteractingAgent()) return;
	
	if(PlayerCharacter->GetInteractableActions().IsValidIndex(2))
	{
		PlayerCharacter->DoInteract(PlayerCharacter->GetInteractableActions()[2]);
	}
}

void UWHDInputManager::DoInteract4()
{
	AWHDPlayerCharacter* PlayerCharacter = UCommonStatics::GetPlayerPawn<AWHDPlayerCharacter>();
	
	if(!PlayerCharacter || !PlayerCharacter->GetInteractingAgent()) return;
	
	if(PlayerCharacter->GetInteractableActions().IsValidIndex(3))
	{
		PlayerCharacter->DoInteract(PlayerCharacter->GetInteractableActions()[3]);
	}
}

void UWHDInputManager::DoInteract5()
{
	AWHDPlayerCharacter* PlayerCharacter = UCommonStatics::GetPlayerPawn<AWHDPlayerCharacter>();
	
	if(!PlayerCharacter || !PlayerCharacter->GetInteractingAgent()) return;
	
	if(PlayerCharacter->GetInteractableActions().IsValidIndex(4))
	{
		PlayerCharacter->DoInteract(PlayerCharacter->GetInteractableActions()[4]);
	}
}
