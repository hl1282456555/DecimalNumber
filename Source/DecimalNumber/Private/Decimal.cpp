#include "Decimal.h"
#include "Internationalization/FastDecimalFormat.h"

namespace DecimalHelper
{
	void ConvertValueToString(double InValue, FString& OutValue)
	{
		FNumberFormattingOptions Options;
		Options.SetAlwaysSign(false);
		Options.SetUseGrouping(false);
		Options.SetRoundingMode(ERoundingMode::HalfToEven);
		Options.SetMaximumFractionalDigits(4);

		FastDecimalFormat::NumberToString(InValue, FastDecimalFormat::GetCultureAgnosticFormattingRules(), Options, OutValue);
	}

	void ConvertStringToValue(const FString& InValue, double& OutValue)
	{
		FNumberParsingOptions Options;
		Options.SetInsideLimits(true);
		Options.SetUseClamping(false);
		Options.SetUseGrouping(false);

		FastDecimalFormat::StringToNumber(*InValue, FastDecimalFormat::GetCultureAgnosticFormattingRules(), Options, OutValue);
	}
}

FDecimal FDecimal::ConstantPI = FDecimal(boost::math::constants::pi<InternalValueType>());

FDecimal::FDecimal()
{
}

FDecimal::FDecimal(const InternalValueType& InVal)
	: InternalValue(InVal)
{
}

FDecimal::FDecimal(const FDecimal& InVal)
	: InternalValue(InVal.InternalValue)
{
}

FDecimal::FDecimal(const FString& InVal)
{
	*this = InVal;
}

FDecimal::FDecimal(int32 InVal)
	: InternalValue(InVal)
{
}

FDecimal::FDecimal(uint32 InVal)
	: InternalValue(InVal)
{
}

FDecimal::FDecimal(int64 InVal)
	: InternalValue(InVal)
{
}

FDecimal::FDecimal(uint64 InVal)
	: InternalValue(InVal)
{
}

FDecimal::FDecimal(float InVal)
{
	*this = InVal;
}

FDecimal::FDecimal(double InVal)
{
	*this = InVal;
}

FDecimal& FDecimal::operator=(const FDecimal& Other)
{
	InternalValue = Other.InternalValue;
	return *this;
}

FDecimal& FDecimal::operator=(const FString& Other)
{
	if (Other.IsNumeric())
	{
		InternalValue = InternalValueType(TCHAR_TO_ANSI(*Other));
	}

	return *this;
}

FDecimal& FDecimal::operator=(int32 Other)
{
	InternalValue = Other;
	return *this;
}

FDecimal& FDecimal::operator=(uint32 Other)
{
	InternalValue = Other;
	return *this;
}

FDecimal& FDecimal::operator=(int64 Other)
{
	InternalValue = Other;
	return *this;
}

FDecimal& FDecimal::operator=(uint64 Other)
{
	InternalValue = Other;
	return *this;
}

FDecimal& FDecimal::operator=(float Other)
{
	FString ConvertedStr;
	DecimalHelper::ConvertValueToString(Other, ConvertedStr);
	InternalValue = InternalValueType(TCHAR_TO_ANSI(*ConvertedStr));

	return *this;
}

FDecimal& FDecimal::operator=(double Other)
{
	FString ConvertedStr;
	DecimalHelper::ConvertValueToString(Other, ConvertedStr);
	InternalValue = InternalValueType(TCHAR_TO_ANSI(*ConvertedStr));

	return *this;
}

FDecimal FDecimal::operator+=(const FDecimal& Other)
{
	InternalValue += Other.InternalValue;
	return *this;
}

FDecimal FDecimal::operator+=(const FString& Other)
{
	return *this += FDecimal(Other);
}

FDecimal FDecimal::operator+=(int32 Other)
{
	return *this += FDecimal(Other);
}

FDecimal FDecimal::operator+=(uint32 Other)
{
	return *this += FDecimal(Other);
}

FDecimal FDecimal::operator+=(int64 Other)
{
	return *this += FDecimal(Other);
}

FDecimal FDecimal::operator+=(uint64 Other)
{
	return *this += FDecimal(Other);
}

FDecimal FDecimal::operator+=(float Other)
{
	return *this += FDecimal(Other);
}

FDecimal FDecimal::operator+=(double Other)
{
	return *this += FDecimal(Other);
}

FDecimal FDecimal::operator+(const FDecimal& Other) const
{
	FDecimal Result(*this);
	Result.InternalValue += Other.InternalValue;

	return Result;
}

FDecimal FDecimal::operator+(const FString& Other) const
{
	FDecimal Result;
	if (!FDecimal::FromString(Other, Result))
	{
		return FDecimal();
	}

	Result.InternalValue += InternalValue;

	return Result;
}

FDecimal FDecimal::operator+(int32 Other) const
{
	return *this + FDecimal(Other);
}

FDecimal FDecimal::operator+(uint32 Other) const
{
	return *this + FDecimal(Other);
}

FDecimal FDecimal::operator+(int64 Other) const
{
	return *this + FDecimal(Other);
}

FDecimal FDecimal::operator+(uint64 Other) const
{
	return *this + FDecimal(Other);
}

FDecimal FDecimal::operator+(float Other) const
{
	return *this + FDecimal(Other);
}

FDecimal FDecimal::operator+(double Other) const
{
	return *this + FDecimal(Other);
}

FDecimal FDecimal::operator-=(const FDecimal& Other)
{
	InternalValue -= Other.InternalValue;
	return *this;
}

FDecimal FDecimal::operator-=(const FString& Other)
{
	return *this -= FDecimal(Other);
}

FDecimal FDecimal::operator-=(int32 Other)
{
	return *this -= FDecimal(Other);
}

FDecimal FDecimal::operator-=(uint32 Other)
{
	return *this -= FDecimal(Other);
}

FDecimal FDecimal::operator-=(int64 Other)
{
	return *this -= FDecimal(Other);
}

FDecimal FDecimal::operator-=(uint64 Other)
{
	return *this -= FDecimal(Other);
}

FDecimal FDecimal::operator-=(float Other)
{
	return *this -= FDecimal(Other);
}

FDecimal FDecimal::operator-=(double Other)
{
	return *this -= FDecimal(Other);
}

FDecimal FDecimal::operator-(const FDecimal& Other) const
{
	FDecimal Result(*this);
	Result.InternalValue -= Other.InternalValue;
	return Result;
}

FDecimal FDecimal::operator-(const FString& Other) const
{
	FDecimal Result;
	if (!FDecimal::FromString(Other, Result))
	{
		return FDecimal();
	}

	Result.InternalValue -= InternalValue;

	return Result;
}

FDecimal FDecimal::operator-(int32 Other) const
{
	return *this - FDecimal(Other);
}

FDecimal FDecimal::operator-(uint32 Other) const
{
	return *this - FDecimal(Other);
}

FDecimal FDecimal::operator-(int64 Other) const
{
	return *this - FDecimal(Other);
}

FDecimal FDecimal::operator-(uint64 Other) const
{
	return *this - FDecimal(Other);
}

FDecimal FDecimal::operator-(float Other) const
{
	return *this - FDecimal(Other);
}

FDecimal FDecimal::operator-(double Other) const
{
	return *this - FDecimal(Other);
}

FDecimal FDecimal::operator*=(const FDecimal& Other)
{
	InternalValue *= Other.InternalValue;
	return *this;
}

FDecimal FDecimal::operator*=(const FString& Other)
{
	return *this *= FDecimal(Other);
}

FDecimal FDecimal::operator*=(int32 Other)
{
	return *this *= FDecimal(Other);
}

FDecimal FDecimal::operator*=(uint32 Other)
{
	return *this *= FDecimal(Other);
}

FDecimal FDecimal::operator*=(int64 Other)
{
	return *this *= FDecimal(Other);
}

FDecimal FDecimal::operator*=(uint64 Other)
{
	return *this *= FDecimal(Other);
}

FDecimal FDecimal::operator*=(float Other)
{
	return *this *= FDecimal(Other);
}

FDecimal FDecimal::operator*=(double Other)
{
	return *this *= FDecimal(Other);
}

FDecimal FDecimal::operator*(const FDecimal& Other) const
{
	FDecimal Result(*this);
	Result.InternalValue *= Other.InternalValue;
	return Result;
}

FDecimal FDecimal::operator*(const FString& Other) const
{
	FDecimal Result;
	if (!FDecimal::FromString(Other, Result))
	{
		return FDecimal();
	}

	Result.InternalValue *= InternalValue;

	return Result;
}

FDecimal FDecimal::operator*(int32 Other) const
{
	return *this * FDecimal(Other);
}

FDecimal FDecimal::operator*(uint32 Other) const
{
	return *this * FDecimal(Other);
}

FDecimal FDecimal::operator*(int64 Other) const
{
	return *this * FDecimal(Other);
}

FDecimal FDecimal::operator*(uint64 Other) const
{
	return *this * FDecimal(Other);
}

FDecimal FDecimal::operator*(float Other) const
{
	return *this * FDecimal(Other);
}

FDecimal FDecimal::operator*(double Other) const
{
	return *this * FDecimal(Other);
}

FDecimal FDecimal::operator/=(const FDecimal& Other)
{
	InternalValue /= Other.InternalValue;
	return *this;
}

FDecimal FDecimal::operator/=(const FString& Other)
{
	return *this /= FDecimal(Other);
}

FDecimal FDecimal::operator/=(int32 Other)
{
	return *this /= FDecimal(Other);
}

FDecimal FDecimal::operator/=(uint32 Other)
{
	return *this /= FDecimal(Other);
}

FDecimal FDecimal::operator/=(int64 Other)
{
	return *this /= FDecimal(Other);
}

FDecimal FDecimal::operator/=(uint64 Other)
{
	return *this /= FDecimal(Other);
}

FDecimal FDecimal::operator/=(float Other)
{
	return *this /= FDecimal(Other);
}

FDecimal FDecimal::operator/=(double Other)
{
	return *this /= FDecimal(Other);
}

FDecimal FDecimal::operator/(const FDecimal& Other) const
{
	FDecimal Result(*this);
	Result.InternalValue /= Other.InternalValue;
	return Result;
}

FDecimal FDecimal::operator/(const FString& Other) const
{
	FDecimal Result;
	if (!FDecimal::FromString(Other, Result))
	{
		return FDecimal();
	}

	Result.InternalValue /= InternalValue;

	return Result;
}

FDecimal FDecimal::operator/(int32 Other) const
{
	return *this / FDecimal(Other);
}

FDecimal FDecimal::operator/(uint32 Other) const
{
	return *this / FDecimal(Other);
}

FDecimal FDecimal::operator/(int64 Other) const
{
	return *this / FDecimal(Other);
}

FDecimal FDecimal::operator/(uint64 Other) const
{
	return *this / FDecimal(Other);
}

FDecimal FDecimal::operator/(float Other) const
{
	return *this / FDecimal(Other);
}

FDecimal FDecimal::operator/(double Other) const
{
	return *this / FDecimal(Other);
}

bool FDecimal::operator==(const FDecimal& Other)  const
{
	return InternalValue == Other.InternalValue;
}

bool FDecimal::operator!=(const FDecimal& Other)  const
{
	return InternalValue != Other.InternalValue;
}

bool FDecimal::operator>(const FDecimal& Other)  const
{
	return InternalValue > Other.InternalValue;
}

bool FDecimal::operator>=(const FDecimal& Other) const
{
	return InternalValue >= Other.InternalValue;
}

bool FDecimal::operator<(const FDecimal& Other)  const
{
	return InternalValue < Other.InternalValue;
}

bool FDecimal::operator<=(const FDecimal& Other) const
{
	return InternalValue <= Other.InternalValue;
}

FDecimal FDecimal::operator-() const
{
	FDecimal Result(*this);
	Result.InternalValue *= -1;
	return Result;
}

bool FDecimal::FromString(const FString& InValue, FDecimal& OutValue)
{
	if (!InValue.IsNumeric())
	{
		return false;
	}

	OutValue = InValue;
	return true;
}

FString FDecimal::ToString(int32 Precision) const
{
	return FString(InternalValue.str(Precision, std::ios::fixed).c_str());
}

double FDecimal::ToDouble() const
{
	double Result;
	DecimalHelper::ConvertStringToValue(ToString(), Result);
	return Result;
}
