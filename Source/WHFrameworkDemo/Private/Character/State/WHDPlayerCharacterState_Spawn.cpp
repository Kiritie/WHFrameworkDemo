// Fill out your copyright notice in the Description page of Project Settings.

#include "Character/State/WHDPlayerCharacterState_Spawn.h"

#include "Character/WHDPlayerCharacter.h"
#include "Components/CapsuleComponent.h"
#include "Voxel/VoxelModule.h"
#include "Voxel/VoxelModuleStatics.h"
#include "Voxel/Chunks/VoxelChunk.h"

UWHDPlayerCharacterState_Spawn::UWHDPlayerCharacterState_Spawn()
{
}

void UWHDPlayerCharacterState_Spawn::OnInitialize(UFSMComponent* InFSM, int32 InStateIndex)
{
	Super::OnInitialize(InFSM, InStateIndex);
}

bool UWHDPlayerCharacterState_Spawn::OnPreEnter(UFiniteStateBase* InLastState, const TArray<FParameter>& InParams)
{
	return Super::OnPreEnter(InLastState, InParams);
}

void UWHDPlayerCharacterState_Spawn::OnEnter(UFiniteStateBase* InLastState, const TArray<FParameter>& InParams)
{
	Super::OnEnter(InLastState, InParams);
}

void UWHDPlayerCharacterState_Spawn::OnRefresh(float DeltaSeconds)
{
	Super::OnRefresh(DeltaSeconds);
}

void UWHDPlayerCharacterState_Spawn::OnLeave(UFiniteStateBase* InNextState)
{
	Super::OnLeave(InNextState);
}

void UWHDPlayerCharacterState_Spawn::OnTermination()
{
	Super::OnTermination();
}

void UWHDPlayerCharacterState_Spawn::TryLeave()
{
	if(!UVoxelModule::IsValid())
	{
		Super::TryLeave();
	}
	else if(UVoxelModule::Get().IsBasicGenerated())
	{
		AWHDPlayerCharacter* PlayerCharacter = GetAgent<AWHDPlayerCharacter>();
		if(PlayerCharacter->GetActorLocation().Z <= 0.f)
		{
			const FVector ChunkSize = UVoxelModuleStatics::GetWorldData().GetChunkRealSize();
			FHitResult HitResult;
			if(UVoxelModuleStatics::VoxelAgentTraceSingle(PlayerCharacter->GetActorLocation(), FVector2D(ChunkSize.X, ChunkSize.Y), PlayerCharacter->GetCapsuleComponent()->GetScaledCapsuleRadius(), PlayerCharacter->GetCapsuleComponent()->GetScaledCapsuleHalfHeight(), {}, HitResult, false, 10, true))
			{
				PlayerCharacter->SetActorLocation(HitResult.Location);
				Super::TryLeave();
			}
		}
		else if(AVoxelChunk* VoxelChunk = Cast<AVoxelChunk>(ISceneActorInterface::Execute_GetContainer(PlayerCharacter).GetObject()))
		{
			if(VoxelChunk->IsGenerated())
			{
				Super::TryLeave();
			}
		}
	}
}
