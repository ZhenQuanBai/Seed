// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Seed : ModuleRules
{
	public Seed(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "Protobuf" });

		PrivateDependencyModuleNames.AddRange(new string[] {  });

        ShadowVariableWarningLevel = WarningLevel.Off;
        bEnableUndefinedIdentifierWarnings = false;
        bEnableExceptions = true;

        PublicDefinitions.Add("_CRT_SECURE_NO_WARNINGS");
    }
}
