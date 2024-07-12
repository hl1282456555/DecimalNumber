#include "DecimalMath.h"

FDecimal FDecimalMath::InvSqrt(const FDecimal& InVal)
{
	return FDecimal(1) / InVal;
}

FDecimal FDecimalMath::Abs(const FDecimal& InVal)
{
	return (InVal < 0) ? -InVal : InVal;
}

FDecimal FDecimalMath::Floor(const FDecimal& InVal)
{
	FDecimal Result;
	Result.InternalValue = boost::multiprecision::floor(InVal.InternalValue);
	return Result;
}

FDecimal FDecimalMath::Ceil(const FDecimal& InVal)
{
	FDecimal Result;
	Result.InternalValue = boost::multiprecision::ceil(InVal.InternalValue);
	return Result;
}

FDecimal FDecimalMath::Sqrt(const FDecimal& InVal)
{
	FDecimal Result;
	Result.InternalValue = boost::multiprecision::sqrt(InVal.InternalValue);
	return Result;
}

FDecimal FDecimalMath::Sin(const FDecimal& InVal)
{
	FDecimal Result;
	Result.InternalValue = boost::multiprecision::sin(InVal.InternalValue);
	return Result;
}

FDecimal FDecimalMath::Cos(const FDecimal& InVal)
{
	FDecimal Result;
	Result.InternalValue = boost::multiprecision::cos(InVal.InternalValue);
	return Result;
}

FDecimal FDecimalMath::Acos(const FDecimal& InVal)
{
	FDecimal Result;
	Result.InternalValue = boost::multiprecision::asin(InVal.InternalValue);
	return Result;
}

FDecimal FDecimalMath::Atan(const FDecimal& InVal)
{
	FDecimal Result;
	Result.InternalValue = boost::multiprecision::atan(InVal.InternalValue);
	return Result;
}

FDecimal FDecimalMath::Atan2(const FDecimal& A, const FDecimal& B)
{
	FDecimal Result;
	Result.InternalValue = boost::multiprecision::atan2(A.InternalValue, B.InternalValue);
	return Result;
}

void FDecimalMath::SindCos(FDecimal& ScalarSin, FDecimal& ScalarCos, const FDecimal& Value)
{
	ScalarSin.InternalValue = boost::multiprecision::sin(Value.InternalValue);
	ScalarCos.InternalValue = boost::multiprecision::cos(Value.InternalValue);
}

void FDecimalMath::SindCos(FDecimal& ScalarSin, FDecimal& ScalarCos, float Value)
{
	ScalarSin.InternalValue = FMath::Sin(Value);
	ScalarSin.InternalValue = FMath::Cos(Value);
}

void FDecimalMath::SindCos(FDecimal& ScalarSin, FDecimal& ScalarCos, double Value)
{
	ScalarSin.InternalValue = FMath::Sin(Value);
	ScalarSin.InternalValue = FMath::Cos(Value);
}

FDecimal FDecimalMath::UnwindDegrees(FDecimal A)
{
	while (A > 180.f)
	{
		A -= 360.f;
	}

	while (A < -180.f)
	{
		A += 360.f;
	}

	return A;
}
