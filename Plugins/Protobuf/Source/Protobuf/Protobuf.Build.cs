// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

namespace UnrealBuildTool.Rules
{
	public class Protobuf : ModuleRules
	{
		public Protobuf(ReadOnlyTargetRules Target) : base(Target)
		{
			PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

			PublicIncludePaths.AddRange(
                new string[] {
					// ... add other private include paths required here ...
					ModuleDirectory
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
					// ... add other public dependencies that you statically link with here ...
				}
				);


			PrivateDependencyModuleNames.AddRange(
				new string[]
				{
					// ... add private dependencies that you statically link with here ...	
				}
				);


			DynamicallyLoadedModuleNames.AddRange(
				new string[]
				{
					// ... add any modules that your module loads dynamically here ...
				}
				);

			ShadowVariableWarningLevel = WarningLevel.Off;
			bEnableUndefinedIdentifierWarnings = false;
			bEnableExceptions = true;

			PublicDefinitions.Add("_CRT_SECURE_NO_WARNINGS");
		}
	}
}
