#pragma once

#include "Ability/AbilityModuleTypes.h"

#include "WHDCommonTypes.generated.h"

/**
 * 交互选项
 */
UENUM(BlueprintType)
enum class EWHDInteractAction : uint8
{
	// 无
	None = EInteractAction::None UMETA(DisplayName="无"),
	// 进入
	Enter = EInteractAction::Custom3 UMETA(DisplayName="进入"),
	// 切换
	Switch = EInteractAction::Custom4 UMETA(DisplayName="切换")
};

namespace GameplayTags
{
	////////////////////////////////////////////////////
	// Input_Player
	WHFRAMEWORKDEMO_API	UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_Player_Jump);
};
