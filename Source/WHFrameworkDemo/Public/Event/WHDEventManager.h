// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Event/Manager/DefaultEventManagerBase.h"
#include "WHDEventManager.generated.h"

/**
 * 
 */
UCLASS()
class WHFRAMEWORKDEMO_API UWHDEventManager : public UDefaultEventManagerBase
{
	GENERATED_BODY()

public:
	virtual void OnInitialize() override;
};
