#pragma once

class Vector2
{
public:

	// x y values
	float x = 0.0f;
	float y = 0.0f;

	// constructors
	Vector2(const float X = 0.0f, const float Y = 0.0f);
	Vector2(const Vector2& other);

	// functions
	float magnitude() const;
	float sqrMagnitude() const;

	Vector2 normalized() const;
	void normalize();

	float dot(const Vector2& other);

	// operator overloads
	Vector2 operator + (const Vector2& other) const;
	Vector2 operator - (const Vector2& other) const;
	Vector2 operator * (const float scaler) const;
	Vector2 operator / (const float scaler) const;
	bool operator == (const Vector2& other) const;
	bool operator != (const Vector2& other) const;

	void operator += (const Vector2& other);
	void operator -= (const Vector2& other);
	void operator *= (const float scaler);
	void operator /= (const float scaler);
	Vector2 operator = (const Vector2& other);
};