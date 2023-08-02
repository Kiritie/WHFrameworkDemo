// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SaveGame/SaveGameModule.h"

#include "WHDSaveGameModule.generated.h"

UCLASS()
class WHFRAMEWORKDEMO_API AWHDSaveGameModule : public ASaveGameModule
{
	GENERATED_BODY()
		
	GENERATED_MODULE(AWHDSaveGameModule)

public:	
	// ParamSets default values for this actor's properties
	AWHDSaveGameModule();

	~AWHDSaveGameModule();
	
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

	virtual void OnTermination_Implementation() override;

protected:
	virtual void LoadData(FSaveData* InSaveData, EPhase InPhase) override;

	virtual FSaveData* ToData(bool bRefresh) override;
};
