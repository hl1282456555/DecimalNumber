#pragma once

#include "Decimal.h"
#include "DecimalVector.h"

class DECIMALNUMBER_API FDecimalMath
{
public:
	static FDecimal InvSqrt(const FDecimal& InVal);

	static FDecimal Abs(const FDecimal& InVal);
	
	static FDecimal Floor(const FDecimal& InVal);

	static FDecimal Ceil(const FDecimal& InVal);

	static FDecimal Sqrt(const FDecimal& InVal);

	static FORCEINLINE FDecimal Square(const FDecimal& InVal)
	{
		return InVal * InVal;
	}

	static FDecimal Sin(const FDecimal& InVal);

	static FDecimal Cos(const FDecimal& InVal);

	static FDecimal Acos(const FDecimal& InVal);

	static FDecimal Atan(const FDecimal& InVal);

	static FDecimal Atan2(const FDecimal& A, const FDecimal& B);

	template <typename Type, TEMPLATE_REQUIRES(ARITHMETIC_WITH_DECIMAL_CONDITION(Type))>
	static FDecimal Power(const FDecimal& InVal, Type InPow)
	{
		FDecimal Result;
		Result.InternalValue = boost::multiprecision::pow(InVal.InternalValue, InPow);
		return Result;
	}

	static void SindCos(FDecimal& ScalarSin, FDecimal& ScalarCos, const FDecimal& Value);

	static void SindCos(FDecimal& ScalarSin, FDecimal& ScalarCos, float Value);
	static void SindCos(FDecimal& ScalarSin, FDecimal& ScalarCos, double Value);

	static FDecimal UnwindDegrees(FDecimal A);

	static FORCEINLINE bool IsFinite(const FDecimal& InVal)
	{
		return 	boost::multiprecision::isfinite(InVal.InternalValue);
	}

	static FORCEINLINE bool IsNearlyZero(const FDecimal& Value, const FDecimal& ErrorTolerance = FDecimal(UE_DOUBLE_SMALL_NUMBER))
	{
		return Abs(Value) <= ErrorTolerance;
	}

	static FORCEINLINE FDecimal DegreesToRadians(FDecimal const& DegVal)
	{
		return DegVal * (FDecimal::ConstantPI / 180.0f);
	}

	template <typename T, TEMPLATE_REQUIRES(std::is_arithmetic<T>::value)>
	static FORCEINLINE FDecimal PlaneDot(const UE::Math::TPlane<T>& Plane, const FDecimalVector& Point)
	{
		return Plane.X * Point.X + Plane.Y * Point.Y + Plane.Z * Point.Z - Plane.W;
	}

	static FORCEINLINE FDecimal GridSnap(const FDecimal& Location, const FDecimal& Grid)
	{
		return (Grid == 0) ? Location : (Floor((Location + (Grid / 2)) / Grid) * Grid);
	}

	static FORCEINLINE FDecimal Min(const FDecimal& A, const FDecimal& B)
	{
		return (A <= B) ? A : B;
	}

	static FORCEINLINE FDecimal Max(const FDecimal& A, const FDecimal& B)
	{
		return (A >= B) ? A : B;
	}

	static FORCEINLINE FDecimal Min3(const FDecimal& A, const FDecimal& B, const FDecimal& C)
	{
		return Min(Min(A, B), C);
	}

	static FORCEINLINE FDecimal Max3(const FDecimal& A, const FDecimal& B, const FDecimal& C)
	{
		return Max(Max(A, B), C);
	}

	static FORCEINLINE FDecimal Clamp(const FDecimal& InVal, const FDecimal& Min, const FDecimal& Max)
	{
		return (InVal < Min) ? Min : (InVal < Max) ? InVal : Max;
	}
};