// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Camera/Roam/RoamCameraPawn.h"
#include "WHDRoamCameraPawn.generated.h"

UCLASS()
class WHFRAMEWORKDEMO_API AWHDRoamCameraPawn : public ARoamCameraPawn
{
	GENERATED_BODY()

public:
	AWHDRoamCameraPawn();

public:
	virtual void OnRefresh_Implementation(float DeltaSeconds) override;
	
protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CameraStats")
	bool bFloorToChunk;
};
