// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Gameplay/WHGameInstance.h"
#include "WHDGameInstance.generated.h"

/**
 * 游戏实例基类
 */
UCLASS()
class WHFRAMEWORKDEMO_API UWHDGameInstance : public UWHGameInstance
{
	GENERATED_BODY()

public:
	UWHDGameInstance();

public:
	virtual void Init() override;

	virtual void Shutdown() override;
};
