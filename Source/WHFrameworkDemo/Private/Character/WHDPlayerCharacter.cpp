// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "Character/WHDPlayerCharacter.h"

#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "GameFramework/PawnMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Voxel/VoxelModule.h"
#include "Voxel/VoxelModuleBPLibrary.h"

//////////////////////////////////////////////////////////////////////////
// AWHDPlayerCharacter

AWHDPlayerCharacter::AWHDPlayerCharacter()
{
	GetCapsuleComponent()->SetCapsuleHalfHeight(69.f);
	GetCapsuleComponent()->SetCapsuleRadius(24.f);

	GetMesh()->SetRelativeLocation(FVector(0.f, 0.f, -70.f));

	AutoPossessAI = EAutoPossessAI::Disabled;
}

void AWHDPlayerCharacter::OnInitialize_Implementation()
{
	Super::OnInitialize_Implementation();

	GetMovementComponent()->SetActive(false);
}

void AWHDPlayerCharacter::OnRefresh_Implementation(float DeltaSeconds)
{
	Super::OnRefresh_Implementation(DeltaSeconds);

	if(bFloorToChunk && GetActorLocation().Z <= 0.f && AVoxelModule::Get()->IsBasicGenerated())
	{
		FHitResult HitResult;
		if(UVoxelModuleBPLibrary::VoxelAgentTraceSingle(GetActorLocation(), FVector2D(UVoxelModuleBPLibrary::GetWorldData().GetChunkRealSize().X, UVoxelModuleBPLibrary::GetWorldData().GetChunkRealSize().Y), GetCapsuleComponent()->GetScaledCapsuleRadius(), GetCapsuleComponent()->GetScaledCapsuleHalfHeight(), {}, HitResult, false, 10, true))
		{
			SetActorLocation(HitResult.Location);
			GetMovementComponent()->SetActive(true);
			GetMovementComponent()->Velocity = FVector::ZeroVector;
		}
	}
}

void AWHDPlayerCharacter::OnSpawn_Implementation(const TArray<FParameter>& InParams)
{
	Super::OnSpawn_Implementation(InParams);
}

void AWHDPlayerCharacter::OnDespawn_Implementation(bool bRecovery)
{
	Super::OnDespawn_Implementation(bRecovery);
}
