#include "Vector4.h"
#include <cmath>

Vector4::Vector4(const float X, const float Y, const float Z, const float W)
{
	x = X;
	y = Y;
	z = Z;
	w = W;
}

Vector4::Vector4(const Vector4& other)
{
	x = other.x;
	y = other.y;
	z = other.z;
	w = other.w;
}

// returns the magnitude of the vector
float Vector4::magnitude() const
{
	return std::sqrt(x * x + y * y + z * z + w * w);
}

// returns the squared magnitude of the vector
float Vector4::sqrMagnitude() const
{
	return (x * x + y * y + z * z + w * w);
}

// returns the normalized vector
Vector4 Vector4::normalized() const
{
	return (*this / magnitude());
}

// normalize this vector
void Vector4::normalize()
{
	*this /= magnitude();
}

// returns the dot product
float Vector4::dot(const Vector4& other)
{
	return(x * other.x + y * other.y + z * other.z + w * other.w);
}

// + overload
Vector4 Vector4::operator + (const Vector4& other) const
{
	return Vector4(x + other.x, y + other.y, z + other.z, w + other.w);
}

// - overload
Vector4 Vector4::operator - (const Vector4& other) const
{
	return Vector4(x - other.x, y - other.y, z - other.z, w - other.w);
}

// * overload
Vector4 Vector4::operator * (const float scaler) const
{
	return Vector4(x * scaler, y * scaler, z * scaler, w * scaler);
}

// / overload
Vector4 Vector4::operator / (const float scaler) const
{
	return Vector4(x / scaler, y / scaler, z / scaler, w / scaler);
}

// == overload
bool Vector4::operator == (const Vector4& other) const
{
	return (x == other.x && y == other.y && z == other.z && w == other.w);
}

// != overload
bool Vector4::operator != (const::Vector4& other) const
{
	return (x != other.x || y != other.y || z != other.z || w != other.w);
}

// += overload
void Vector4::operator += (const Vector4& other)
{
	x += other.x;
	y += other.y;
	z += other.z;
	w += other.w;
}

// -= overload
void Vector4::operator -= (const Vector4& other)
{
	x -= other.x;
	y -= other.y;
	z -= other.z;
	w -= other.w;
}

// *= overload
void Vector4::operator *= (const float scaler)
{
	x *= scaler;
	y *= scaler;
	z *= scaler;
	w *= scaler;
}

// /= overload
void Vector4::operator /= (const float scaler)
{
	x /= scaler;
	y /= scaler;
	z /= scaler;
	w /= scaler;
}

// = overload
Vector4 Vector4::operator = (const Vector4& other)
{
	x = other.x;
	y = other.y;
	z = other.z;
	z = other.w;
	return *this;
}