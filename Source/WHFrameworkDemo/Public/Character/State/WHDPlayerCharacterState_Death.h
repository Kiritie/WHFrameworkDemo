// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Ability/Character/States/AbilityCharacterState_Death.h"
#include "WHDPlayerCharacterState_Death.generated.h"

/**
 * 
 */
UCLASS()
class WHFRAMEWORKDEMO_API UWHDPlayerCharacterState_Death : public UAbilityCharacterState_Death
{
	GENERATED_BODY()

public:
	UWHDPlayerCharacterState_Death();

public:
	virtual void OnInitialize(UFSMComponent* InFSM, int32 InStateIndex) override;

	virtual bool OnPreEnter(UFiniteStateBase* InLastState, const TArray<FParameter>& InParams) override;

	virtual void OnEnter(UFiniteStateBase* InLastState, const TArray<FParameter>& InParams) override;
	
	virtual void OnRefresh(float DeltaSeconds) override;

	virtual void OnLeave(UFiniteStateBase* InNextState) override;

	virtual void OnTermination() override;
};
