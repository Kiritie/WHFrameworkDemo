// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Voxel/VoxelModule.h"
#include "WHDVoxelModule.generated.h"

/**
 * 体素模块
 */
UCLASS()
class WHFRAMEWORKDEMO_API AWHDVoxelModule : public AVoxelModule
{
	GENERATED_BODY()
		
	GENERATED_MODULE(AWHDVoxelModule)

public:	
	// Sets default values for this actor's properties
	AWHDVoxelModule();

	~AWHDVoxelModule();

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

public:
	virtual ECollisionChannel GetChunkTraceChannel() const override;
	
	virtual ECollisionChannel GetVoxelTraceChannel() const override;
};
