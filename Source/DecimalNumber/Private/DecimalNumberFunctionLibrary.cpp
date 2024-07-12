// Fill out your copyright notice in the Description page of Project Settings.


#include "DecimalNumberFunctionLibrary.h"
#include "DecimalMath.h"
#include "DecimalVector.h"

void UDecimalNumberFunctionLibrary::TestDecimal()
{
	FDecimal TestA, TestB(11111.11), TestC(TEXT("0.0001"));

	UE_LOG(LogTemp, Warning, TEXT("TestDecimal step 1 - %s"), *TestA.ToString());
	UE_LOG(LogTemp, Warning, TEXT("TestDecimal step 1 - %s"), *TestB.ToString());
	UE_LOG(LogTemp, Warning, TEXT("TestDecimal step 1 - %s"), *TestC.ToString());

	double TestD = TestA.ToDouble();
	TestA = TestD;

	TestD = TestB.ToDouble();
	TestB = TestD;
	
	TestD = TestC.ToDouble();
	TestC = TestD;

	UE_LOG(LogTemp, Warning, TEXT("TestDecimal step 2 - %s"), *TestA.ToString());
	UE_LOG(LogTemp, Warning, TEXT("TestDecimal step 2 - %s"), *TestB.ToString());
	UE_LOG(LogTemp, Warning, TEXT("TestDecimal step 2 - %s"), *TestC.ToString());

	UE_LOG(LogTemp, Warning, TEXT("TestDecimal step 3 - %s"), *(TestA + TestB).ToString());
	UE_LOG(LogTemp, Warning, TEXT("TestDecimal step 3 - %s"), *(TestA - TestB).ToString());
	UE_LOG(LogTemp, Warning, TEXT("TestDecimal step 3 - %s"), *(TestB + TestC).ToString());
	UE_LOG(LogTemp, Warning, TEXT("TestDecimal step 3 - %s"), *(TestB - TestC).ToString());
	UE_LOG(LogTemp, Warning, TEXT("TestDecimal step 3 - %s"), *(TestA + TestC).ToString());
	UE_LOG(LogTemp, Warning, TEXT("TestDecimal step 3 - %s"), *(TestA - TestC).ToString());

	UE_LOG(LogTemp, Warning, TEXT("TestDecimal step 4 - %s"), *(FDecimal(1) / FDecimal(10000.0f)).ToString());
	UE_LOG(LogTemp, Warning, TEXT("TestDecimal step 4 - %s"), *(FDecimal(1) / FDecimal(3.0f)).ToString());
	UE_LOG(LogTemp, Warning, TEXT("TestDecimal step 4 - %s"), *(FDecimal(1) / FDecimal(10000)).ToString());
	UE_LOG(LogTemp, Warning, TEXT("TestDecimal step 4 - %s"), *(FDecimal(1) / FDecimal(3)).ToString());
	UE_LOG(LogTemp, Warning, TEXT("TestDecimal step 4 - %s"), *(FDecimal(1) * FDecimal(10000.0f)).ToString());
	UE_LOG(LogTemp, Warning, TEXT("TestDecimal step 4 - %s"), *(FDecimal(0.0001) * FDecimal(10000.0f)).ToString());
	UE_LOG(LogTemp, Warning, TEXT("TestDecimal step 4 - %s"), *(FDecimal(0.33) / FDecimal(10.0f)).ToString());
	UE_LOG(LogTemp, Warning, TEXT("TestDecimal step 4 - %s"), *(FDecimal("0.33") / FDecimal(10.0f)).ToString());

	UE_LOG(LogTemp, Warning, TEXT("TestDecimal step ceil 1/3	- %s"), *FDecimalMath::Ceil(FDecimal(1) / FDecimal(3)).ToString());
	UE_LOG(LogTemp, Warning, TEXT("TestDecimal step ceil 0		- %s"), *FDecimalMath::Ceil(FDecimal(0)).ToString());
	UE_LOG(LogTemp, Warning, TEXT("TestDecimal step ceil 0.1	- %s"), *FDecimalMath::Ceil(FDecimal(0.1)).ToString());
	UE_LOG(LogTemp, Warning, TEXT("TestDecimal step ceil 0.5	- %s"), *FDecimalMath::Ceil(FDecimal(0.5)).ToString());
	UE_LOG(LogTemp, Warning, TEXT("TestDecimal step ceil 0.9	- %s"), *FDecimalMath::Ceil(FDecimal(0.9)).ToString());

	UE_LOG(LogTemp, Warning, TEXT("TestDecimal step power 3		- %s"), *FDecimalMath::Power(FDecimal(3), 2).ToString());
	UE_LOG(LogTemp, Warning, TEXT("TestDecimal step power 2.2	- %s"), *FDecimalMath::Power(FDecimal(2.2), 2).ToString());
	UE_LOG(LogTemp, Warning, TEXT("TestDecimal step power 0.2	- %s"), *FDecimalMath::Power(FDecimal(0.2), 2).ToString());

	UE_LOG(LogTemp, Warning, TEXT("TestDecimal step floor 1/3	- %s"), *FDecimalMath::Floor(FDecimal(1) / FDecimal(3)).ToString());
	UE_LOG(LogTemp, Warning, TEXT("TestDecimal step floor 0		- %s"), *FDecimalMath::Floor(FDecimal(0)).ToString());
	UE_LOG(LogTemp, Warning, TEXT("TestDecimal step floor 0.1	- %s"), *FDecimalMath::Floor(FDecimal(0.1)).ToString());
	UE_LOG(LogTemp, Warning, TEXT("TestDecimal step floor 0.5	- %s"), *FDecimalMath::Floor(FDecimal(0.5)).ToString());
	UE_LOG(LogTemp, Warning, TEXT("TestDecimal step floor 0.9	- %s"), *FDecimalMath::Floor(FDecimal(0.9)).ToString());

	UE_LOG(LogTemp, Warning, TEXT("TestDecimal step sqrt 9		- %s"), *FDecimalMath::Sqrt(FDecimal(9)).ToString());
	UE_LOG(LogTemp, Warning, TEXT("TestDecimal step sqrt 3		- %s"), *FDecimalMath::Sqrt(FDecimal(3)).ToString());
	UE_LOG(LogTemp, Warning, TEXT("TestDecimal step sqrt 64		- %s"), *FDecimalMath::Sqrt(FDecimal(64)).ToString());

	UE_LOG(LogTemp, Warning, TEXT("TestDecimal step constrary	- %s"), *(-FDecimal(64)).ToString());

	FDecimalVector TestVA, TestVB(1), TestVC(FDecimal(0.5f), FDecimal(2.2f), FDecimal(TEXT("111")));
	UE_LOG(LogTemp, Warning, TEXT("TestDecimal step FDecimalVector	- %s"), *TestVA.ToString());
	UE_LOG(LogTemp, Warning, TEXT("TestDecimal step FDecimalVector	- %s"), *TestVB.ToString());
	UE_LOG(LogTemp, Warning, TEXT("TestDecimal step FDecimalVector	- %s"), *TestVC.ToString());
	UE_LOG(LogTemp, Warning, TEXT("TestDecimal step FDecimalVector	- %s"), *(TestVB * 10).ToString());
	UE_LOG(LogTemp, Warning, TEXT("TestDecimal step FDecimalVector	- %s"), *(TestVC / 10).ToString(10));
	UE_LOG(LogTemp, Warning, TEXT("TestDecimal step FDecimalVector	- %s"), *(FDecimalVector::UpVector).ToString());
	UE_LOG(LogTemp, Warning, TEXT("TestDecimal step FDecimalVector	- %s"), *(FDecimalVector::DownVector).ToString());
	UE_LOG(LogTemp, Warning, TEXT("TestDecimal step FDecimalVector	- %s"), *(FDecimalVector::RightVector).ToString());
	UE_LOG(LogTemp, Warning, TEXT("TestDecimal step FDecimalVector	- %s"), *(FDecimalVector::LeftVector).ToString());
	UE_LOG(LogTemp, Warning, TEXT("TestDecimal step FDecimalVector	- %s"), *(FDecimalVector(2, 2, 2)).ToString());
	UE_LOG(LogTemp, Warning, TEXT("TestDecimal step FDecimalVector	- %s"), *(FDecimalVector(2, 2, 2).GetSafeNormal()).ToString());

	FDecimalVector TestVD;
	FString TestVDStr = TEXT("X=1231515615.32131 Y=98486484.8916451 Z=454135451684.46415416");
	if (!TestVD.InitFromString(TestVDStr))
	{
		UE_LOG(LogTemp, Warning, TEXT("TestDecimal step FDecimalVector init from string failed	- %s"), *TestVDStr);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("TestDecimal step FDecimalVector precision 2	- %s"), *TestVD.ToString());
		UE_LOG(LogTemp, Warning, TEXT("TestDecimal step FDecimalVector precision 20	- %s"), *TestVD.ToString(20));
	}

}
