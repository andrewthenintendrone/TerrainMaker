#include "Vector3.h"
#include <cmath>

Vector3::Vector3(const float X, const float Y, const float Z)
{
	x = X;
	y = Y;
	z = Z;
}

Vector3::Vector3(const Vector3& other)
{
	x = other.x;
	y = other.y;
	z = other.z;
}

// returns the magnitude of the vector
float Vector3::magnitude() const
{
	return std::sqrt(x * x + y * y + z * z);
}

// returns the squared magnitude of the vector
float Vector3::sqrMagnitude() const
{
	return (x * x + y * y + z * z);
}

// returns the normalized vector
Vector3 Vector3::normalized() const
{
	return (*this / magnitude());
}

// normalize this vector
void Vector3::normalize()
{
	*this /= magnitude();
}
// returns the dot product
float Vector3::dot(const Vector3& other)
{
	return(x * other.x + y * other.y + z * other.z);
}

// + overload
Vector3 Vector3::operator + (const Vector3& other) const
{
	return Vector3(x + other.x, y + other.y, z + other.z);
}

// - overload
Vector3 Vector3::operator - (const Vector3& other) const
{
	return Vector3(x - other.x, y - other.y, z - other.z);
}

// * overload
Vector3 Vector3::operator * (const float scaler) const
{
	return Vector3(x * scaler, y * scaler, z * scaler);
}

// / overload
Vector3 Vector3::operator / (const float scaler) const
{
	return Vector3(x / scaler, y / scaler, z / scaler);
}

// == overload
bool Vector3::operator == (const Vector3& other) const
{
	return (x == other.x && y == other.y && z == other.z);
}

// != overload
bool Vector3::operator != (const::Vector3& other) const
{
	return (x != other.x || y != other.y || z != other.z);
}

// += overload
void Vector3::operator += (const Vector3& other)
{
	x += other.x;
	y += other.y;
	z += other.z;
}

// -= overload
void Vector3::operator -= (const Vector3& other)
{
	x -= other.x;
	y -= other.y;
	z -= other.z;
}

// *= overload
void Vector3::operator *= (const float scaler)
{
	x *= scaler;
	y *= scaler;
	z *= scaler;
}

// /= overload
void Vector3::operator /= (const float scaler)
{
	x /= scaler;
	y /= scaler;
	z /= scaler;
}

// = overload
Vector3 Vector3::operator = (const Vector3& other)
{
	x = other.x;
	y = other.y;
	z = other.z;
	return *this;
}