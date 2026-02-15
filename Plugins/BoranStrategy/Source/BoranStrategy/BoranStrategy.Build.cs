// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class BoranStrategy : ModuleRules
{
	public BoranStrategy(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
		
		PublicIncludePaths.AddRange(
			new string[] {
				"BoranStrategy",
				"BoranStrategy/Character",
				"BoranStrategy/Controller",
				"BoranStrategy/GameMode",
				"BoranStrategy/GameState",
				"BoranStrategy/HUD",
				"BoranStrategy/PlayerState",
				"BoranStrategy/Spectator",
			}
			);
				
		
		PrivateIncludePaths.AddRange(
			new string[] {
				// ... add other private include paths required here ...
			}
			);
			
		
		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				"Boran",
			}
			);
			
		
		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"CoreUObject",
				"Engine",
				"Slate",
				"SlateCore",
				// ... add private dependencies that you statically link with here ...	
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
