// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Seed : ModuleRules
{
	public Seed(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PrivateIncludePaths.AddRange(
			new string[] {
				// ... add public include paths required here ...
				ModuleDirectory
		}
		);

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "Protobuf", "TcpSocketPlugin" });

		PrivateDependencyModuleNames.AddRange(new string[] {  });

        ShadowVariableWarningLevel = WarningLevel.Off;
        bEnableUndefinedIdentifierWarnings = false;
        bEnableExceptions = true;

        PublicDefinitions.Add("_CRT_SECURE_NO_WARNINGS");
    }
}
