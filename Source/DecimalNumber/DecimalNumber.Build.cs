// Copyright Epic Games, Inc. All Rights Reserved.

using System.IO;
using UnrealBuildTool;

public class DecimalNumber : ModuleRules
{
	public DecimalNumber(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
		
		string ThirdPartyDir = Path.Combine(ModuleDirectory, "../../ThirdParty/boost_multiprecision_1.8.5");
		
		PublicIncludePaths.Add(Path.Combine(ThirdPartyDir, "include"));
		
		PublicAdditionalLibraries.AddRange(
			new string[]
			{
				Path.Combine(ThirdPartyDir, "lib/boost_system-vc144-mt-x64-1_85.lib"),
				Path.Combine(ThirdPartyDir, "lib/boost_container-vc144-mt-x64-1_85.lib"),
				Path.Combine(ThirdPartyDir, "lib/boost_random-vc144-mt-x64-1_85.lib"),
				Path.Combine(ThirdPartyDir, "lib/boost_regex-vc144-mt-x64-1_85.lib")
			});
		
		PublicDelayLoadDLLs.AddRange(
			new string[]
			{
				"boost_container-vc144-mt-x64-1_85.dll",
				"boost_random-vc144-mt-x64-1_85.dll",
				"boost_regex-vc144-mt-x64-1_85.dll",
				"boost_system-vc144-mt-x64-1_85.dll"
			});
		
		RuntimeDependencies.Add(Path.Combine(ThirdPartyDir, "/bin/boost_container-vc144-mt-x64-1_85.dll"));
		RuntimeDependencies.Add(Path.Combine(ThirdPartyDir, "/bin/boost_random-vc144-mt-x64-1_85.dll"));
		RuntimeDependencies.Add(Path.Combine(ThirdPartyDir, "/bin/boost_regex-vc144-mt-x64-1_85.dll"));
		RuntimeDependencies.Add(Path.Combine(ThirdPartyDir, "/bin/boost_system-vc144-mt-x64-1_85.dll"));
		
		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				"Projects"
				// ... add other public dependencies that you statically link with here ...
			}
			);
			
		
		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"CoreUObject",
				"Engine"
				// ... add private dependencies that you statically link with here ...	
			}
			);
	}
}
