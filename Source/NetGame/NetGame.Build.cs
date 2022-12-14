// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class NetGame : ModuleRules
{
	public NetGame(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { 
			"Core", 
			"CoreUObject", 
			"Engine", 
			"InputCore", 
			"HeadMountedDisplay",
			"OnlineSubsystem",
			"OnlineSubsystemUtils",
			"UMG"
		});
		
		PrivateDependencyModuleNames.AddRange(new string[]
		{
			"GameplayAbilities",
			"GameplayTags",
			"GameplayTasks"
		});
	}
}
