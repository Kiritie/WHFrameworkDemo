// Fill out your copyright notice in the Description page of Project Settings.


#include "Camera/WHDRoamCameraActor.h"

#include "Camera/CameraModuleBPLibrary.h"
#include "Components/SphereComponent.h"
#include "Voxel/VoxelModule.h"
#include "Voxel/VoxelModuleBPLibrary.h"

AWHDRoamCameraActor::AWHDRoamCameraActor()
{
	CameraName = FName("RoamCamera");

	bFloorToChunk = false;
}

void AWHDRoamCameraActor::OnPreparatory_Implementation(EPhase InPhase)
{
	Super::OnPreparatory_Implementation(InPhase);
}

void AWHDRoamCameraActor::OnRefresh_Implementation(float DeltaSeconds)
{
	Super::OnRefresh_Implementation(DeltaSeconds);

	if(bFloorToChunk && GetActorLocation().Z == 0.f && AVoxelModule::Get()->IsBasicGenerated())
	{
		FHitResult HitResult;
		const FVector ChunkSize = UVoxelModuleBPLibrary::GetWorldData().GetChunkRealSize();
		if(UVoxelModuleBPLibrary::VoxelAgentTraceSingle(GetActorLocation(), FVector2D(ChunkSize.X, ChunkSize.Y), Sphere->GetScaledSphereRadius(), Sphere->GetScaledSphereRadius(), {}, HitResult, false, 10, true))
		{
			UCameraModuleBPLibrary::SetCameraLocation(HitResult.Location);
		}
	}
}
