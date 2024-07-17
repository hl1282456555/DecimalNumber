// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Decimal.h"
#include "DecimalVector.generated.h"

USTRUCT(BlueprintType)
struct DECIMALNUMBER_API FDecimalVector
{
	GENERATED_BODY()
public:
	union
	{
		struct
		{
			FDecimal X;

			FDecimal Y;

			FDecimal Z;
		};

		UE_DEPRECATED(all, "For internal use only")
		FDecimal XYZ[3];
	};

public:
	/** A zero vector (0, 0, 0) */
	static const FDecimalVector ZeroVector;

	/** One vector (1, 1, 1) */
	static const FDecimalVector OneVector;

	/** Unreal up vector (0, 0, 1) */
	static const FDecimalVector UpVector;

	/** Unreal down vector (0, 0, -1) */
	static const FDecimalVector DownVector;

	/** Unreal forward vector (1, 0, 0) */
	static const FDecimalVector ForwardVector;

	/** Unreal backward vector (-1, 0, 0) */
	static const FDecimalVector BackwardVector;

	/** Unreal right vector (0, 1, 0) */
	static const FDecimalVector RightVector;

	/** Unreal left vector (0, -1, 0) */
	static const FDecimalVector LeftVector;

	/** Unit X axis vector (1, 0, 0) */
	static const FDecimalVector XAxisVector;

	/** Unit Y axis vector (0, 1, 0) */
	static const FDecimalVector YAxisVector;

	/** Unit Z axis vector (0, 0, 1) */
	static const FDecimalVector ZAxisVector;

	/** @return Zero vector (0, 0, 0) */
	static inline FDecimalVector Zero() { return ZeroVector; }

	/** @return One Vector (1,1,1) */
	static inline FDecimalVector One() { return OneVector; }

	/** @return Unit X Vector (1,0,0)  */
	static inline FDecimalVector UnitX() { return XAxisVector; }

	/** @return Unit Y Vector (0,1,0)  */
	static inline FDecimalVector UnitY() { return YAxisVector; }

	/** @return Unit Z Vector (0,0,1)  */
	static inline FDecimalVector UnitZ() { return ZAxisVector; }

public:
	/** Default constructor (no initialization) */
	FORCEINLINE FDecimalVector();

	/**
	 * Constructor initializing all components to a single value.
	 *
	 * @param InVal Value to set all components to.
	 */
	explicit FORCEINLINE FDecimalVector(const FDecimal& InVal);

	/**
	 * Constructor using initial values for each component.
	 *
	 * @param InX X Coordinate.
	 * @param InY Y Coordinate.
	 * @param InZ Z Coordinate.
	 */
	FORCEINLINE FDecimalVector(const FDecimal& InX, const FDecimal& InY, const FDecimal& InZ);

	template <typename T, TEMPLATE_REQUIRES(std::is_arithmetic<T>::value)>
	FORCEINLINE FDecimalVector(T InX, T InY, T InZ)
		: X(InX), Y(InY), Z(InZ)
	{

	}

	/**
	* Constructs a vector from an FDecimalVector.
	* 
	* @param V Vector to copy from.
	*/
	FORCEINLINE FDecimalVector(const FDecimalVector& V);

	/**
	 * Constructs a vector from an TVector3<T>.
	 *
	 * @param V Vector to copy from.
	 */
	template <typename T>
	explicit FORCEINLINE FDecimalVector(const UE::Math::TVector<T>& V)
		: X(V.X), Y(V.Y), Z(V.Z)
	{
	}

	/**
	* Constructs a vector from an TVector2<T> and Z value.
	* 
	* @param V Vector to copy from.
	* @param InZ Z Coordinate.
	*/
	template <typename T>
	explicit FORCEINLINE FDecimalVector(const UE::Math::TVector2<T>& V, T InZ)
		: X(V.X), Y(V.Y), Z(InZ)
	{
	}

	/**
	* Constructor using the XYZ components from a 4D vector
	* 
	* @param V 4D Vector to copy from.
	*/
	template <typename T>
	FORCEINLINE FDecimalVector(const UE::Math::TVector4<T>& V)
		: X(V.X), Y(V.Y), Z(V.Z)
	{
	}

	/**
	* Constructs a vector from an FLinearColor.
	* 
	* @param InColor Color to copy from.
	*/
	explicit FDecimalVector(const FLinearColor& InColor);

	/**
	* Construts a vector from an FIntVector.
	* 
	* @param InVector FIntVector to copy from.
	*/
	template <typename IntType>
	explicit FDecimalVector(const UE::Math::TIntVector3<IntType>& InVector)
		: X(InVector.X), Y(InVector.Y), Z(InVector.Z)
	{
	}

	/**
	* Constructs a vector from an FIntPoint.
	* 
	* @param A Int Point used to set X and Y coordinates, Z is set to zero.
	*/
	template <typename IntType>
	explicit FDecimalVector(const UE::Math::TIntPoint<IntType>& A)
		: X(A.X), Y(A.Y), Z(0)
	{
	}

	/**
	* Constructor which initializes all components to zero.
	* 
	* @param EForceInit Force init enum.
	*/
	explicit FORCEINLINE FDecimalVector(EForceInit);

	/**
	* Convert vector to TIntVector3<T>.
	*/
	template <typename T>
	explicit FORCEINLINE operator UE::Math::TIntVector3<T>() const
	{
		return UE::Math::TIntVector3<T>((T)X.ToDouble(), (T)Y.ToDouble(), (T)Z.ToDouble());
	}

	/**
	* Convert FDecimalVector to TVector<T>
	*/
	template <typename T>
	explicit FORCEINLINE operator UE::Math::TVector<T>() const
	{
		return UE::Math::TVector<T>((T)X.ToDouble(), (T)Y.ToDouble(), (T)Z.ToDouble());
	}

	template <typename T, TEMPLATE_REQUIRES(std::is_arithmetic<T>::value)>
	FORCEINLINE FDecimalVector& operator=(const UE::Math::TVector<T>& V)
	{
		X = V.X; Y = V.Y; Z = V.Z;
		return *this;
	}

	/**
	* Copy all component-wise values from another vector.
	* 
	* @param V The vector copy from.
	* @return self after copy done.
	*/
	FORCEINLINE FDecimalVector& operator=(const FDecimalVector& V);

	/**
	* Calculate cross product between this and another vector.
	* 
	* @param V The other vector.
	* @return The cross product.
	*/
	FORCEINLINE FDecimalVector operator^(const FDecimalVector& V) const;

	/**
	* Calculate cross product between this and another vector
	* 
	* @param V The other vector.
	* @return The cross product.
	*/
	FORCEINLINE FDecimalVector Cross(const FDecimalVector& V) const;

	/**
	* Calculate the cross product of two vectors.
	* 
	* @param A The first vector.
	* @param B The second vector.
	* @return The cross product.
	*/
	FORCEINLINE static FDecimalVector CrossProduct(const FDecimalVector& A, const FDecimalVector& B);

	/**
	* Calculate the dot product between this and another vector.
	* 
	* @param V The other vector.
	* @return The dot product.
	*/
	FORCEINLINE FDecimal operator|(const FDecimalVector& V) const;

	/**
	* Calculate the dot product between this and another vector.
	* 
	* @param V The other vector.
	* @return The dot product.
	*/
	FORCEINLINE FDecimal Dot(const FDecimalVector& V) const;

	/**
	* Calculate the dot product of two vectors.
	*
	* @param A The first vector.
	* @param B The second vector.
	* @return The dot product.
	*/
	FORCEINLINE static FDecimal DotProduct(const FDecimalVector& A, const FDecimalVector& B);

	/**
	 * Gets the result of component-wise addition of this and another vector.
	 *
	 * @param V The vector to add to this.
	 * @return The result of vector addition.
	 */
	FORCEINLINE FDecimalVector operator+(const FDecimalVector& V) const;

	/**
	 * Gets the result of component-wise subtraction of this by another vector.
	 *
	 * @param V The vector to subtract from this.
	 * @return The result of vector subtraction.
	 */
	FORCEINLINE FDecimalVector operator-(const FDecimalVector& V) const;

	/**
	* Gets the result of scaling the vector (multiplying each component by a value).
	* 
	* @param Scale What to multiply each component by.
	* @return The result of multiplication.
	*/
	template <typename Type, TEMPLATE_REQUIRES(ARITHMETIC_WITH_DECIMAL_CONDITION(Type))>
	FORCEINLINE FDecimalVector operator*(Type Scale) const
	{
		return FDecimalVector(X * Scale, Y * Scale, Z * Scale);
	}

	/**
	* Gets the result of dividing each component of the vector by a value.
	* 
	* @pararm Scale What to divide each component by.
	* @return The result of division.
	*/
	template <typename Type, TEMPLATE_REQUIRES(ARITHMETIC_WITH_DECIMAL_CONDITION(Type))>
	FDecimalVector operator/(Type Scale) const
	{
		Type RScale = 1.0f / Scale;
		return FDecimalVector(X * RScale, Y * RScale, Z * RScale);
	}

	/**
	* Gets the result of component-wise multiplication of this vector by another.
	* 
	* @param V The vector to multiply with.
	* @return The result of multiplication.
	*/
	FORCEINLINE FDecimalVector operator*(const FDecimalVector& V) const;

	/**
	* Gets the result of component-wise division of this vector by another.
	* 
	* @param V The vector to divide by.
	* @return The result of division.
	*/
	FORCEINLINE FDecimalVector operator/(const FDecimalVector& V) const;

	// Binary comparsion operators.
	
	/**
	* Check against another vector for quality.
	* 
	* @param V The vector to check against.
	* @return true if the vectors are equal, false otherwise.
	*/
	bool operator==(const FDecimalVector& V) const;

	/**
	* Check against another vector for inequality.
	* 
	* @param V The vector to check against.
	* @return true if the vectors are not equal, false otherwise.
	*/
	bool operator!=(const FDecimalVector& V) const;

	/**
	* Check against another vector for equality, within specified error limits.
	* 
	* @param V The vector to check against.
	* @param Tolerance Error tolerance.
	* @return true if the vectors are equal within tolerance limits, false otherwise.
	*/
	bool Equals(const FDecimalVector& V, const FDecimal& Tolerance = FDecimal(UE_KINDA_SMALL_NUMBER)) const;

	/**
	* Check whether all components of this vector are the same, within a tolerance.
	* 
	* @param Tolerance Erro tolerance.
	* @return true if the vectors are equal within tolerance limits, false otherwise.
	*/
	bool AllComponentsEqual(const FDecimal& Tolerance = UE_KINDA_SMALL_NUMBER) const;

	/**
    * Get a negated copy of the vector.
    *
    * @return A negated copy of the vector.
    */
    FORCEINLINE FDecimalVector operator-() const;

	/**
	 * Adds another vector to this.
	 * Uses component-wise addition.
	 *
	 * @param V Vector to add to this.
	 * @return Copy of the vector after addition.
	 */
	FORCEINLINE FDecimalVector operator+=(const FDecimalVector& V);

	/**
	 * Subtracts another vector from this.
	 * Uses component-wise subtraction.
	 *
	 * @param V Vector to subtract from this.
	 * @return Copy of the vector after subtraction.
	 */
	FORCEINLINE FDecimalVector operator-=(const FDecimalVector& V);

	/**
	 * Scales the vector.
	 *
	 * @param Scale Amount to scale this vector by.
	 * @return Copy of the vector after scaling.
	 */
	template <typename Type, TEMPLATE_REQUIRES(ARITHMETIC_WITH_DECIMAL_CONDITION(Type))>
	FORCEINLINE FDecimalVector operator*=(Type Scale)
	{
		X *= Scale; Y *= Scale; Z *= Scale;
		return *this;
	}

	/**
	 * Divides the vector by a number.
	 *
	 * @param V What to divide this vector by.
	 * @return Copy of the vector after division.
	 */
	template <typename Type, TEMPLATE_REQUIRES(ARITHMETIC_WITH_DECIMAL_CONDITION(Type))>
	FDecimalVector operator/=(Type Scale)
	{
		const Type RV = 1.0f / Scale;
		X *= RV; Y *= RV; Z *= RV;

		return *this;
	}

	/**
	 * Multiplies the vector with another vector, using component-wise multiplication.
	 *
	 * @param V What to multiply this vector with.
	 * @return Copy of the vector after multiplication.
	 */
	FDecimalVector operator*=(const FDecimalVector& V);

	/**
	 * Divides the vector by another vector, using component-wise division.
	 *
	 * @param V What to divide vector by.
	 * @return Copy of the vector after division.
	 */
	FDecimalVector operator/=(const FDecimalVector& V);

	/**
	 * Gets specific component of the vector.
	 *
	 * @param Index the index of vector component
	 * @return reference to component.
	 */
	FDecimal& operator[](int32 Index);

	/**
	 * Gets specific component of the vector.
	 *
	 * @param Index the index of vector component
	 * @return Copy of the component.
	 */
	FDecimal operator[](int32 Index) const;

	/**
	* Gets a specific component of the vector.
	*
	* @param Index The index of the component required.
	*
	* @return Reference to the specified component.
	*/
	FDecimal& Component(int32 Index);

	/**
	* Gets a specific component of the vector.
	*
	* @param Index The index of the component required.
	* @return Copy of the specified component.
	*/
	FDecimal Component(int32 Index) const;


	/** Get a specific component of the vector, given a specific axis by enum */
	FDecimal GetComponentForAxis(EAxis::Type Axis) const;

	/** Set a specified componet of the vector, given a specific axis by enum */
	void SetComponentForAxis(EAxis::Type Axis, const FDecimal& Component);

public:
	// Simple functins.

	/**
	 * Set the values of the vector directly.
	 *
	 * @param InX New X coordinate.
	 * @param InY New Y coordinate.
	 * @param InZ New Z coordinate.
	 */
	void Set(const FDecimal& InX, const FDecimal& InY, const FDecimal& InZ);

	/**
	 * Get the maximum value of the vector's components.
	 *
	 * @return The maximum value of the vector's components.
	 */
	FDecimal GetMax() const;

	/**
	 * Get the maximum absolute value of the vector's components.
	 *
	 * @return The maximum absolute value of the vector's components.
	 */
	FDecimal GetAbsMax() const;

	/**
	 * Get the minimum value of the vector's components.
	 *
	 * @return The minimum value of the vector's components.
	 */
	FDecimal GetMin() const;

	/**
	 * Get the minimum absolute value of the vector's components.
	 *
	 * @return The minimum absolute value of the vector's components.
	 */
	FDecimal GetAbsMin() const;

	/** Gets the component-wise min of two vectors. */
	FDecimalVector ComponentMin(const FDecimalVector& Other) const;

	/** Gets the component-wise max of two vectors. */
	FDecimalVector ComponentMax(const FDecimalVector& Other) const;

	/**
	* Get a copy of this vector with absolute value of each component.
	*
	* @return A copy of this vector with absolute value of each component.
	*/
	FDecimalVector GetAbs() const;

	/**
	 * Get the length (magnitude) of this vector.
	 *
	 * @return The length of this vector.
	 */
	FDecimal Size() const;

	/**
	 * Get the length (magnitude) of this vector.
	 *
	 * @return The length of this vector.
	 */
	FDecimal Length() const;

	/**
	 * Get the squared length of this vector.
	 *
	 * @return The squared length of this vector.
	 */
	FDecimal SizeSquared() const;

	/**
	 * Get the squared length of this vector.
	 *
	 * @return The squared length of this vector.
	 */
	FDecimal SquaredLength() const;

	/**
	 * Get the length of the 2D components of this vector.
	 *
	 * @return The 2D length of this vector.
	 */
	FDecimal Size2D() const;

	/**
	 * Get the squared length of the 2D components of this vector.
	 *
	 * @return The squared 2D length of this vector.
	 */
	FDecimal SizeSquared2D() const;

	/**
	 * Checks whether vector is near to zero within a specified tolerance.
	 *
	 * @param Tolerance Error tolerance.
	 * @return true if the vector is near to zero, false otherwise.
	 */
	bool IsNearlyZero(const FDecimal& Tolerance = UE_KINDA_SMALL_NUMBER) const;

	/**
	 * Checks whether all components of the vector are exactly zero.
	 *
	 * @return true if the vector is exactly zero, false otherwise.
	 */
	bool IsZero() const;

	/**
	 * Check if the vector is of unit length, with specified tolerance.
	 *
	 * @param LengthSquaredTolerance Tolerance against squared length.
	 * @return true if the vector is a unit vector within the specified tolerance.
	 */
	FORCEINLINE bool IsUnit(const FDecimal& LengthSquaredTolerance = UE_KINDA_SMALL_NUMBER) const;

	/**
	 * Checks whether vector is normalized.
	 *
	 * @return true if normalized, false otherwise.
	 */
	bool IsNormalized() const;

	/**
	 * Normalize this vector in-place if it is larger than a given tolerance. Leaves it unchanged if not.
	 *
	 * @param Tolerance Minimum squared length of vector for normalization.
	 * @return true if the vector was normalized correctly, false otherwise.
	 */
	bool Normalize(const FDecimal& Tolerance = UE_SMALL_NUMBER);

	/**
	 * Calculates normalized version of vector without checking for zero length.
	 *
	 * @return Normalized version of vector.
	 * @see GetSafeNormal()
	 */
	FORCEINLINE FDecimalVector GetUnsafeNormal() const;

	/**
	 * Gets a normalized copy of the vector, checking it is safe to do so based on the length.
	 * Returns zero vector by default if vector length is too small to safely normalize.
	 *
	 * @param Tolerance Minimum squared vector length.
	 * @return A normalized copy if safe, ResultIfZero otherwise.
	 */
	FDecimalVector GetSafeNormal(const FDecimal& Tolerance = UE_SMALL_NUMBER, const FDecimalVector& ResultIfZero = ZeroVector) const;

	/**
	 * Gets a normalized copy of the 2D components of the vector, checking it is safe to do so. Z is set to zero.
	 * Returns zero vector by default if vector length is too small to normalize.
	 *
	 * @param Tolerance Minimum squared vector length.
	 * @return Normalized copy if safe, otherwise returns ResultIfZero.
	 */
	FDecimalVector GetSafeNormal2D(const FDecimal& Tolerance = UE_SMALL_NUMBER, const FDecimalVector& ResultIfZero = ZeroVector) const;

	/**
	 * Util to convert this vector into a unit direction vector and its original length.
	 *
	 * @param OutDir Reference passed in to store unit direction vector.
	 * @param OutLength Reference passed in to store length of the vector.
	 */
	void ToDirectionAndLength(FDecimalVector& OutDir, double& OutLength) const;
	void ToDirectionAndLength(FDecimalVector& OutDir, float& OutLength) const;

	/**
	 * Get a copy of the vector as sign only.
	 * Each component is set to +1 or -1, with the sign of zero treated as +1.
	 *
	 * @param A copy of the vector with each component set to +1 or -1
	 */
	FORCEINLINE FDecimalVector GetSignVector() const;

	/**
	 * Projects 2D components of vector based on Z.
	 *
	 * @return Projected version of vector based on Z.
	 */
	FDecimalVector Projection() const;

	/**
	* Calculates normalized 2D version of vector without checking for zero length.
	*
	* @return Normalized version of vector.
	* @see GetSafeNormal2D()
	*/
	FORCEINLINE FDecimalVector GetUnsafeNormal2D() const;

	/**
	 * Gets a copy of this vector snapped to a grid.
	 *
	 * @param GridSz Grid dimension.
	 * @return A copy of this vector snapped to a grid.
	 * @see FMath::GridSnap()
	 */
	FDecimalVector GridSnap(const FDecimal& GridSz) const;

	/**
	 * Get a copy of this vector, clamped inside of a cube.
	 *
	 * @param Radius Half size of the cube.
	 * @return A copy of this vector, bound by cube.
	 */
	FDecimalVector BoundToCube(const FDecimal& Radius) const;

	/** Get a copy of this vector, clamped inside of a cube. */
	FDecimalVector BoundToBox(const FDecimalVector& Min, const FDecimalVector& Max) const;

	/** Create a copy of this vector, with its magnitude clamped between Min and Max. */
	FDecimalVector GetClampedToSize(const FDecimal& Min, const FDecimal& Max) const;

	/** Create a copy of this vector, with the 2D magnitude clamped between Min and Max. Z is unchanged. */
	FDecimalVector GetClampedToSize2D(const FDecimal& Min, const FDecimal& Max) const;

	/** Create a copy of this vector, with its maximum magnitude clamped to MaxSize. */
	FDecimalVector GetClampedToMaxSize(const FDecimal& MaxSize) const;

	/** Create a copy of this vector, with the maximum 2D magnitude clamped to MaxSize. Z is unchanged. */
	FDecimalVector GetClampedToMaxSize2D(const FDecimal& MaxSize) const;

	/**
	 * Add a vector to this and clamp the result in a cube.
	 *
	 * @param V Vector to add.
	 * @param Radius Half size of the cube.
	 */
	void AddBounded(const FDecimalVector& V, const FDecimal& Radius = MAX_int16);

	/**
	 * Gets the reciprocal of this vector, avoiding division by zero.
	 * Zero components are set to BIG_NUMBER.
	 *
	 * @return Reciprocal of this vector.
	 */
	FDecimalVector Reciprocal() const;

	/**
	 * Check whether X, Y and Z are nearly equal.
	 *
	 * @param Tolerance Specified Tolerance.
	 * @return true if X == Y == Z within the specified tolerance.
	 */
	bool IsUniform(const FDecimal& Tolerance = UE_KINDA_SMALL_NUMBER) const;

	/**
	 * Mirror a vector about a normal vector.
	 *
	 * @param MirrorNormal Normal vector to mirror about.
	 * @return Mirrored vector.
	 */
	FDecimalVector MirrorByVector(const FDecimalVector& MirrorNormal) const;

	/**
	 * Mirrors a vector about a plane.
	 *
	 * @param Plane Plane to mirror about.
	 * @return Mirrored vector.
	 */
	template <typename T, TEMPLATE_REQUIRES(std::is_arithmetic<T>::value)>
	FDecimalVector MirrorByPlane(const UE::Math::TPlane<T>& Plane) const
	{
		return *this - Plane * (2.f * (Plane.X * .X + Plane.Y * Y + Plane.Z * Z - Plane.W));
	}

	/**
	 * Rotates around Axis (assumes Axis.Size() == 1).
	 *
	 * @param AngleDeg Angle to rotate (in degrees).
	 * @param Axis Axis to rotate around.
	 * @return Rotated Vector.
	 */
	template <typename Type, TEMPLATE_REQUIRES(ARITHMETIC_WITH_DECIMAL_CONDITION(Type))>
	FDecimalVector RotateAngleAxis(const Type AngleDeg, const FDecimalVector& Axis) const
	{
		return RotateAngleAxisRad(FDecimalMath::DegreesToRadians(AngleDeg), Axis);
	}

	/**
	 * Rotates around Axis (assumes Axis.Size() == 1).
	 *
	 * @param AngleRad Angle to rotate (in radians).
	 * @param Axis Axis to rotate around.
	 * @return Rotated Vector.
	 */
	template <typename Type, TEMPLATE_REQUIRES(ARITHMETIC_WITH_DECIMAL_CONDITION(Type))>
	FDecimalVector RotateAngleAxisRad(const Type AngleRad, const FDecimalVector& Axis) const
	{
		FDecimal S, C;
		FDecimalMath::SinCos(S, C, AngleRad);

		const T XX = Axis.X * Axis.X;
		const T YY = Axis.Y * Axis.Y;
		const T ZZ = Axis.Z * Axis.Z;

		const T XY = Axis.X * Axis.Y;
		const T YZ = Axis.Y * Axis.Z;
		const T ZX = Axis.Z * Axis.X;

		const T XS = Axis.X * S;
		const T YS = Axis.Y * S;
		const T ZS = Axis.Z * S;

		const T OMC = 1.f - C;

		return FDecimalVector(
			(OMC * XX + C) * X + (OMC * XY - ZS) * Y + (OMC * ZX + YS) * Z,
			(OMC * XY + ZS) * X + (OMC * YY + C) * Y + (OMC * YZ - XS) * Z,
			(OMC * ZX - YS) * X + (OMC * YZ + XS) * Y + (OMC * ZZ + C) * Z
		);
	}

	/**
	 * Returns the cosine of the angle between this vector and another projected onto the XY plane (no Z).
	 *
	 * @param B the other vector to find the 2D cosine of the angle with.
	 * @return The cosine.
	 */
	FORCEINLINE FDecimal CosineAngle2D(FDecimalVector B) const;

	/**
	 * Gets a copy of this vector projected onto the input vector.
	 *
	 * @param A	Vector to project onto, does not assume it is normalized.
	 * @return Projected vector.
	 */
	FORCEINLINE FDecimalVector ProjectOnTo(const FDecimalVector& A) const;

	/**
	 * Gets a copy of this vector projected onto the input vector, which is assumed to be unit length.
	 *
	 * @param  Normal Vector to project onto (assumed to be unit length).
	 * @return Projected vector.
	 */
	FORCEINLINE FDecimalVector ProjectOnToNormal(const FDecimalVector& Normal) const;

	/**
	 * Return the TRotator orientation corresponding to the direction in which the vector points.
	 * Sets Yaw and Pitch to the proper numbers, and sets Roll to zero because the roll can'T be determined from a vector.
	 *
	 * @return TRotator from the Vector's direction, without any roll.
	 * @see ToOrientationQuat()
	 */
	template <typename T, TEMPLATE_REQUIRES(std::is_arithmetic<T>::value)>
	UE::Math::TRotator<T> ToOrientationRotator() const
	{
		UE::Math::TRotator<T> R;

		// Find yaw.
		R.Yaw = FDecimalMath::RadiansToDegrees(FDecimalMath::Atan2(Y, X));

		// Find pitch.
		R.Pitch = FDecimalMath::RadiansToDegrees(FDecimalMath::Atan2(Z, FMath::Sqrt(X * X + Y * Y)));

		// Find roll.
		R.Roll = 0;

#if ENABLE_NAN_DIAGNOSTIC || (DO_CHECK && !UE_BUILD_SHIPPING)
		if (R.ContainsNaN())
		{
			logOrEnsureNanError(TEXT("TVector::Rotation(): Rotator result %s contains NaN! Input FVector = %s"), *R.ToString(), *this->ToString());
			R = UE::Math::TRotator<T>::ZeroRotator;
		}
#endif

		return R;
	}

	/**
	 * Return the Quaternion orientation corresponding to the direction in which the vector points.
	 * Similar to the UE::Math::TRotator<T> version, returns a result without roll such that it preserves the up vector.
	 *
	 * @note If you don'T care about preserving the up vector and just want the most direct rotation, you can use the faster
	 * 'FQuat::FindBetweenVectors(FVector::ForwardVector, YourVector)' or 'FQuat::FindBetweenNormals(...)' if you know the vector is of unit length.
	 *
	 * @return Quaternion from the Vector's direction, without any roll.
	 * @see ToOrientationRotator(), FQuat::FindBetweenVectors()
	 */
	template <typename T, TEMPLATE_REQUIRES(std::is_arithmetic<T>::value)>
	UE::Math::TQuat<T> ToOrientationQuat() const
	{
		// Essentially an optimized Vector->Rotator->Quat made possible by knowing Roll == 0, and avoiding radians->degrees->radians.
		// This is done to avoid adding any roll (which our API states as a constraint).
		const FDecimal YawRad = FDecimalMath::Atan2(Y, X);
		const FDecimal PitchRad = FDecimalMath::Atan2(Z, FDecimalMath::Sqrt(X * X + Y * Y));

		const T DIVIDE_BY_2 = 0.5;
		FDecimal SP, SY;
		FDecimal CP, CY;

		FDecimalMath::SinCos(SP, CP, PitchRad * DIVIDE_BY_2);
		FDecimalMath::SinCos(SY, CY, YawRad * DIVIDE_BY_2);

		UE::Math::TQuat<T> RotationQuat;
		RotationQuat.X = (SP * SY).ToDouble();
		RotationQuat.Y = (- SP * CY).ToDoubl();
		RotationQuat.Z = (CP * SY).ToDouble();
		RotationQuat.W = (CP * CY).ToDouble();
		return RotationQuat;
	}

	/**
	 * Return the UE::Math::TRotator<T> orientation corresponding to the direction in which the vector points.
	 * Sets Yaw and Pitch to the proper numbers, and sets Roll to zero because the roll can't be determined from a vector.
	 * @note Identical to 'ToOrientationRotator()' and preserved for legacy reasons.
	 * @return UE::Math::TRotator<T> from the Vector's direction.
	 * @see ToOrientationRotator(), ToOrientationQuat()
	 */
	template <typename T, TEMPLATE_REQUIRES(std::is_arithmetic<T>::value)>
	FORCEINLINE UE::Math::TRotator<T> Rotation() const
	{
		return ToOrientationRotator<T>();
	}

	/**
	 * Find good arbitrary axis vectors to represent U and V axes of a plane,
	 * using this vector as the normal of the plane.
	 *
	 * @param Axis1 Reference to first axis.
	 * @param Axis2 Reference to second axis.
	 */
	void FindBestAxisVectors(FDecimalVector& Axis1, FDecimalVector& Axis2) const;

	/** When this vector contains Euler angles (degrees), ensure that angles are between +/-180 */
	void UnwindEuler();

	/**
	 * Utility to check if there are any non-finite values (NaN or Inf) in this vector.
	 *
	 * @return true if there are any non-finite values in this vector, false otherwise.
	 */
	bool ContainsNaN() const;

	/**
	 * Get a textual representation of this vector.
	 *
	 * @return A string describing the vector.
	 */
	FString ToString(int32 Precision = 3) const;

	/**
	* Get a locale aware textual representation of this vector.
	*
	* @return A string describing the vector.
	*/
	FText ToText() const;

	/** Get a short textural representation of this vector, for compact readable logging. */
	FString ToCompactString() const;

	/** Get a short locale aware textural representation of this vector, for compact readable logging. */
	FText ToCompactText() const;

	/**
	 * Initialize this Vector based on an FString. The String is expected to contain X=, Y=, Z=.
	 * The TVector<T> will be bogus when InitFromString returns false.
	 *
	 * @param	InSourceString	FString containing the vector values.
	 * @return true if the X,Y,Z values were read successfully; false otherwise.
	 */
	bool InitFromString(const FString& InSourceString);

	/**
	 * Initialize this Vector based on an FString. The String is expected to contain V(0)
	 * or at least one value X=, Y=, Z=, previously produced by ToCompactString()
	 * The TVector<T> will be bogus when InitFromString returns false.
	 *
	 * @param	InSourceString	FString containing the vector values.
	 * @return true if any of the X,Y,Z values were read successfully; false otherwise.
	 */
	bool InitFromCompactString(const FString& InSourceString);

	/**
	 * Converts a Cartesian unit vector into spherical coordinates on the unit sphere.
	 * @return Output Theta will be in the range [0, PI], and output Phi will be in the range [-PI, PI].
	 */
	template<typename T, TEMPLATE_REQUIRES(std::is_arithmetic<T>::value)>
	UE::Math::TVector2<T> UnitCartesianToSpherical() const
	{
		checkSlow(IsUnit());
		const FDecimal Theta = FDecimalMath::Acos(Z / Size());
		const FDecimal Phi = FDecimalMath::Atan2(Y, X);
		return UE::Math::TVector2<T>(Theta.ToDouble(), Phi.ToDouble());
	}

	/**
	 * Convert a direction vector into a 'heading' angle.
	 *
	 * @return 'Heading' angle between +/-PI. 0 is pointing down +X.
	 */
	FDecimal HeadingAngle() const;

	/**
	 * Create an orthonormal basis from a basis with at least two orthogonal vectors.
	 * It may change the directions of the X and Y axes to make the basis orthogonal,
	 * but it won'T change the direction of the Z axis.
	 * All axes will be normalized.
	 *
	 * @param XAxis The input basis' XAxis, and upon return the orthonormal basis' XAxis.
	 * @param YAxis The input basis' YAxis, and upon return the orthonormal basis' YAxis.
	 * @param ZAxis The input basis' ZAxis, and upon return the orthonormal basis' ZAxis.
	 */
	static void CreateOrthonormalBasis(FDecimalVector& XAxis, FDecimalVector& YAxis, FDecimalVector& ZAxis);

	/**
	 * Compare two points and see if they're the same, using a threshold.
	 *
	 * @param P First vector.
	 * @param Q Second vector.
	 * @return Whether points are the same within a threshold. Uses fast distance approximation (linear per-component distance).
	 */
	static bool PointsAreSame(const FDecimalVector& P, const FDecimalVector& Q);

	/**
	 * Compare two points and see if they're within specified distance.
	 *
	 * @param Point1 First vector.
	 * @param Point2 Second vector.
	 * @param Dist Specified distance.
	 * @return Whether two points are within the specified distance. Uses fast distance approximation (linear per-component distance).
	 */
	static bool PointsAreNear(const FDecimalVector& Point1, const FDecimalVector& Point2, const FDecimal& Dist);

	/**
	 * Calculate the signed distance (in the direction of the normal) between a point and a plane.
	 *
	 * @param Point The Point we are checking.
	 * @param PlaneBase The Base Point in the plane.
	 * @param PlaneNormal The Normal of the plane (assumed to be unit length).
	 * @return Signed distance between point and plane.
	 */
	static FDecimal PointPlaneDist(const FDecimalVector& Point, const FDecimalVector& PlaneBase, const FDecimalVector& PlaneNormal);

	/**
	 * Calculate the projection of a point on the given plane.
	 *
	 * @param Point The point to project onto the plane
	 * @param Plane The plane
	 * @return Projection of Point onto Plane
	 */
	template <typename T, TEMPLATE_REQUIRES(std::is_arithmetic<T>::value)>
	static FDecimalVector PointPlaneProject(const FDecimalVector& Point, const UE::Math::TPlane<T>& Plane)
	{
		//Find the distance of X from the plane
		//Add the distance back along the normal from the point
		return Point - FDecimalMath::PlaneDot<T>(Plane, Point) * Plane;
	}

	/**
	 * Calculate the projection of a point on the plane defined by counter-clockwise (CCW) points A,B,C.
	 *
	 * @param Point The point to project onto the plane
	 * @param A 1st of three points in CCW order defining the plane
	 * @param B 2nd of three points in CCW order defining the plane
	 * @param C 3rd of three points in CCW order defining the plane
	 * @return Projection of Point onto plane ABC
	 */
	template <typename T, TEMPLATE_REQUIRES(std::is_arithmetic<T>::value)>
	static FDecimalVector PointPlaneProject(const FDecimalVector& Point, const FDecimalVector& A, const FDecimalVector& B, const FDecimalVector& C)
	{
		//Compute the plane normal from ABC
		TPlane<T> Plane(A, B, C);

		//Find the distance of X from the plane
		//Add the distance back along the normal from the point
		return Point - FDecimalMath::PlaneDot<T>(Plane, Point) * Plane;
	}

	/**
	* Calculate the projection of a point on the plane defined by PlaneBase and PlaneNormal.
	*
	* @param Point The point to project onto the plane
	* @param PlaneBase Point on the plane
	* @param PlaneNorm Normal of the plane (assumed to be unit length).
	* @return Projection of Point onto plane
	*/
	static FDecimalVector PointPlaneProject(const FDecimalVector& Point, const FDecimalVector& PlaneBase, const FDecimalVector& PlaneNormal);

	/**
	 * Calculate the projection of a vector on the plane defined by PlaneNormal.
	 *
	 * @param  V The vector to project onto the plane.
	 * @param  PlaneNormal Normal of the plane (assumed to be unit length).
	 * @return Projection of V onto plane.
	 */
	static FDecimalVector VectorPlaneProject(const FDecimalVector& V, const FDecimalVector& PlaneNormal);

	/**
	 * Euclidean distance between two points.
	 *
	 * @param V1 The first point.
	 * @param V2 The second point.
	 * @return The distance between two points.
	 */
	static FDecimal Dist(const FDecimalVector& V1, const FDecimalVector& V2);
	static FORCEINLINE FDecimal Distance(const FDecimalVector& V1, const FDecimalVector& V2) { return Dist(V1, V2); }

	/**
	* Euclidean distance between two points in the XY plane (ignoring Z).
	*
	* @param V1 The first point.
	* @param V2 The second point.
	* @return The distance between two points in the XY plane.
	*/
	static FDecimal DistXY(const FDecimalVector& V1, const FDecimalVector& V2);
	static FORCEINLINE FDecimal Dist2D(const FDecimalVector& V1, const FDecimalVector& V2) { return DistXY(V1, V2); }

	/**
	 * Squared distance between two points.
	 *
	 * @param V1 The first point.
	 * @param V2 The second point.
	 * @return The squared distance between two points.
	 */
	static FDecimal DistSquared(const FDecimalVector& V1, const FDecimalVector& V2);

	/**
	 * Squared distance between two points in the XY plane only.
	 *
	 * @param V1 The first point.
	 * @param V2 The second point.
	 * @return The squared distance between two points in the XY plane
	 */
	static FDecimal DistSquaredXY(const FDecimalVector& V1, const FDecimalVector& V2);
	static FORCEINLINE FDecimal DistSquared2D(const FDecimalVector& V1, const FDecimalVector& V2) { return DistSquaredXY(V1, V2); }

	/**
	 * Compute pushout of a box from a plane.
	 *
	 * @param Normal The plane normal.
	 * @param Size The size of the box.
	 * @return Pushout required.
	 */
	static FDecimal BoxPushOut(const FDecimalVector& Normal, const FDecimalVector& Size);

	/**
	 * Min, Max, Min3, Max3 like FMath
	 */
	static FDecimalVector Min(const FDecimalVector& A, const FDecimalVector& B);
	static FDecimalVector Max(const FDecimalVector& A, const FDecimalVector& B);

	static FDecimalVector Min3(const FDecimalVector& A, const FDecimalVector& B, const FDecimalVector& C);
	static FDecimalVector Max3(const FDecimalVector& A, const FDecimalVector& B, const FDecimalVector& C);

	/**
	 * See if two normal vectors are nearly parallel, meaning the angle between them is close to 0 degrees.
	 *
	 * @param  Normal1 First normalized vector.
	 * @param  Normal1 Second normalized vector.
	 * @param  ParallelCosineThreshold Normals are parallel if absolute value of dot product (cosine of angle between them) is greater than or equal to this. For example: cos(1.0 degrees).
	 * @return true if vectors are nearly parallel, false otherwise.
	 */
	static bool Parallel(const FDecimalVector& Normal1, const FDecimalVector& Normal2, const FDecimal& ParallelCosineThreshold = UE_THRESH_NORMALS_ARE_PARALLEL);

	/**
	 * See if two normal vectors are coincident (nearly parallel and point in the same direction).
	 *
	 * @param  Normal1 First normalized vector.
	 * @param  Normal2 Second normalized vector.
	 * @param  ParallelCosineThreshold Normals are coincident if dot product (cosine of angle between them) is greater than or equal to this. For example: cos(1.0 degrees).
	 * @return true if vectors are coincident (nearly parallel and point in the same direction), false otherwise.
	 */
	static bool Coincident(const FDecimalVector& Normal1, const FDecimalVector& Normal2, const FDecimal& ParallelCosineThreshold = UE_THRESH_NORMALS_ARE_PARALLEL);

	/**
	 * See if two normal vectors are nearly orthogonal (perpendicular), meaning the angle between them is close to 90 degrees.
	 *
	 * @param  Normal1 First normalized vector.
	 * @param  Normal2 Second normalized vector.
	 * @param  OrthogonalCosineThreshold Normals are orthogonal if absolute value of dot product (cosine of angle between them) is less than or equal to this. For example: cos(89.0 degrees).
	 * @return true if vectors are orthogonal (perpendicular), false otherwise.
	 */
	static bool Orthogonal(const FDecimalVector& Normal1, const FDecimalVector& Normal2, const FDecimal& OrthogonalCosineThreshold = UE_THRESH_NORMALS_ARE_ORTHOGONAL);

	/**
	 * See if two planes are coplanar. They are coplanar if the normals are nearly parallel and the planes include the same set of points.
	 *
	 * @param Base1 The base point in the first plane.
	 * @param Normal1 The normal of the first plane.
	 * @param Base2 The base point in the second plane.
	 * @param Normal2 The normal of the second plane.
	 * @param ParallelCosineThreshold Normals are parallel if absolute value of dot product is greater than or equal to this.
	 * @return true if the planes are coplanar, false otherwise.
	 */
	static bool Coplanar(const FDecimalVector& Base1, const FDecimalVector& Normal1, const FDecimalVector& Base2, const FDecimalVector& Normal2, const FDecimal& ParallelCosineThreshold = UE_THRESH_NORMALS_ARE_PARALLEL);

	/**
	 * Triple product of three vectors: X dot (Y cross Z).
	 *
	 * @param X The first vector.
	 * @param Y The second vector.
	 * @param Z The third vector.
	 * @return The triple product: X dot (Y cross Z).
	 */
	static FDecimal Triple(const FDecimalVector& X, const FDecimalVector& Y, const FDecimalVector& Z);

	/**
	 * Generates a list of sample points on a Bezier curve defined by 2 points.
	 *
	 * @param ControlPoints	Array of 4 FVectors (vert1, controlpoint1, controlpoint2, vert2).
	 * @param NumPoints Number of samples.
	 * @param OutPoints Receives the output samples.
	 * @return The path length.
	 */
	static FDecimal EvaluateBezier(const FDecimalVector* ControlPoints, int32 NumPoints, TArray<FDecimalVector>& OutPoints);

	/**
	 * Converts a vector containing radian values to a vector containing degree values.
	 *
	 * @param RadVector	Vector containing radian values
	 * @return Vector  containing degree values
	 */
	static FDecimalVector RadiansToDegrees(const FDecimalVector& RadVector);

	/**
	 * Converts a vector containing degree values to a vector containing radian values.
	 *
	 * @param DegVector	Vector containing degree values
	 * @return Vector containing radian values
	 */
	static FDecimalVector DegreesToRadians(const FDecimalVector& DegVector);

	/**
	 * Given a current set of cluster centers, a set of points, iterate N times to move clusters to be central.
	 *
	 * @param Clusters Reference to array of Clusters.
	 * @param Points Set of points.
	 * @param NumIterations Number of iterations.
	 * @param NumConnectionsToBeValid Sometimes you will have long strings that come off the mass of points
	 * which happen to have been chosen as Cluster starting points.  You want to be able to disregard those.
	 */
	static void GenerateClusterCenters(TArray<FDecimalVector>& Clusters, const TArray<FDecimalVector>& Points, int32 NumIterations, int32 NumConnectionsToBeValid);


	bool Serialize(FStructuredArchive::FSlot Slot)
	{
		FString TempX, TempY, TempZ;
		if (Slot.GetUnderlyingArchive().IsLoading())
		{
			Slot << TempX;
			Slot << TempY;
			Slot << TempZ;
			if (!FDecimal::FromString(TempX, X) || !FDecimal::FromString(TempY, Y) || !FDecimal::FromString(TempZ, Z))
			{
				return false;
			}
		}
		else
		{
			TempX = X.ToString(10);
			TempY = Y.ToString(10);
			TempZ = Z.ToString(10);

			Slot << TempX;
			Slot << TempY;
			Slot << TempZ;
		}

		return true;
	}

	bool SerializeFromMismatchedTag(FName StructTag, FStructuredArchive::FSlot Slot);

	/**
	 * Network serialization function.
	 * FVectors NetSerialize without quantization (ie exact values are serialized). se the FVectors_NetQuantize etc (NetSerialization.h) instead.
	 *
	 * @see FVector_NetQuantize, FVector_NetQuantize10, FVector_NetQuantize100, FVector_NetQuantizeNormal
	 */
	bool NetSerialize(FArchive& Ar, class UPackageMap* Map, bool& bOutSuccess)
	{
		FString TempX, TempY, TempZ;
		if (Ar.IsLoading())
		{
			Ar << TempX << TempY << TempZ;
			if (!FDecimal::FromString(TempX, X) || !FDecimal::FromString(TempY, Y) || !FDecimal::FromString(TempZ, Z))
			{
				return false;
			}
		}
		else
		{
			TempX = X.ToString(10);
			TempY = Y.ToString(10);
			TempZ = Z.ToString(10);

			Ar << TempX << TempY << TempZ;
		}
		return true;
	}
};

/**
 * Multiplies a vector by a scaling factor.
 *
 * @param Scale Scaling factor.
 * @param V Vector to scale.
 * @return Result of multiplication.
 */
template <typename Type, TEMPLATE_REQUIRES(ARITHMETIC_WITH_DECIMAL_CONDITION(Type))>
FORCEINLINE FDecimalVector operator*(Type Scale, const FDecimalVector& V)
{
	return V.operator*(Scale);
}

/**
 * Creates a hash value from an FVector.
 *
 * @param Vector the vector to create a hash value for
 * @return The hash value from the components
 */
template<typename Type>
FORCEINLINE uint32 GetTypeHash(const FDecimalVector& Vector)
{
	return FCrc::MemCrc_DEPRECATED(&Vector, sizeof(Vector));
}
