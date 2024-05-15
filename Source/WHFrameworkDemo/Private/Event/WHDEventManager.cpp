// Fill out your copyright notice in the Description page of Project Settings.


#include "Event/WHDEventManager.h"

#include "Asset/AssetModuleStatics.h"

void UWHDEventManager::OnInitialize()
{
	Super::OnInitialize();

	UAssetModuleStatics::AddEnumMapping(TEXT("/Script/WHFramework.EInteractAction"), TEXT("/Script/WHFrameworkDemo.EWHDInteractAction"));
}
