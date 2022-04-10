// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class WHFrameworkDemo : ModuleRules
{
	public WHFrameworkDemo(ReadOnlyTargetRules Target) : base(Target)
	{
		PrivatePCHHeaderFile = "WHFrameworkDemo.h";

		bLegacyPublicIncludePaths = false;

		ShadowVariableWarningLevel = WarningLevel.Error;

		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(
			new string[] {
				"Core",
				"CoreUObject",
				"Engine",
				"WHFramework"
			}
		);

		PrivateDependencyModuleNames.AddRange(
			new string[] {
				"InputCore",
				"SlateCore",
				"UMG",
				"AIModule",
				"GameplayAbilities",
				"GameplayTags",
				"GameplayTasks",
				"ProceduralMeshComponent",
				"WHFramework"
			}
		);

	}
}
