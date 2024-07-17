// Copyright Epic Games, Inc. All Rights Reserved.

#include "DecimalNumber.h"
#include "IPluginManager.h"

THIRD_PARTY_INCLUDES_START
#include <boost/assert/source_location.hpp>
THIRD_PARTY_INCLUDES_END

DECLARE_LOG_CATEGORY_CLASS(LogDecimalNumber, Log, All);

#define LOCTEXT_NAMESPACE "FDecimalNumberModule"

namespace boost
{
	void throw_exception(std::exception const& e)
	{
		UE_LOG(LogDecimalNumber, Error, TEXT("[DecimalNumber][boost] - %s"), *FString(e.what()));
	}
	
	void throw_exception(std::exception const& e, boost::source_location const& loc)
	{
		UE_LOG(LogDecimalNumber, Error, TEXT("[DecimalNumber][boost][%s-%s-%d-%d] - %s"),
			*FString(loc.file_name()), *FString(loc.function_name()), loc.line(), loc.column(), *FString(e.what()));
	}
}

void FDecimalNumberModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	TArray<FString> DllNames =
		{
			TEXT("boost_container-vc144-mt-x64-1_85.dll"),
			TEXT("boost_random-vc144-mt-x64-1_85.dll"),
			TEXT("boost_regex-vc144-mt-x64-1_85.dll"),
			TEXT("boost_system-vc144-mt-x64-1_85.dll")
		};

	const FString PluginDir = IPluginManager::Get().FindPlugin("DecimalNumber")->GetBaseDir();
	for (const FString& DllName : DllNames)
	{
		void* NewHandle = FPlatformProcess::GetDllHandle(*FPaths::Combine(PluginDir, "ThirdParty/boost_multiprecision_1.8.5/bin", DllName));
		if (NewHandle == nullptr)
		{
			UE_LOG(LogTemp, Error, TEXT("%s - Failed to load dependency dll '%s'"), __FUNCTIONW__, *DllName);
			continue;
		}

		Handles.Add(NewHandle);
	}
}

void FDecimalNumberModule::ShutdownModule()
{
	for (void* Handle : Handles)
	{
		FPlatformProcess::FreeDllHandle(Handle);
	}

	Handles.Empty();
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FDecimalNumberModule, DecimalNumber)