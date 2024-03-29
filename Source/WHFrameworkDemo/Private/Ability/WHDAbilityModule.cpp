// Fill out your copyright notice in the Description page of Project Settings.


#include "Ability/WHDAbilityModule.h"

#include "Ability/AbilityModuleBPLibrary.h"
#include "Common/WHDCommonTypes.h"

IMPLEMENTATION_MODULE(AWHDAbilityModule)

// ParamSets default values
AWHDAbilityModule::AWHDAbilityModule()
{
	
}

AWHDAbilityModule::~AWHDAbilityModule()
{
	TERMINATION_MODULE(AWHDAbilityModule)
}

#if WITH_EDITOR
void AWHDAbilityModule::OnGenerate()
{
	Super::OnGenerate();
}

void AWHDAbilityModule::OnDestroy()
{
	Super::OnDestroy();
}
#endif

void AWHDAbilityModule::OnInitialize_Implementation()
{
	Super::OnInitialize_Implementation();
}

void AWHDAbilityModule::OnPreparatory_Implementation(EPhase InPhase)
{
	Super::OnPreparatory_Implementation(InPhase);

	if(PHASEC(InPhase, EPhase::Primary))
	{
		UAssetModuleBPLibrary::AddEnumMapping(TEXT("/Script/WHFramework.EInteractAction"), TEXT("/Script/WHFrameworkDemo.EWHDInteractAction"));
	}
}

void AWHDAbilityModule::OnRefresh_Implementation(float DeltaSeconds)
{
	Super::OnRefresh_Implementation(DeltaSeconds);
}

void AWHDAbilityModule::OnPause_Implementation()
{
	Super::OnPause_Implementation();
}

void AWHDAbilityModule::OnUnPause_Implementation()
{
	Super::OnUnPause_Implementation();
}

ECollisionChannel AWHDAbilityModule::GetPickUpTraceChannel() const
{
	return ECC_GameTraceChannel9;
}
