#pragma once
#include "CoreMinimal.h"
THIRD_PARTY_INCLUDES_START
#pragma push_macro("check")
#undef check
#include <boost/multiprecision/cpp_dec_float.hpp>
#pragma pop_macro("check")
THIRD_PARTY_INCLUDES_END
#include "Decimal.generated.h"

#define ARITHMETIC_WITH_DECIMAL_CONDITION(Type) std::conditional_t<std::is_arithmetic<##Type>::value || std::is_same<##Type, FDecimal>::value, std::true_type, std::false_type>::value

#define DEFINE_DECIMAL_OPERATOR_ADD(Type)	\
FORCEINLINE FDecimal operator+(Type InVal)				\
{											\
	return *this + FDecimal(InVal);			\
}

USTRUCT(BlueprintType)
struct DECIMALNUMBER_API FDecimal
{
	GENERATED_BODY()

	typedef boost::multiprecision::cpp_dec_float_50 InternalValueType;
	
public:
	static FDecimal ConstantPI;

	friend class FDecimalMath;
public:
	FDecimal();
	FDecimal(const InternalValueType& InVal);
	FDecimal(const FDecimal& InVal);
	FDecimal(const FString& InVal);
	FDecimal(int32 InVal);
	FDecimal(uint32 InVal);
	FDecimal(int64 InVal);
	FDecimal(uint64 InVal);
	FDecimal(float InVal);
	FDecimal(double InVal);

	FDecimal& operator=(const FDecimal& Other);
	FDecimal& operator=(const FString& Other);
	FDecimal& operator=(int32 Other);
	FDecimal& operator=(uint32 Other);
	FDecimal& operator=(int64 Other);
	FDecimal& operator=(uint64 Other);
	FDecimal& operator=(float Other);
	FDecimal& operator=(double Other);

	FDecimal operator+=(const FDecimal& Other);
	FDecimal operator+=(const FString& Other);
	FDecimal operator+=(int32 Other);
	FDecimal operator+=(uint32 Other);
	FDecimal operator+=(int64 Other);
	FDecimal operator+=(uint64 Other);
	FDecimal operator+=(float Other);
	FDecimal operator+=(double Other);

	FDecimal operator+(const FDecimal& Other)  const;
	FDecimal operator+(const FString& Other)  const;
	FDecimal operator+(int32 Other)  const;
	FDecimal operator+(uint32 Other)  const;
	FDecimal operator+(int64 Other)  const;
	FDecimal operator+(uint64 Other)  const;
	FDecimal operator+(float Other)  const;
	FDecimal operator+(double Other)  const;

	FDecimal operator-=(const FDecimal& Other);
	FDecimal operator-=(const FString& Other);
	FDecimal operator-=(int32 Other);
	FDecimal operator-=(uint32 Other);
	FDecimal operator-=(int64 Other);
	FDecimal operator-=(uint64 Other);
	FDecimal operator-=(float Other);
	FDecimal operator-=(double Other);

	FDecimal operator-(const FDecimal& Other)  const;
	FDecimal operator-(const FString& Other)  const;
	FDecimal operator-(int32 Other)  const;
	FDecimal operator-(uint32 Other)  const;
	FDecimal operator-(int64 Other)  const;
	FDecimal operator-(uint64 Other)  const;
	FDecimal operator-(float Other)  const;
	FDecimal operator-(double Other)  const;

	FDecimal operator*=(const FDecimal& Other);
	FDecimal operator*=(const FString& Other);
	FDecimal operator*=(int32 Other);
	FDecimal operator*=(uint32 Other);
	FDecimal operator*=(int64 Other);
	FDecimal operator*=(uint64 Other);
	FDecimal operator*=(float Other);
	FDecimal operator*=(double Other);

	FDecimal operator*(const FDecimal& Other)  const;
	FDecimal operator*(const FString& Other)  const;
	FDecimal operator*(int32 Other)  const;
	FDecimal operator*(uint32 Other)  const;
	FDecimal operator*(int64 Other)  const;
	FDecimal operator*(uint64 Other)  const;
	FDecimal operator*(float Other)  const;
	FDecimal operator*(double Other)  const;

	FDecimal operator/=(const FDecimal& Other);
	FDecimal operator/=(const FString& Other);
	FDecimal operator/=(int32 Other);
	FDecimal operator/=(uint32 Other);
	FDecimal operator/=(int64 Other);
	FDecimal operator/=(uint64 Other);
	FDecimal operator/=(float Other);
	FDecimal operator/=(double Other);

	FDecimal operator/(const FDecimal& Other)  const;
	FDecimal operator/(const FString& Other)  const;
	FDecimal operator/(int32 Other)  const;
	FDecimal operator/(uint32 Other)  const;
	FDecimal operator/(int64 Other)  const;
	FDecimal operator/(uint64 Other)  const;
	FDecimal operator/(float Other)  const;
	FDecimal operator/(double Other)  const;

	bool operator==(const FDecimal& Other)  const;
	bool operator!=(const FDecimal& Other)  const;
	bool operator>(const FDecimal& Other)  const;
	bool operator>=(const FDecimal& Other) const;
	bool operator<(const FDecimal& Other)  const;
	bool operator<=(const FDecimal& Other) const;

	FDecimal operator-() const;

	static bool FromString(const FString& InValue, FDecimal& OutValue);
	
	FString ToString(int32 Precision = 2) const;
	double ToDouble() const;

private:
	InternalValueType InternalValue;
};

#define DEFINE_BASIC_DECIMAL_ARITHMETIC(Operator, Type)							\
static FORCEINLINE FDecimal operator##Operator(Type A, const FDecimal& B)		\
{																				\
	return FDecimal(A) ##Operator B;											\
}

#define DEFINE_STRING_DECIMAL_ARITHMETIC(Operator)								\
static FDecimal operator##Operator(const FString& A, const FDecimal& B)			\
{																				\
	FDecimal Result;															\
	if (FDecimal::FromString(A, Result))										\
	{																			\
		return Result ##Operator B;												\
	}																			\
	return FDecimal();															\
}

// Addition operators for c++ basic type.
DEFINE_BASIC_DECIMAL_ARITHMETIC(+, int32);
DEFINE_BASIC_DECIMAL_ARITHMETIC(+, uint32);
DEFINE_BASIC_DECIMAL_ARITHMETIC(+, int64);
DEFINE_BASIC_DECIMAL_ARITHMETIC(+, uint64);
DEFINE_BASIC_DECIMAL_ARITHMETIC(+, float);
DEFINE_BASIC_DECIMAL_ARITHMETIC(+, double);

// Subtraction operators for c++ basic type.
DEFINE_BASIC_DECIMAL_ARITHMETIC(-, int32);
DEFINE_BASIC_DECIMAL_ARITHMETIC(-, uint32);
DEFINE_BASIC_DECIMAL_ARITHMETIC(-, int64);
DEFINE_BASIC_DECIMAL_ARITHMETIC(-, uint64);
DEFINE_BASIC_DECIMAL_ARITHMETIC(-, float);
DEFINE_BASIC_DECIMAL_ARITHMETIC(-, double);

// Multiplication operators for c++ basic type.
DEFINE_BASIC_DECIMAL_ARITHMETIC(*, int32);
DEFINE_BASIC_DECIMAL_ARITHMETIC(*, uint32);
DEFINE_BASIC_DECIMAL_ARITHMETIC(*, int64);
DEFINE_BASIC_DECIMAL_ARITHMETIC(*, uint64);
DEFINE_BASIC_DECIMAL_ARITHMETIC(*, float);
DEFINE_BASIC_DECIMAL_ARITHMETIC(*, double);

// Dividsion operators for c++ basic type.
DEFINE_BASIC_DECIMAL_ARITHMETIC(/, int32);
DEFINE_BASIC_DECIMAL_ARITHMETIC(/, uint32);
DEFINE_BASIC_DECIMAL_ARITHMETIC(/, int64);
DEFINE_BASIC_DECIMAL_ARITHMETIC(/, uint64);
DEFINE_BASIC_DECIMAL_ARITHMETIC(/, float);
DEFINE_BASIC_DECIMAL_ARITHMETIC(/, double);

// Arithmetic for string.
DEFINE_STRING_DECIMAL_ARITHMETIC(+);
DEFINE_STRING_DECIMAL_ARITHMETIC(-);
DEFINE_STRING_DECIMAL_ARITHMETIC(*);
DEFINE_STRING_DECIMAL_ARITHMETIC(/);