// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Ability/AbilityModule.h"

#include "WHDAbilityModule.generated.h"

UCLASS()
class WHFRAMEWORKDEMO_API AWHDAbilityModule : public AAbilityModule
{
	GENERATED_BODY()
		
	GENERATED_MODULE(AWHDAbilityModule)

public:	
	// ParamSets default values for this actor's properties
	AWHDAbilityModule();
	
	~AWHDAbilityModule();
	
	//////////////////////////////////////////////////////////////////////////
	/// Module
public:
#if WITH_EDITOR
	virtual void OnGenerate() override;

	virtual void OnDestroy() override;
#endif

	virtual void OnInitialize_Implementation() override;

	virtual void OnPreparatory_Implementation(EPhase InPhase) override;

	virtual void OnRefresh_Implementation(float DeltaSeconds) override;

	virtual void OnPause_Implementation() override;

	virtual void OnUnPause_Implementation() override;

public:
	virtual ECollisionChannel GetPickUpTraceChannel() const override;
};
