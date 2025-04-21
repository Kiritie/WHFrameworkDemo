// Fill out your copyright notice in the Description page of Project Settings.


#include "Camera/WHDRoamCameraActor.h"

#include "Camera/CameraModuleStatics.h"
#include "Components/SphereComponent.h"
#include "Voxel/VoxelModule.h"
#include "Voxel/VoxelModuleStatics.h"

AWHDRoamCameraActor::AWHDRoamCameraActor()
{
	CameraName = FName("RoamCamera");

	bFloorToChunk = false;
}

void AWHDRoamCameraActor::OnPreparatory_Implementation()
{
	Super::OnPreparatory_Implementation();
}

void AWHDRoamCameraActor::OnRefresh_Implementation(float DeltaSeconds)
{
	Super::OnRefresh_Implementation(DeltaSeconds);

	if(bFloorToChunk && GetActorLocation().Z == 0.f && UVoxelModule::Get().IsWorldBasicGenerated())
	{
		FHitResult HitResult;
		const FVector ChunkSize = UVoxelModuleStatics::GetVoxelWorldData().GetChunkRealSize();
		if(UVoxelModuleStatics::VoxelAgentTraceSingle(GetActorLocation(), FVector2D(ChunkSize.X, ChunkSize.Y), Sphere->GetScaledSphereRadius(), Sphere->GetScaledSphereRadius(), {}, HitResult, false, 10, true))
		{
			UCameraModuleStatics::SetCameraLocation(HitResult.Location);
		}
	}
}
