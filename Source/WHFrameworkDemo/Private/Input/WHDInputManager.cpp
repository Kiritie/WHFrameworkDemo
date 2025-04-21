// Fill out your copyright notice in the Description page of Project Settings.

#include "Input/WHDInputManager.h"

#include "Character/WHDPlayerCharacter.h"
#include "Common/CommonStatics.h"
#include "Common/WHDCommonTypes.h"
#include "Common/Widget/Inventory/WHDWidgetCommonInventoryBar.h"
#include "Input/Components/InputComponentBase.h"
#include "Widget/WidgetModuleStatics.h"

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

	InInputComponent->BindInputAction(GameplayTags::Input_Interact1, ETriggerEvent::Started, this, &UWHDInputManager::DoInteract1);
	InInputComponent->BindInputAction(GameplayTags::Input_Interact2, ETriggerEvent::Started, this, &UWHDInputManager::DoInteract2);
	InInputComponent->BindInputAction(GameplayTags::Input_Interact3, ETriggerEvent::Started, this, &UWHDInputManager::DoInteract3);
	InInputComponent->BindInputAction(GameplayTags::Input_Interact4, ETriggerEvent::Started, this, &UWHDInputManager::DoInteract4);
	InInputComponent->BindInputAction(GameplayTags::Input_Interact5, ETriggerEvent::Started, this, &UWHDInputManager::DoInteract5);
	InInputComponent->BindInputAction(GameplayTags::Input_NextInteract, ETriggerEvent::Started, this, &UWHDInputManager::NextInteract);

	InInputComponent->BindInputAction(GameplayTags::Input_SelectInventorySlot1, ETriggerEvent::Started, this, &UWHDInputManager::SelectInventorySlot1);
	InInputComponent->BindInputAction(GameplayTags::Input_SelectInventorySlot2, ETriggerEvent::Started, this, &UWHDInputManager::SelectInventorySlot2);
	InInputComponent->BindInputAction(GameplayTags::Input_SelectInventorySlot3, ETriggerEvent::Started, this, &UWHDInputManager::SelectInventorySlot3);
	InInputComponent->BindInputAction(GameplayTags::Input_SelectInventorySlot4, ETriggerEvent::Started, this, &UWHDInputManager::SelectInventorySlot4);
	InInputComponent->BindInputAction(GameplayTags::Input_SelectInventorySlot5, ETriggerEvent::Started, this, &UWHDInputManager::SelectInventorySlot5);
	InInputComponent->BindInputAction(GameplayTags::Input_SelectInventorySlot6, ETriggerEvent::Started, this, &UWHDInputManager::SelectInventorySlot6);
	InInputComponent->BindInputAction(GameplayTags::Input_SelectInventorySlot7, ETriggerEvent::Started, this, &UWHDInputManager::SelectInventorySlot7);
	InInputComponent->BindInputAction(GameplayTags::Input_SelectInventorySlot8, ETriggerEvent::Started, this, &UWHDInputManager::SelectInventorySlot8);
	InInputComponent->BindInputAction(GameplayTags::Input_SelectInventorySlot9, ETriggerEvent::Started, this, &UWHDInputManager::SelectInventorySlot9);
	InInputComponent->BindInputAction(GameplayTags::Input_SelectInventorySlot10, ETriggerEvent::Started, this, &UWHDInputManager::SelectInventorySlot10);

	InInputComponent->BindInputAction(GameplayTags::Input_PrevInventorySlot, ETriggerEvent::Started, this, &UWHDInputManager::PrevInventorySlot);
	InInputComponent->BindInputAction(GameplayTags::Input_NextInventorySlot, ETriggerEvent::Started, this, &UWHDInputManager::NextInventorySlot);
}

void UWHDInputManager::DoInteract1()
{
	AWHDPlayerCharacter* PlayerCharacter = UCommonStatics::GetPlayerPawn<AWHDPlayerCharacter>();
	
	if(!PlayerCharacter || PlayerCharacter->Execute_IsBlockAllInput(PlayerCharacter)) return;
	
	if(PlayerCharacter->GetInteractableActions().IsValidIndex(0))
	{
		PlayerCharacter->DoInteract(PlayerCharacter->GetInteractableActions()[0]);
	}
}

void UWHDInputManager::DoInteract2()
{
	AWHDPlayerCharacter* PlayerCharacter = UCommonStatics::GetPlayerPawn<AWHDPlayerCharacter>();
	
	if(!PlayerCharacter || PlayerCharacter->Execute_IsBlockAllInput(PlayerCharacter)) return;
	
	if(PlayerCharacter->GetInteractableActions().IsValidIndex(1))
	{
		PlayerCharacter->DoInteract(PlayerCharacter->GetInteractableActions()[1]);
	}
}

void UWHDInputManager::DoInteract3()
{
	AWHDPlayerCharacter* PlayerCharacter = UCommonStatics::GetPlayerPawn<AWHDPlayerCharacter>();
	
	if(!PlayerCharacter || PlayerCharacter->Execute_IsBlockAllInput(PlayerCharacter)) return;
	
	if(PlayerCharacter->GetInteractableActions().IsValidIndex(2))
	{
		PlayerCharacter->DoInteract(PlayerCharacter->GetInteractableActions()[2]);
	}
}

void UWHDInputManager::DoInteract4()
{
	AWHDPlayerCharacter* PlayerCharacter = UCommonStatics::GetPlayerPawn<AWHDPlayerCharacter>();
	
	if(!PlayerCharacter || PlayerCharacter->Execute_IsBlockAllInput(PlayerCharacter)) return;
	
	if(PlayerCharacter->GetInteractableActions().IsValidIndex(3))
	{
		PlayerCharacter->DoInteract(PlayerCharacter->GetInteractableActions()[3]);
	}
}

void UWHDInputManager::DoInteract5()
{
	AWHDPlayerCharacter* PlayerCharacter = UCommonStatics::GetPlayerPawn<AWHDPlayerCharacter>();
	
	if(!PlayerCharacter || PlayerCharacter->Execute_IsBlockAllInput(PlayerCharacter)) return;
	
	if(PlayerCharacter->GetInteractableActions().IsValidIndex(4))
	{
		PlayerCharacter->DoInteract(PlayerCharacter->GetInteractableActions()[4]);
	}
}

void UWHDInputManager::NextInteract()
{
	AWHDPlayerCharacter* PlayerCharacter = UCommonStatics::GetPlayerPawn<AWHDPlayerCharacter>();
	
	if(!PlayerCharacter || PlayerCharacter->Execute_IsBlockAllInput(PlayerCharacter)) return;
	
	if(PlayerCharacter->GetOverlappingAgents().Num() > 1)
	{
		PlayerCharacter->GetInteractingAgent()->LeaveInteract(PlayerCharacter);
	}
}

void UWHDInputManager::SelectInventorySlot1()
{
	if(UWidgetModuleStatics::GetUserWidget<UWHDWidgetCommonInventoryBar>())
	{
		UWidgetModuleStatics::GetUserWidget<UWHDWidgetCommonInventoryBar>()->SelectInventorySlot(0);
	}
}

void UWHDInputManager::SelectInventorySlot2()
{
	if(UWidgetModuleStatics::GetUserWidget<UWHDWidgetCommonInventoryBar>())
	{
		UWidgetModuleStatics::GetUserWidget<UWHDWidgetCommonInventoryBar>()->SelectInventorySlot(1);
	}
}

void UWHDInputManager::SelectInventorySlot3()
{
	if(UWidgetModuleStatics::GetUserWidget<UWHDWidgetCommonInventoryBar>())
	{
		UWidgetModuleStatics::GetUserWidget<UWHDWidgetCommonInventoryBar>()->SelectInventorySlot(2);
	}
}

void UWHDInputManager::SelectInventorySlot4()
{
	if(UWidgetModuleStatics::GetUserWidget<UWHDWidgetCommonInventoryBar>())
	{
		UWidgetModuleStatics::GetUserWidget<UWHDWidgetCommonInventoryBar>()->SelectInventorySlot(3);
	}
}

void UWHDInputManager::SelectInventorySlot5()
{
	if(UWidgetModuleStatics::GetUserWidget<UWHDWidgetCommonInventoryBar>())
	{
		UWidgetModuleStatics::GetUserWidget<UWHDWidgetCommonInventoryBar>()->SelectInventorySlot(4);
	}
}

void UWHDInputManager::SelectInventorySlot6()
{
	if(UWidgetModuleStatics::GetUserWidget<UWHDWidgetCommonInventoryBar>())
	{
		UWidgetModuleStatics::GetUserWidget<UWHDWidgetCommonInventoryBar>()->SelectInventorySlot(5);
	}
}

void UWHDInputManager::SelectInventorySlot7()
{
	if(UWidgetModuleStatics::GetUserWidget<UWHDWidgetCommonInventoryBar>())
	{
		UWidgetModuleStatics::GetUserWidget<UWHDWidgetCommonInventoryBar>()->SelectInventorySlot(6);
	}
}

void UWHDInputManager::SelectInventorySlot8()
{
	if(UWidgetModuleStatics::GetUserWidget<UWHDWidgetCommonInventoryBar>())
	{
		UWidgetModuleStatics::GetUserWidget<UWHDWidgetCommonInventoryBar>()->SelectInventorySlot(7);
	}
}

void UWHDInputManager::SelectInventorySlot9()
{
	if(UWidgetModuleStatics::GetUserWidget<UWHDWidgetCommonInventoryBar>())
	{
		UWidgetModuleStatics::GetUserWidget<UWHDWidgetCommonInventoryBar>()->SelectInventorySlot(8);
	}
}

void UWHDInputManager::SelectInventorySlot10()
{
	if(UWidgetModuleStatics::GetUserWidget<UWHDWidgetCommonInventoryBar>())
	{
		UWidgetModuleStatics::GetUserWidget<UWHDWidgetCommonInventoryBar>()->SelectInventorySlot(9);
	}
}

void UWHDInputManager::PrevInventorySlot()
{
	if(UWidgetModuleStatics::GetUserWidget<UWHDWidgetCommonInventoryBar>())
	{
		UWidgetModuleStatics::GetUserWidget<UWHDWidgetCommonInventoryBar>()->PrevInventorySlot();
	}
}

void UWHDInputManager::NextInventorySlot()
{
	if(UWidgetModuleStatics::GetUserWidget<UWHDWidgetCommonInventoryBar>())
	{
		UWidgetModuleStatics::GetUserWidget<UWHDWidgetCommonInventoryBar>()->NextInventorySlot();
	}
}
