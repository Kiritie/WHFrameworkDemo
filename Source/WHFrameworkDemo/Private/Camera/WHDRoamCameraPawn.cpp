// Fill out your copyright notice in the Description page of Project Settings.


#include "Camera/WHDRoamCameraPawn.h"

#include "Camera/CameraModuleBPLibrary.h"
#include "Components/SphereComponent.h"
#include "Voxel/VoxelModuleBPLibrary.h"

AWHDRoamCameraPawn::AWHDRoamCameraPawn()
{
	CameraName = FName("RoamCamera");
}

void AWHDRoamCameraPawn::OnRefresh_Implementation(float DeltaSeconds)
{
	Super::OnRefresh_Implementation(DeltaSeconds);

	if(GetActorLocation().IsNearlyZero() && bFloorToChunk)
	{
		FHitResult hitResult;
		if(UVoxelModuleBPLibrary::VoxelAgentTraceSingle(GetActorLocation(), Sphere->GetScaledSphereRadius(), Sphere->GetScaledSphereRadius(), {}, hitResult, true, 10, true))
		{
			UCameraModuleBPLibrary::SetCameraLocation(hitResult.Location);
		}
	}
}
