// Fill out your copyright notice in the Description page of Project Settings.


#include "DecimalVector.h"

#include "DecimalMath.h"

const FDecimalVector FDecimalVector::ZeroVector		= FDecimalVector(0);
const FDecimalVector FDecimalVector::OneVector		= FDecimalVector(1);
const FDecimalVector FDecimalVector::UpVector		= FDecimalVector(0, 0, 1);
const FDecimalVector FDecimalVector::DownVector		= FDecimalVector(0, 0, -1);
const FDecimalVector FDecimalVector::ForwardVector	= FDecimalVector(1, 0, 0);
const FDecimalVector FDecimalVector::BackwardVector	= FDecimalVector(-1, 0, 0);
const FDecimalVector FDecimalVector::RightVector	= FDecimalVector(0, 1, 0);
const FDecimalVector FDecimalVector::LeftVector		= FDecimalVector(0, -1, 0);
const FDecimalVector FDecimalVector::XAxisVector	= FDecimalVector(1, 0, 0);
const FDecimalVector FDecimalVector::YAxisVector	= FDecimalVector(0, 1, 0);
const FDecimalVector FDecimalVector::ZAxisVector	= FDecimalVector(0, 0, 1);

FDecimalVector::FDecimalVector()
	: X(0), Y(0), Z(0)
{
}

FDecimalVector::FDecimalVector(const FDecimal& InVal)
	: X(InVal), Y(InVal), Z(InVal)
{
}

FDecimalVector::FDecimalVector(const FDecimal& InX, const FDecimal& InY, const FDecimal& InZ)
	: X(InX), Y(InY), Z(InZ)
{
}

FDecimalVector::FDecimalVector(const FDecimalVector& V)
	: X(V.X), Y(V.Y), Z(V.Z)
{
}

FDecimalVector::FDecimalVector(const FLinearColor& InColor)
	: X(InColor.R), Y(InColor.G), Z(InColor.B)
{
}

FDecimalVector::FDecimalVector(EForceInit)
	: X(0), Y(0), Z(0)
{
}

FDecimalVector& FDecimalVector::operator=(const FDecimalVector& V)
{
	X = V.X; Y = V.Y; Z = V.Z;
	return *this;
}

FDecimalVector FDecimalVector::operator^(const FDecimalVector& V) const
{
	return FDecimalVector
	(
		Y * V.Z - Z * V.Y,
		Z * V.X - X * V.Z,
		X * V.Y - Y * V.X
	);
}

FDecimalVector FDecimalVector::Cross(const FDecimalVector& V) const
{
	return *this ^ V;
}

FDecimalVector FDecimalVector::CrossProduct(const FDecimalVector& A, const FDecimalVector& B)
{
	return A ^ B;
}

FDecimal FDecimalVector::operator|(const FDecimalVector& V) const
{
	return X * V.X + Y * V.Y + Z * V.Z;
}

FDecimal FDecimalVector::Dot(const FDecimalVector& V) const
{
	return *this | V;
}

FDecimal FDecimalVector::DotProduct(const FDecimalVector& A, const FDecimalVector& B)
{
	return A | B;
}

FDecimalVector FDecimalVector::operator+(const FDecimalVector& V) const
{
	return FDecimalVector(X + V.X, Y + V.Y, Z + V.Z);
}

FDecimalVector FDecimalVector::operator-(const FDecimalVector& V) const
{
	return FDecimalVector(X - V.X, Y - V.Y, Z - V.Z);
}

FDecimalVector FDecimalVector::operator*(const FDecimalVector& V) const
{
	return FDecimalVector(X * V.X, Y * V.Y, Z * V.Z);
}

FDecimalVector FDecimalVector::operator/(const FDecimalVector& V) const
{
	return FDecimalVector(X / V.X, Y / V.Y, Z / V.Z);
}

bool FDecimalVector::operator==(const FDecimalVector& V) const
{
	return X == V.X && Y == V.Y && Z == V.Z;
}

bool FDecimalVector::operator!=(const FDecimalVector& V) const
{
	return X != V.X || Y != V.Y || Z != V.Z;
}

bool FDecimalVector::Equals(const FDecimalVector& V, const FDecimal& Tolerance) const
{
	return FDecimalMath::Abs(X - V.X) <= Tolerance && FDecimalMath::Abs(Y - V.Y) <= Tolerance && FDecimalMath::Abs(Z - V.Z) <= Tolerance;
}

bool FDecimalVector::AllComponentsEqual(const FDecimal& Tolerance) const
{
	return FDecimalMath::Abs(X - Y) <= Tolerance && FDecimalMath::Abs(X - Z) <= Tolerance && FDecimalMath::Abs(Y - Z) <= Tolerance;
}

FDecimalVector FDecimalVector::operator-() const
{
	return FDecimalVector(-X, -Y, -Z);
}

FDecimalVector FDecimalVector::operator+=(const FDecimalVector& V)
{
	X += V.X; Y += V.Y; Z += V.Z;
	return *this;
}

FDecimalVector FDecimalVector::operator-=(const FDecimalVector& V)
{
	X -= V.X; Y -= V.Y; Z -= V.Z;
	return *this;
}

FDecimalVector FDecimalVector::operator*=(const FDecimalVector& V)
{
	X *= V.X; Y *= V.Y; Z *= V.Z;
	return *this;
}

FDecimalVector FDecimalVector::operator/=(const FDecimalVector& V)
{
	X /= V.X; Y /= V.Y; Z /= V.Z;
	return *this;
}

FDecimal& FDecimalVector::operator[](int32 Index)
{
	checkSlow(Index >= 0 && Index < 3);
	
PRAGMA_DISABLE_DEPRECATION_WARNINGS
		return XYZ[Index];
PRAGMA_ENABLE_DEPRECATION_WARNINGS
}

FDecimal FDecimalVector::operator[](int32 Index) const
{
	checkSlow(Index >= 0 && Index < 3);

PRAGMA_DISABLE_DEPRECATION_WARNINGS
		return XYZ[Index];
PRAGMA_ENABLE_DEPRECATION_WARNINGS
}

FDecimal& FDecimalVector::Component(int32 Index)
{
PRAGMA_DISABLE_DEPRECATION_WARNINGS
		return XYZ[Index];
PRAGMA_ENABLE_DEPRECATION_WARNINGS
}

FDecimal FDecimalVector::Component(int32 Index) const
{
PRAGMA_DISABLE_DEPRECATION_WARNINGS
		return XYZ[Index];
PRAGMA_ENABLE_DEPRECATION_WARNINGS
}

FDecimal FDecimalVector::GetComponentForAxis(EAxis::Type Axis) const
{
	switch (Axis)
	{
	case EAxis::X:
		return X;
	case EAxis::Y:
		return Y;
	case EAxis::Z:
		return Z;
	default:
		return 0.f;
	}
}

void FDecimalVector::SetComponentForAxis(EAxis::Type Axis, const FDecimal& Component)
{
	switch (Axis)
	{
	case EAxis::X:
		X = Component;
		break;
	case EAxis::Y:
		Y = Component;
		break;
	case EAxis::Z:
		Z = Component;
		break;
	}
}

void FDecimalVector::Set(const FDecimal& InX, const FDecimal& InY, const FDecimal& InZ)
{
	X = InX;
	Y = InY;
	Z = InZ;
}

FDecimal FDecimalVector::GetMax() const
{
	return FDecimalMath::Max(FDecimalMath::Max(X, Y), Z);
}

FDecimal FDecimalVector::GetAbsMax() const
{
	return FDecimalMath::Max(FDecimalMath::Max(FDecimalMath::Abs(X), FDecimalMath::Abs(Y)), FDecimalMath::Abs(Z));
}

FDecimal FDecimalVector::GetMin() const
{
	return FDecimalMath::Min(FDecimalMath::Min(X, Y), Z);
}

FDecimal FDecimalVector::GetAbsMin() const
{
	return FDecimalMath::Min(FDecimalMath::Min(FDecimalMath::Abs(X), FDecimalMath::Abs(Y)), FDecimalMath::Abs(Z));
}

FDecimalVector FDecimalVector::ComponentMin(const FDecimalVector& Other) const
{
	return FDecimalVector(FDecimalMath::Min(X, Other.X), FDecimalMath::Min(Y, Other.Y), FDecimalMath::Min(Z, Other.Z));
}

FDecimalVector FDecimalVector::ComponentMax(const FDecimalVector& Other) const
{
	return FDecimalVector(FDecimalMath::Max(X, Other.X), FDecimalMath::Max(Y, Other.Y), FDecimalMath::Max(Z, Other.Z));
}

FDecimalVector FDecimalVector::GetAbs() const
{
	return FDecimalVector(FDecimalMath::Abs(X), FDecimalMath::Abs(Y), FDecimalMath::Abs(Z));
}

FDecimal FDecimalVector::Size() const
{
	return FDecimalMath::Sqrt(X * X + Y * Y + Z * Z);
}

FDecimal FDecimalVector::Length() const
{
	return Size();
}

FDecimal FDecimalVector::SizeSquared() const
{
	return X * X + Y * Y + Z * Z;
}

FDecimal FDecimalVector::SquaredLength() const
{
	return SizeSquared();
}

FDecimal FDecimalVector::Size2D() const
{
	return FDecimalMath::Sqrt(X * X + Y * Y);
}

FDecimal FDecimalVector::SizeSquared2D() const
{
	return X * X + Y * Y;
}

bool FDecimalVector::IsNearlyZero(const FDecimal& Tolerance) const
{
	return
		FDecimalMath::Abs(X) <= Tolerance
		&& FDecimalMath::Abs(Y) <= Tolerance
		&& FDecimalMath::Abs(Z) <= Tolerance;
}

bool FDecimalVector::IsZero() const
{
	return X == 0.f && Y == 0.f && Z == 0.f;
}

bool FDecimalVector::IsUnit(const FDecimal& LengthSquaredTolerance) const
{
	return FDecimalMath::Abs(1.0f - SizeSquared()) < LengthSquaredTolerance;
}

bool FDecimalVector::IsNormalized() const
{
	return (FDecimalMath::Abs(1.f - SizeSquared()) < UE_THRESH_VECTOR_NORMALIZED);
}

bool FDecimalVector::Normalize(const FDecimal& Tolerance)
{
	const FDecimal SquareSum = X * X + Y * Y + Z * Z;
	if (SquareSum > Tolerance)
	{
		const FDecimal Scale = FDecimalMath::InvSqrt(SquareSum);
		X *= Scale; Y *= Scale; Z *= Scale;
		return true;
	}
	return false;
}

FDecimalVector FDecimalVector::GetUnsafeNormal() const
{
	const FDecimal Scale = FDecimalMath::InvSqrt(X * X + Y * Y + Z * Z);
	return FDecimalVector(X * Scale, Y * Scale, Z * Scale);
}

FDecimalVector FDecimalVector::GetSafeNormal(const FDecimal& Tolerance, const FDecimalVector& ResultIfZero) const
{
	const FDecimal SquareSum = X * X + Y * Y + Z * Z;

	// Not sure if it's safe to add tolerance in there. Might introduce too many errors
	if (SquareSum == 1.f)
	{
		return *this;
	}
	else if (SquareSum < Tolerance)
	{
		return ResultIfZero;
	}
	const FDecimal Scale = FDecimalMath::InvSqrt(SquareSum);
	return FDecimalVector(X * Scale, Y * Scale, Z * Scale);
}

FDecimalVector FDecimalVector::GetSafeNormal2D(const FDecimal& Tolerance, const FDecimalVector& ResultIfZero) const
{
	const FDecimal SquareSum = X * X + Y * Y;

	// Not sure if it's safe to add tolerance in there. Might introduce too many errors
	if (SquareSum == 1.f)
	{
		if (Z == 0.f)
		{
			return *this;
		}
		else
		{
			return FDecimalVector(X, Y, 0.f);
		}
	}
	else if (SquareSum < Tolerance)
	{
		return ResultIfZero;
	}

	const FDecimal Scale = FDecimalMath::InvSqrt(SquareSum);
	return FDecimalVector(X * Scale, Y * Scale, 0.f);
}

void FDecimalVector::ToDirectionAndLength(FDecimalVector& OutDir, double& OutLength) const
{
	OutLength = Size().ToDouble();
	if (OutLength > UE_SMALL_NUMBER)
	{
		FDecimal OneOverLength = FDecimal(1.0 / OutLength);
		OutDir = FDecimalVector(X * OneOverLength, Y * OneOverLength, Z * OneOverLength);
	}
	else
	{
		OutDir = ZeroVector;
	}
}

void FDecimalVector::ToDirectionAndLength(FDecimalVector& OutDir, float& OutLength) const
{
	OutLength = (float)Size().ToDouble();
	if (OutLength > UE_SMALL_NUMBER)
	{
		float OneOverLength = 1.0f / OutLength;
		OutDir = FDecimalVector(X * OneOverLength, Y * OneOverLength, Z * OneOverLength);
	}
	else
	{
		OutDir = ZeroVector;
	}
}

FDecimalVector FDecimalVector::GetSignVector() const
{
	return FDecimalVector
		(
			X >= 0 ? 1 : -1,
			Y >= 0 ? 1 : -1,
			Z >= 0 ? 1 : -1
		);
}

FDecimalVector FDecimalVector::Projection() const
{
	const FDecimal RZ = 1.f / Z;
	return FDecimalVector(X * RZ, Y * RZ, 1);
}

FDecimalVector FDecimalVector::GetUnsafeNormal2D() const
{
	const FDecimal Scale = FDecimalMath::InvSqrt(X * X + Y * Y);
	return FDecimalVector(X * Scale, Y * Scale, 0);
}

FDecimalVector FDecimalVector::GridSnap(const FDecimal& GridSz) const
{
	return FDecimalVector(FDecimalMath::GridSnap(X, GridSz), FDecimalMath::GridSnap(Y, GridSz), FDecimalMath::GridSnap(Z, GridSz));
}

FDecimalVector FDecimalVector::BoundToCube(const FDecimal& Radius) const
{
	return FDecimalVector
	(
		FDecimalMath::Clamp(X, -Radius, Radius),
		FDecimalMath::Clamp(Y, -Radius, Radius),
		FDecimalMath::Clamp(Z, -Radius, Radius)
	);
}

FDecimalVector FDecimalVector::BoundToBox(const FDecimalVector& Min, const FDecimalVector& Max) const
{
	return FDecimalVector
	(
		FDecimalMath::Clamp(X, Min.X, Max.X),
		FDecimalMath::Clamp(Y, Min.Y, Max.Y),
		FDecimalMath::Clamp(Z, Min.Z, Max.Z)
	);
}

FDecimalVector FDecimalVector::GetClampedToSize(const FDecimal& Min, const FDecimal& Max) const
{
	FDecimal VecSize = Size();
	const FDecimalVector VecDir = (VecSize > UE_SMALL_NUMBER) ? (*this / VecSize) : ZeroVector;

	VecSize = FMath::Clamp(VecSize, Min, Max);

	return VecSize * VecDir;
}

FDecimalVector FDecimalVector::GetClampedToSize2D(const FDecimal& Min, const FDecimal& Max) const
{
	FDecimal VecSize2D = Size2D();
	const FDecimalVector VecDir = (VecSize2D > UE_SMALL_NUMBER) ? (*this / VecSize2D) : ZeroVector;

	VecSize2D = FDecimalMath::Clamp(VecSize2D, Min, Max);

	return FDecimalVector(VecSize2D * VecDir.X, VecSize2D * VecDir.Y, Z);
}

FDecimalVector FDecimalVector::GetClampedToMaxSize(const FDecimal& MaxSize) const
{
	if (MaxSize < UE_KINDA_SMALL_NUMBER)
	{
		return ZeroVector;
	}

	const FDecimal VSq = SizeSquared();
	if (VSq > FDecimalMath::Square(MaxSize))
	{
		const FDecimal Scale = MaxSize * FDecimalMath::InvSqrt(VSq);
		return FDecimalVector(X * Scale, Y * Scale, Z * Scale);
	}
	else
	{
		return *this;
	}
}

FDecimalVector FDecimalVector::GetClampedToMaxSize2D(const FDecimal& MaxSize) const
{
	if (MaxSize < UE_KINDA_SMALL_NUMBER)
	{
		return FDecimalVector(0.f, 0.f, Z);
	}

	const FDecimal VSq2D = SizeSquared2D();
	if (VSq2D > FDecimalMath::Square(MaxSize))
	{
		const FDecimal Scale = MaxSize * FDecimalMath::InvSqrt(VSq2D);
		return FDecimalVector(X * Scale, Y * Scale, Z);
	}
	else
	{
		return *this;
	}
}

void FDecimalVector::AddBounded(const FDecimalVector& V, const FDecimal& Radius)
{
	*this = (*this + V).BoundToCube(Radius);
}

FDecimalVector FDecimalVector::Reciprocal() const
{
	FDecimalVector RecVector;
	if (X != 0.f)
	{
		RecVector.X = 1.f / X;
	}
	else
	{
		RecVector.X = UE_BIG_NUMBER;
	}
	if (Y != 0.f)
	{
		RecVector.Y = 1.f / Y;
	}
	else
	{
		RecVector.Y = UE_BIG_NUMBER;
	}
	if (Z != 0.f)
	{
		RecVector.Z = 1.f / Z;
	}
	else
	{
		RecVector.Z = UE_BIG_NUMBER;
	}

	return RecVector;
}

bool FDecimalVector::IsUniform(const FDecimal& Tolerance) const
{
	return AllComponentsEqual(Tolerance);
}

FDecimalVector FDecimalVector::MirrorByVector(const FDecimalVector& MirrorNormal) const
{
	return *this - MirrorNormal * (2.f * (*this | MirrorNormal));
}

FDecimal FDecimalVector::CosineAngle2D(FDecimalVector B) const
{
	FDecimalVector A(*this);
	A.Z = 0.0f;
	B.Z = 0.0f;
	A.Normalize();
	B.Normalize();
	return A | B;
}

FDecimalVector FDecimalVector::ProjectOnTo(const FDecimalVector& A) const
{
	return (A * ((*this | A) / (A | A)));
}

FDecimalVector FDecimalVector::ProjectOnToNormal(const FDecimalVector& Normal) const
{
	return (Normal * (*this | Normal));
}

void FDecimalVector::FindBestAxisVectors(FDecimalVector& Axis1, FDecimalVector& Axis2) const
{
	const FDecimal NX = FDecimalMath::Abs(X);
	const FDecimal NY = FDecimalMath::Abs(Y);
	const FDecimal NZ = FDecimalMath::Abs(Z);

	// Find best basis vectors.
	if (NZ > NX && NZ > NY)	Axis1 = FDecimalVector(1, 0, 0);
	else					Axis1 = FDecimalVector(0, 0, 1);

	FDecimalVector Tmp = Axis1 - *this * (Axis1 | *this);
	Axis1 = Tmp.GetSafeNormal();
	Axis2 = Axis1 ^ *this;
}

void FDecimalVector::UnwindEuler()
{
	X = FDecimalMath::UnwindDegrees(X);
	Y = FDecimalMath::UnwindDegrees(Y);
	Z = FDecimalMath::UnwindDegrees(Z);
}

bool FDecimalVector::ContainsNaN() const
{
	return (!FDecimalMath::IsFinite(X) ||
		!FDecimalMath::IsFinite(Y) ||
		!FDecimalMath::IsFinite(Z));
}

FString FDecimalVector::ToString(int32 Precision) const
{
	return FString::Printf(TEXT("X=%s Y=%s Z=%s"), *X.ToString(Precision), *Y.ToString(Precision), *Z.ToString(Precision));
}

FText FDecimalVector::ToText() const
{
	FFormatNamedArguments Args;
	Args.Add(TEXT("X"), X.ToDouble());
	Args.Add(TEXT("Y"), Y.ToDouble());
	Args.Add(TEXT("Z"), Z.ToDouble());

	return FText::Format(NSLOCTEXT("DecimalNumber", "DecimalVector", "X={X} Y={Y} Z={Z}"), Args);
}

FString FDecimalVector::ToCompactString() const
{
	if (IsNearlyZero())
	{
		return FString::Printf(TEXT("V(0)"));
	}

	FString ReturnString(TEXT("V("));
	bool bIsEmptyString = true;
	if (!FDecimalMath::IsNearlyZero(X))
	{
		ReturnString += FString::Printf(TEXT("X=%s"), *X.ToString(2));
		bIsEmptyString = false;
	}
	if (!FDecimalMath::IsNearlyZero(Y))
	{
		if (!bIsEmptyString)
		{
			ReturnString += FString(TEXT(", "));
		}
		ReturnString += FString::Printf(TEXT("Y=%s"), *Y.ToString(2));
		bIsEmptyString = false;
	}
	if (!FDecimalMath::IsNearlyZero(Z))
	{
		if (!bIsEmptyString)
		{
			ReturnString += FString(TEXT(", "));
		}
		ReturnString += FString::Printf(TEXT("Z=%s"), *Z.ToString(2));
		bIsEmptyString = false;
	}
	ReturnString += FString(TEXT(")"));
	return ReturnString;
}

FText FDecimalVector::ToCompactText() const
{
	if (IsNearlyZero())
	{
		return NSLOCTEXT("DecimalNumber", "DecimalVector_CompactZeroVector", "V(0)");
	}

	const bool XIsNotZero = !FDecimalMath::IsNearlyZero(X);
	const bool YIsNotZero = !FDecimalMath::IsNearlyZero(Y);
	const bool ZIsNotZero = !FDecimalMath::IsNearlyZero(Z);

	FNumberFormattingOptions FormatRules;
	FormatRules.MinimumFractionalDigits = 2;
	FormatRules.MinimumIntegralDigits = 0;

	FFormatNamedArguments Args;
	Args.Add(TEXT("X"), FText::AsNumber(X.ToDouble(), &FormatRules));
	Args.Add(TEXT("Y"), FText::AsNumber(Y.ToDouble(), &FormatRules));
	Args.Add(TEXT("Z"), FText::AsNumber(Z.ToDouble(), &FormatRules));

	if (XIsNotZero && YIsNotZero && ZIsNotZero)
	{
		return FText::Format(NSLOCTEXT("DecimalNumber", "DecimalVector_CompactZeroVector", "V(X={X}, Y={Y}, Z={Z})"), Args);
	}
	else if (!XIsNotZero && YIsNotZero && ZIsNotZero)
	{
		return FText::Format(NSLOCTEXT("DecimalNumber", "DecimalVector_CompactZeroVector", "V(Y={Y}, Z={Z})"), Args);
	}
	else if (XIsNotZero && !YIsNotZero && ZIsNotZero)
	{
		return FText::Format(NSLOCTEXT("DecimalNumber", "DecimalVector_CompactZeroVector", "V(X={X}, Z={Z})"), Args);
	}
	else if (XIsNotZero && YIsNotZero && !ZIsNotZero)
	{
		return FText::Format(NSLOCTEXT("DecimalNumber", "DecimalVector_CompactZeroVector", "V(X={X}, Y={Y})"), Args);
	}
	else if (!XIsNotZero && !YIsNotZero && ZIsNotZero)
	{
		return FText::Format(NSLOCTEXT("DecimalNumber", "DecimalVector_CompactZeroVector", "V(Z={Z})"), Args);
	}
	else if (XIsNotZero && !YIsNotZero && !ZIsNotZero)
	{
		return FText::Format(NSLOCTEXT("DecimalNumber", "DecimalVector_CompactZeroVector", "V(X={X})"), Args);
	}
	else if (!XIsNotZero && YIsNotZero && !ZIsNotZero)
	{
		return FText::Format(NSLOCTEXT("DecimalNumber", "DecimalVector_CompactZeroVector", "V(Y={Y})"), Args);
	}

	return NSLOCTEXT("DecimalNumber", "DecimalVector_CompactZeroVector", "V(0)");
}

bool FDecimalVector::InitFromString(const FString& InSourceString)
{
	X = Y = Z = 0;

	FString TempX, TempY, TempZ;
	// The initialization is only successful if the X, Y, and Z values can all be parsed from the string
	bool bSuccessful = FParse::Value(*InSourceString, TEXT("X="), TempX) && FParse::Value(*InSourceString, TEXT("Y="), TempY) && FParse::Value(*InSourceString, TEXT("Z="), TempZ);
	if (bSuccessful)
	{
		bSuccessful = FDecimal::FromString(TempX, X) && FDecimal::FromString(TempY, Y) && FDecimal::FromString(TempZ, Z);
	}

	return bSuccessful;
}

bool FDecimalVector::InitFromCompactString(const FString& InSourceString)
{
	bool bAxisFound = false;

	X = Y = Z = 0;

	if (FCString::Strifind(*InSourceString, TEXT("V(0)")) != nullptr)
	{
		return true;
	}

	FString TempX, TempY, TempZ;
	bool bSuccessful = FParse::Value(*InSourceString, TEXT("X="), TempX) | FParse::Value(*InSourceString, TEXT("Y="), TempY) | FParse::Value(*InSourceString, TEXT("Z="), TempZ);
	if (bSuccessful)
	{
		bSuccessful = FDecimal::FromString(TempX, X) && FDecimal::FromString(TempY, Y) && FDecimal::FromString(TempZ, Z);
	}

	return bSuccessful;
}

FDecimal FDecimalVector::HeadingAngle() const
{
	// Project Dir into Z plane.
	FDecimalVector PlaneDir = *this;
	PlaneDir.Z = 0.f;
	PlaneDir = PlaneDir.GetSafeNormal();

	FDecimal Angle = FDecimalMath::Acos(PlaneDir.X);

	if (PlaneDir.Y < 0.0f)
	{
		Angle *= -1.0f;
	}

	return Angle;
}

void FDecimalVector::CreateOrthonormalBasis(FDecimalVector& XAxis, FDecimalVector& YAxis, FDecimalVector& ZAxis)
{
	// Project the X and Y axes onto the plane perpendicular to the Z axis.
	XAxis -= (XAxis | ZAxis) / (ZAxis | ZAxis) * ZAxis;
	YAxis -= (YAxis | ZAxis) / (ZAxis | ZAxis) * ZAxis;

	// If the X axis was parallel to the Z axis, choose a vector which is orthogonal to the Y and Z axes.
	if (XAxis.SizeSquared() < UE_DELTA * UE_DELTA)
	{
		XAxis = YAxis ^ ZAxis;
	}

	// If the Y axis was parallel to the Z axis, choose a vector which is orthogonal to the X and Z axes.
	if (YAxis.SizeSquared() < UE_DELTA * UE_DELTA)
	{
		YAxis = XAxis ^ ZAxis;
	}

	// Normalize the basis vectors.
	XAxis.Normalize();
	YAxis.Normalize();
	ZAxis.Normalize();
}

bool FDecimalVector::PointsAreSame(const FDecimalVector& P, const FDecimalVector& Q)
{
	FDecimal Temp;
	Temp = P.X - Q.X;
	if ((Temp > -UE_THRESH_POINTS_ARE_SAME) && (Temp < UE_THRESH_POINTS_ARE_SAME))
	{
		Temp = P.Y - Q.Y;
		if ((Temp > -UE_THRESH_POINTS_ARE_SAME) && (Temp < UE_THRESH_POINTS_ARE_SAME))
		{
			Temp = P.Z - Q.Z;
			if ((Temp > -UE_THRESH_POINTS_ARE_SAME) && (Temp < UE_THRESH_POINTS_ARE_SAME))
			{
				return true;
			}
		}
	}
	return false;
}

bool FDecimalVector::PointsAreNear(const FDecimalVector& Point1, const FDecimalVector& Point2, const FDecimal& Dist)
{
	FDecimal Temp;
	Temp = (Point1.X - Point2.X); if (FDecimalMath::Abs(Temp) >= Dist) return false;
	Temp = (Point1.Y - Point2.Y); if (FDecimalMath::Abs(Temp) >= Dist) return false;
	Temp = (Point1.Z - Point2.Z); if (FDecimalMath::Abs(Temp) >= Dist) return false;
	return true;
}

FDecimal FDecimalVector::PointPlaneDist(const FDecimalVector& Point, const FDecimalVector& PlaneBase, const FDecimalVector& PlaneNormal)
{
	return (Point - PlaneBase) | PlaneNormal;
}

FDecimalVector FDecimalVector::PointPlaneProject(const FDecimalVector& Point, const FDecimalVector& PlaneBase, const FDecimalVector& PlaneNormal)
{
	//Find the distance of X from the plane
	//Add the distance back along the normal from the point
	return Point - FDecimalVector::PointPlaneDist(Point, PlaneBase, PlaneNormal) * PlaneNormal;
}

FDecimalVector FDecimalVector::VectorPlaneProject(const FDecimalVector& V, const FDecimalVector& PlaneNormal)
{
	return V - V.ProjectOnToNormal(PlaneNormal);
}

FDecimal FDecimalVector::Dist(const FDecimalVector& V1, const FDecimalVector& V2)
{
	return FDecimalMath::Sqrt(FDecimalVector::DistSquared(V1, V2));
}

FDecimal FDecimalVector::DistXY(const FDecimalVector& V1, const FDecimalVector& V2)
{
	return FDecimalMath::Sqrt(FDecimalVector::DistSquaredXY(V1, V2));
}

FDecimal FDecimalVector::DistSquared(const FDecimalVector& V1, const FDecimalVector& V2)
{
	return FDecimalMath::Square(V2.X - V1.X) + FDecimalMath::Square(V2.Y - V1.Y) + FDecimalMath::Square(V2.Z - V1.Z);
}

FDecimal FDecimalVector::DistSquaredXY(const FDecimalVector& V1, const FDecimalVector& V2)
{
	return FDecimalMath::Square(V2.X - V1.X) + FDecimalMath::Square(V2.Y - V1.Y);
}

FDecimal FDecimalVector::BoxPushOut(const FDecimalVector& Normal, const FDecimalVector& Size)
{
	return FDecimalMath::Abs(Normal.X * Size.X) + FDecimalMath::Abs(Normal.Y * Size.Y) + FDecimalMath::Abs(Normal.Z * Size.Z);
}

FDecimalVector FDecimalVector::Min(const FDecimalVector& A, const FDecimalVector& B)
{
	return FDecimalVector(
		FDecimalMath::Min(A.X, B.X),
		FDecimalMath::Min(A.Y, B.Y),
		FDecimalMath::Min(A.Z, B.Z)
	);
}

FDecimalVector FDecimalVector::Max(const FDecimalVector& A, const FDecimalVector& B)
{
	return FDecimalVector(
		FDecimalMath::Max(A.X, B.X),
		FDecimalMath::Max(A.Y, B.Y),
		FDecimalMath::Max(A.Z, B.Z)
	);
}

FDecimalVector FDecimalVector::Min3(const FDecimalVector& A, const FDecimalVector& B, const FDecimalVector& C)
{
	return FDecimalVector(
		FDecimalMath::Min3(A.X, B.X, C.X),
		FDecimalMath::Min3(A.Y, B.Y, C.Y),
		FDecimalMath::Min3(A.Z, B.Z, C.Z)
	);
}

FDecimalVector FDecimalVector::Max3(const FDecimalVector& A, const FDecimalVector& B, const FDecimalVector& C)
{
	return FDecimalVector(
		FDecimalMath::Max3(A.X, B.X, C.X),
		FDecimalMath::Max3(A.Y, B.Y, C.Y),
		FDecimalMath::Max3(A.Z, B.Z, C.Z)
	);
}

bool FDecimalVector::Parallel(const FDecimalVector& Normal1, const FDecimalVector& Normal2, const FDecimal& ParallelCosineThreshold)
{
	const FDecimal NormalDot = Normal1 | Normal2;
	return FDecimalMath::Abs(NormalDot) >= ParallelCosineThreshold;
}

bool FDecimalVector::Coincident(const FDecimalVector& Normal1, const FDecimalVector& Normal2, const FDecimal& ParallelCosineThreshold)
{
	const FDecimal NormalDot = Normal1 | Normal2;
	return NormalDot >= ParallelCosineThreshold;
}

bool FDecimalVector::Orthogonal(const FDecimalVector& Normal1, const FDecimalVector& Normal2, const FDecimal& OrthogonalCosineThreshold)
{
	const FDecimal NormalDot = Normal1 | Normal2;
	return FDecimalMath::Abs(NormalDot) <= OrthogonalCosineThreshold;
}

bool FDecimalVector::Coplanar(const FDecimalVector& Base1, const FDecimalVector& Normal1, const FDecimalVector& Base2, const FDecimalVector& Normal2, const FDecimal& ParallelCosineThreshold)
{
	if (!FDecimalVector::Parallel(Normal1, Normal2, ParallelCosineThreshold)) return false;
	else if (FDecimalMath::Abs(FDecimalVector::PointPlaneDist(Base2, Base1, Normal1)) > UE_THRESH_POINT_ON_PLANE) return false;
	else return true;
}

FDecimal FDecimalVector::Triple(const FDecimalVector& X, const FDecimalVector& Y, const FDecimalVector& Z)
{
	return
		((X.X * (Y.Y * Z.Z - Y.Z * Z.Y))
		+ (X.Y * (Y.Z * Z.X - Y.X * Z.Z))
		+ (X.Z * (Y.X * Z.Y - Y.Y * Z.X)));
}

FDecimal FDecimalVector::EvaluateBezier(const FDecimalVector* ControlPoints, int32 NumPoints, TArray<FDecimalVector>& OutPoints)
{
	check(ControlPoints);
	check(NumPoints >= 2);

	// var q is the change in t between successive evaluations.
	const FDecimal q = 1.f / (FDecimal)(NumPoints - 1); // q is dependent on the number of GAPS = POINTS-1

	// recreate the names used in the derivation
	const FDecimalVector& P0 = ControlPoints[0];
	const FDecimalVector& P1 = ControlPoints[1];
	const FDecimalVector& P2 = ControlPoints[2];
	const FDecimalVector& P3 = ControlPoints[3];

	// coefficients of the cubic polynomial that we're FDing -
	const FDecimalVector a = P0;
	const FDecimalVector b = 3 * (P1 - P0);
	const FDecimalVector c = 3 * (P2 - 2 * P1 + P0);
	const FDecimalVector d = P3 - 3 * P2 + 3 * P1 - P0;

	// initial values of the poly and the 3 diffs -
	FDecimalVector S = a;						// the poly value
	FDecimalVector U = b * q + c * q * q + d * q * q * q;	// 1st order diff (quadratic)
	FDecimalVector V = 2 * c * q * q + 6 * d * q * q * q;	// 2nd order diff (linear)
	FDecimalVector W = 6 * d * q * q * q;				// 3rd order diff (constant)

	// Path length.
	FDecimal Length = 0;

	FDecimalVector OldPos = P0;
	OutPoints.Add(P0);	// first point on the curve is always P0.

	for (int32 i = 1; i < NumPoints; ++i)
	{
		// calculate the next value and update the deltas
		S += U;			// update poly value
		U += V;			// update 1st order diff value
		V += W;			// update 2st order diff value
		// 3rd order diff is constant => no update needed.

		// Update Length.
		Length += FDecimalVector::Dist(S, OldPos);
		OldPos = S;

		OutPoints.Add(S);
	}

	// Return path length as experienced in sequence (linear interpolation between points).
	return Length;
}

FDecimalVector FDecimalVector::RadiansToDegrees(const FDecimalVector& RadVector)
{
	return RadVector * (180.f / FDecimal::ConstantPI);
}

FDecimalVector FDecimalVector::DegreesToRadians(const FDecimalVector& DegVector)
{
	return DegVector * (FDecimal::ConstantPI / 180.f);
}

void FDecimalVector::GenerateClusterCenters(TArray<FDecimalVector>& Clusters, const TArray<FDecimalVector>& Points, int32 NumIterations, int32 NumConnectionsToBeValid)
{
	struct FClusterMovedHereToMakeCompile
	{
		FDecimalVector ClusterPosAccum;
		int32 ClusterSize;
	};

	// Check we have >0 points and clusters
	if (Points.Num() == 0 || Clusters.Num() == 0)
	{
		return;
	}

	// Temp storage for each cluster that mirrors the order of the passed in Clusters array
	TArray<FClusterMovedHereToMakeCompile> ClusterData;
	ClusterData.AddZeroed(Clusters.Num());

	// Then iterate
	for (int32 ItCount = 0; ItCount < NumIterations; ItCount++)
	{
		// Classify each point - find closest cluster center
		for (int32 i = 0; i < Points.Num(); i++)
		{
			const FDecimalVector& Pos = Points[i];

			// Iterate over all clusters to find closes one
			int32 NearestClusterIndex = INDEX_NONE;
			FDecimal NearestClusterDistSqr = UE_BIG_NUMBER;
			for (int32 j = 0; j < Clusters.Num(); j++)
			{
				const FDecimal DistSqr = (Pos - Clusters[j]).SizeSquared();
				if (DistSqr < NearestClusterDistSqr)
				{
					NearestClusterDistSqr = DistSqr;
					NearestClusterIndex = j;
				}
			}
			// Update its info with this point
			if (NearestClusterIndex != INDEX_NONE)
			{
				ClusterData[NearestClusterIndex].ClusterPosAccum += Pos;
				ClusterData[NearestClusterIndex].ClusterSize++;
			}
		}

		// All points classified - update cluster center as average of membership
		for (int32 i = 0; i < Clusters.Num(); i++)
		{
			if (ClusterData[i].ClusterSize > 0)
			{
				Clusters[i] = ClusterData[i].ClusterPosAccum / (FDecimal)ClusterData[i].ClusterSize;
			}
		}
	}

	// so now after we have possible cluster centers we want to remove the ones that are outliers and not part of the main cluster
	for (int32 i = 0; i < ClusterData.Num(); i++)
	{
		if (ClusterData[i].ClusterSize < NumConnectionsToBeValid)
		{
			Clusters.RemoveAt(i);
		}
	}
}

bool FDecimalVector::SerializeFromMismatchedTag(FName StructTag, FStructuredArchive::FSlot Slot)
{
	if (StructTag == TEXT("DecimalVector") || (StructTag == NAME_Vector && 
		(TIsUECoreVariant<FVector3d, int32>::Value || TIsUECoreVariant<FVector3d, uint32>::Value ||
		TIsUECoreVariant<FVector3f, int32>::Value || TIsUECoreVariant<FVector3f, uint32>::Value)))
	{
		// Note: Unlike float types int retains a default of 32bits, so no conversion is necessary.
		return Serialize(Slot);
	}

	return false;
}
