// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Camera/Roam/RoamCameraActor.h"
#include "WHDRoamCameraActor.generated.h"

UCLASS()
class WHFRAMEWORKDEMO_API AWHDRoamCameraActor : public ARoamCameraActor
{
	GENERATED_BODY()

public:
	AWHDRoamCameraActor();

public:
	virtual void OnPreparatory_Implementation(EPhase InPhase) override;

public:
	virtual void OnRefresh_Implementation(float DeltaSeconds) override;
	
protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CameraStats")
	bool bFloorToChunk;
};
