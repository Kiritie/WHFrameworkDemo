// Fill out your copyright notice in the Description page of Project Settings.

#include "Character/State/WHDPlayerCharacterState_Death.h"

UWHDPlayerCharacterState_Death::UWHDPlayerCharacterState_Death()
{
}

void UWHDPlayerCharacterState_Death::OnInitialize(UFSMComponent* InFSM, int32 InStateIndex)
{
	Super::OnInitialize(InFSM, InStateIndex);
}

bool UWHDPlayerCharacterState_Death::OnPreEnter(UFiniteStateBase* InLastState, const TArray<FParameter>& InParams)
{
	return Super::OnPreEnter(InLastState, InParams);
}

void UWHDPlayerCharacterState_Death::OnEnter(UFiniteStateBase* InLastState, const TArray<FParameter>& InParams)
{
	Super::OnEnter(InLastState, InParams);
}

void UWHDPlayerCharacterState_Death::OnRefresh(float DeltaSeconds)
{
	Super::OnRefresh(DeltaSeconds);
}

void UWHDPlayerCharacterState_Death::OnLeave(UFiniteStateBase* InNextState)
{
	Super::OnLeave(InNextState);
}

void UWHDPlayerCharacterState_Death::OnTermination()
{
	Super::OnTermination();
}
