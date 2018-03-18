#include "Vector2.h"
#include <cmath>

Vector2::Vector2(const float X, const float Y)
{
	x = X;
	y = Y;
}

Vector2::Vector2(const Vector2& other)
{
	x = other.x;
	y = other.y;
}

// returns the magnitude of the vector
float Vector2::magnitude() const
{
	return std::sqrt(x * x + y * y);
}

// returns the squared magnitude of the vector
float Vector2::sqrMagnitude() const
{
	return (x * x + y * y);
}

// returns the normalized vector
Vector2 Vector2::normalized() const
{
	return (*this / magnitude());
}

// normalize this vector
void Vector2::normalize()
{
	*this /= magnitude();
}

// return the dot product
float Vector2::dot(const Vector2& other)
{
	return (x * other.x + y * other.y);
}

// + overload
Vector2 Vector2::operator + (const Vector2& other) const
{
	return Vector2(x + other.x, y + other.y);
}

// - overload
Vector2 Vector2::operator - (const Vector2& other) const
{
	return Vector2(x - other.x, y - other.y);
}

// * overload
Vector2 Vector2::operator * (const float scaler) const
{
	return Vector2(x * scaler, y * scaler);
}

// / overload
Vector2 Vector2::operator / (const float scaler) const
{
	return Vector2(x / scaler, y / scaler);
}

// == overload
bool Vector2::operator == (const Vector2& other) const
{
	return (x == other.x && y == other.y);
}

// != overload
bool Vector2::operator != (const::Vector2& other) const
{
	return (x != other.x || y != other.y);
}

// += overload
void Vector2::operator += (const Vector2& other)
{
	x += other.x;
	y += other.y;
}

// -= overload
void Vector2::operator -= (const Vector2& other)
{
	x -= other.x;
	y -= other.y;
}

// *= overload
void Vector2::operator *= (const float scaler)
{
	x *= scaler;
	y *= scaler;
}

// /= overload
void Vector2::operator /= (const float scaler)
{
	x /= scaler;
	y /= scaler;
}

// = overload
Vector2 Vector2::operator = (const Vector2& other)
{
	x = other.x;
	y = other.y;
	return *this;
}