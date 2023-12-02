// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class SQEXSEADEd : ModuleRules
{
	public SQEXSEADEd(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
		bLegacyPublicIncludePaths = false;
		ShadowVariableWarningLevel = WarningLevel.Warning;
		
		PublicDependencyModuleNames.AddRange(new string[] {
            "Core",
            "CoreUObject",
            "Engine",
            "SQEXSEADUtils",
			"Slate",
			"SlateCore",
            "UnrealEd",
			"SQEXSEAD",
        });
		
	}
}