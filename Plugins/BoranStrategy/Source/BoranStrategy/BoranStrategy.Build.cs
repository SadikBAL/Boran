// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class BoranStrategy : ModuleRules
{
	public BoranStrategy(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
		
		PublicIncludePaths.AddRange(
			new string[] {
				ModuleDirectory,
				ModuleDirectory + "/Controller",
				ModuleDirectory + "/GameMode",
				ModuleDirectory + "/Pawn",
				ModuleDirectory + "/UserInterface",
			}
			);
				
		
		PrivateIncludePaths.AddRange(
			new string[] {
				
			}
			);
			
		
		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				"InputCore",
				"EnhancedInput",
				"UMG",
				"AIModule",
				"NavigationSystem",
				"Boran"
			}
			);
			
		
		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"CoreUObject",
				"Engine",
				"Slate",
				"SlateCore",
			}
			);
		
		
		DynamicallyLoadedModuleNames.AddRange(
			new string[]
			{
				// ... add any modules that your module loads dynamically here ...
			}
			);
	}
}
