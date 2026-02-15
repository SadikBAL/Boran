// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Boran : ModuleRules
{
	public Boran(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"NavigationSystem",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"Niagara",
			"UMG",
			"Slate"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"Boran",
			"Boran/Controller",
			"Boran/GameMode",
			"Boran/GameState",
			"Boran/Pawn",
			"Boran/PlayerState",
			"Boran/Spectator",
			"Boran/UserInterface",
			
			"Boran/Variant_Strategy",
			"Boran/Variant_Strategy/UI",
		});
	}
}
