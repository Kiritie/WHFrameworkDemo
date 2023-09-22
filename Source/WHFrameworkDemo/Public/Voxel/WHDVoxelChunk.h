// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

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
};

