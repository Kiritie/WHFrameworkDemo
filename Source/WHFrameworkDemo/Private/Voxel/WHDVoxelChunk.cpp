// Fill out your copyright notice in the Description page of Project Settings.PickUp/


#include "Voxel/WHDVoxelChunk.h"

#include "Ability/AbilityModuleBPLibrary.h"
#include "Ability/Character/AbilityCharacterDataBase.h"
#include "Ability/PickUp/AbilityPickUpBase.h"
#include "Ability/Vitality/AbilityVitalityDataBase.h"
#include "Character/Base/CharacterBase.h"
#include "Components/BoxComponent.h"
#include "Global/GlobalTypes.h"
#include "Main/MainModule.h"
#include "Voxel/VoxelModule.h"
#include "Voxel/Components/VoxelMeshComponent.h"
#include "Voxel/Voxels/Voxel.h"
#include "Voxel/Voxels/Auxiliary/VoxelAuxiliary.h"
#include "ObjectPool/ObjectPoolModuleBPLibrary.h"
#include "SaveGame/SaveGameModuleBPLibrary.h"
#include "Voxel/VoxelModuleBPLibrary.h"

// Sets default values
AWHDVoxelChunk::AWHDVoxelChunk()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void AWHDVoxelChunk::BeginPlay()
{
	Super::BeginPlay();
}

void AWHDVoxelChunk::OnSpawn_Implementation(const TArray<FParameter>& InParams)
{
	Super::OnSpawn_Implementation(InParams);
}

void AWHDVoxelChunk::OnDespawn_Implementation(bool bRecovery)
{
	Super::OnDespawn_Implementation(bRecovery);
}

void AWHDVoxelChunk::LoadData(FSaveData* InSaveData, EPhase InPhase)
{
	Super::LoadData(InSaveData, InPhase);
}
 
FSaveData* AWHDVoxelChunk::ToData()
{
	return Super::ToData();
}

void AWHDVoxelChunk::OnCollision(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	Super::OnCollision(HitComponent, OtherActor, OtherComp, NormalImpulse, Hit);
}

void AWHDVoxelChunk::OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	Super::OnBeginOverlap(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex, bFromSweep, SweepResult);
}

void AWHDVoxelChunk::OnEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	Super::OnEndOverlap(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex);
}

// Called every frame
void AWHDVoxelChunk::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AWHDVoxelChunk::Initialize(FIndex InIndex, int32 InBatch)
{
	Super::Initialize(InIndex, InBatch);
}

void AWHDVoxelChunk::Generate(EPhase InPhase)
{
	Super::Generate(InPhase);
}

void AWHDVoxelChunk::BuildMap(int32 InStage)
{
	Super::BuildMap(InStage);
}

void AWHDVoxelChunk::BuildMesh()
{
	Super::BuildMesh();
}

void AWHDVoxelChunk::SpawnActors()
{
	Super::SpawnActors();
}

void AWHDVoxelChunk::LoadActors(FSaveData* InSaveData)
{
	Super::LoadActors(InSaveData);
}

void AWHDVoxelChunk::GenerateActors()
{
	Super::GenerateActors();
}

void AWHDVoxelChunk::DestroyActors()
{
	Super::DestroyActors();
}

void AWHDVoxelChunk::AddSceneActor(AActor* InActor)
{
	Super::AddSceneActor(InActor);
}

void AWHDVoxelChunk::RemoveSceneActor(AActor* InActor)
{
	Super::RemoveSceneActor(InActor);
}
