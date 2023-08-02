// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "ReferencePool/ReferencePoolInterface.h"
#include "GameFramework/Actor.h"
#include "Voxel/VoxelModuleTypes.h"
#include "Voxel/Chunks/VoxelChunk.h"
#include "WHDVoxelChunk.generated.h"

class UVoxel;
class AAbilityPickUpBase;
class UVoxelMeshComponent;

/**
 * 体素块
 */
UCLASS()
class WHFRAMEWORKDEMO_API AWHDVoxelChunk : public AVoxelChunk
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWHDVoxelChunk();

protected:
	virtual void OnSpawn_Implementation(const TArray<FParameter>& InParams) override;
		
	virtual void OnDespawn_Implementation(bool bRecovery) override;

	virtual void LoadData(FSaveData* InSaveData, EPhase InPhase = EPhase::Final) override;

	virtual FSaveData* ToData(bool bRefresh) override;

	virtual void OnCollision(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit) override;
	
	virtual void OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) override;

	virtual void OnEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) override;

	//////////////////////////////////////////////////////////////////////////
	// Chunk
public:
	virtual void Initialize(FIndex InIndex, int32 InBatch) override;

	virtual void Generate(EPhase InPhase = EPhase::Primary) override;

	virtual void BuildMap(int32 InStage) override;

	virtual void BuildMesh() override;

	virtual void SpawnActors() override;

	virtual void LoadActors(FSaveData* InSaveData) override;

	virtual void GenerateActors() override;

	virtual void DestroyActors() override;

	//////////////////////////////////////////////////////////////////////////
	// SceneContainer
public:
	virtual void AddSceneActor(AActor* InActor) override;

	virtual void RemoveSceneActor(AActor* InActor) override;
};

