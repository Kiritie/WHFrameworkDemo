// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Common/Base/WHActor.h"
#include "Common/Interaction/InteractionAgentInterface.h"

#include "WHDEnterLevelTrigger.generated.h"

class UTextRenderComponent;
class UVoxel;

/**
 */
UCLASS()
class WHFRAMEWORKDEMO_API AWHDEnterLevelTrigger : public AWHActor, public IInteractionAgentInterface
{
	GENERATED_BODY()
	
public:
	AWHDEnterLevelTrigger();
	
public:
	virtual void OnRefresh_Implementation(float DeltaSeconds) override;
	
public:
	virtual bool CanInteract(EInteractAction InInteractAction, IInteractionAgentInterface* InInteractionAgent) override;

	virtual void OnEnterInteract(IInteractionAgentInterface* InInteractionAgent) override;

	virtual void OnLeaveInteract(IInteractionAgentInterface* InInteractionAgent) override;

	virtual void OnInteract(EInteractAction InInteractAction, IInteractionAgentInterface* InInteractionAgent, bool bPassivity) override;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UInteractionComponent* Interaction;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UTextRenderComponent* Text;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSoftObjectPtr<UWorld> Level;

public:
	virtual EInteractAgentType GetInteractAgentType() const override { return EInteractAgentType::Passivity; }
	
	UFUNCTION(BlueprintPure, meta = (DeterminesOutputType = "InAgentClass"))
	virtual AActor* GetInteractingAgent(TSubclassOf<AActor> InAgentClass) const { return Cast<AActor>(GetInteractingAgent()); }

	virtual IInteractionAgentInterface* GetInteractingAgent() const override { return IInteractionAgentInterface::GetInteractingAgent(); }
	
	virtual UInteractionComponent* GetInteractionComponent() const override;
};
