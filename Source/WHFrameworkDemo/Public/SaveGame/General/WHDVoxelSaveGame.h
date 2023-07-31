// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Global/WHDGlobalTypes.h"
#include "SaveGame/General/GeneralSaveGame.h"

#include "WHDVoxelSaveGame.generated.h"

class UDWArchiveSaveGame;

/**
 * 常规游戏数据存取类
 */
UCLASS()
class WHFRAMEWORKDEMO_API UWHDVoxelSaveGame : public UGeneralSaveGame
{
	GENERATED_BODY()

public:
	UWHDVoxelSaveGame();
	
public:
	virtual void OnCreate_Implementation(int32 InSaveIndex) override;
	
	virtual void OnLoad_Implementation(EPhase InPhase) override;
	
	virtual void OnUnload_Implementation(EPhase InPhase) override;

	virtual void OnRefresh_Implementation() override;

// protected:
// 	UPROPERTY()
// 	FWHDVoxelSaveData WHDVoxelSaveData;
//
// public:
// 	virtual FSaveData* GetSaveData() override { return &WHDVoxelSaveData; }
//
// 	virtual void SetSaveData(FSaveData* InSaveData) override { WHDVoxelSaveData = InSaveData->CastRef<FWHDVoxelSaveData>(); }
//
// 	UFUNCTION(BlueprintPure, meta = (DisplayName = "GetSaveData"))
// 	FWHDVoxelSaveData& K2_GetSaveData() { return WHDVoxelSaveData; }
//
// 	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SetSaveData"))
// 	void K2_SetSaveData(const FWHDVoxelSaveData& InSaveData) { this->WHDVoxelSaveData = InSaveData; }
};
