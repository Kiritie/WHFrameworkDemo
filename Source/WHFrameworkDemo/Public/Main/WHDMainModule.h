// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Main/MainModule.h"

#include "WHDMainModule.generated.h"

/**
 * 
 */
UCLASS()
class WHFRAMEWORKDEMO_API AWHDMainModule : public AMainModule
{
	GENERATED_BODY()
		
	GENERATED_MAIN_MODULE(AWHDMainModule)

public:
	AWHDMainModule();

	~AWHDMainModule();
	
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

	virtual void OnTermination_Implementation(EPhase InPhase) override;
};
