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

	virtual void OnTermination_Implementation() override;
	
protected:
	virtual void LoadData(FSaveData* InSaveData, EPhase InPhase = EPhase::Final) override;

	virtual FSaveData* ToData() override;

	virtual void UnloadData(EPhase InPhase = EPhase::Final) override;

	//////////////////////////////////////////////////////////////////////////
	// World
protected:
	virtual void OnWorldStateChanged() override;

protected:
	virtual void GenerateWorld() override;

public:
	virtual void BuildChunkMap(FIndex InIndex, int32 InStage) override;

	virtual void BuildChunkMesh(FIndex InIndex) override;

	virtual void GenerateChunk(FIndex InIndex) override;

	virtual void DestroyChunk(FIndex InIndex) override;

public:
	virtual AVoxelChunk* SpawnChunk(FIndex InIndex, bool bAddToQueue = true) override;

	virtual ECollisionChannel GetChunkTraceType() const override;

	virtual ECollisionChannel GetVoxelTraceType() const override;
};
