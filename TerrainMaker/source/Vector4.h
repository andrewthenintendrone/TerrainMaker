#pragma once

class Vector4
{
public:

	// x y z w values
	float x = 0.0f;
	float y = 0.0f;
	float z = 0.0f;
	float w = 0.0f;

	// constructors
	Vector4(const float X = 0.0f, const float Y = 0.0f, const float Z = 0.0f, const float W = 0.0f);
	Vector4(const Vector4& other);

	// functions
	float magnitude() const;
	float sqrMagnitude() const;

	Vector4 normalized() const;
	void normalize();

	float dot(const Vector4& other);

	// operator overloads
	Vector4 operator + (const Vector4& other) const;
	Vector4 operator - (const Vector4& other) const;
	Vector4 operator * (const float scaler) const;
	Vector4 operator / (const float scaler) const;
	bool operator == (const Vector4& other) const;
	bool operator != (const Vector4& other) const;

	void operator += (const Vector4& other);
	void operator -= (const Vector4& other);
	void operator *= (const float scaler);
	void operator /= (const float scaler);
	Vector4 operator = (const Vector4& other);
};