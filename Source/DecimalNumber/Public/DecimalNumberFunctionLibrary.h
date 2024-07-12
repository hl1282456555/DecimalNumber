// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Decimal.h"
#include "DecimalNumberFunctionLibrary.generated.h"

/**
 * 
 */
UCLASS()
class DECIMALNUMBER_API UDecimalNumberFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable)
	static void TestDecimal();
};
