// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class WHFrameworkDemo : ModuleRules
{
	public WHFrameworkDemo(ReadOnlyTargetRules Target) : base(Target)
	{
		bLegacyPublicIncludePaths = false;

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
				"Slate",
				"UMG",
				"CommonUI",
				"AIModule",
				"CommonInput",
				"EnhancedInput",
				"GameplayAbilities",
				"GameplayTags",
				"GameplayTasks",
				"ProceduralMeshComponent"
			}
		);

	}
}
