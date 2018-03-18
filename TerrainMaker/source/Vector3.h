#pragma once

class Vector3
{
public:

	// x y z values
	float x = 0.0f;
	float y = 0.0f;
	float z = 0.0f;

	// constructors
	Vector3(const float X = 0.0f, const float Y = 0.0f, const float Z = 0.0f);
	Vector3(const Vector3& other);

	// functions
	float magnitude() const;
	float sqrMagnitude() const;

	Vector3 normalized() const;
	void normalize();

	float dot(const Vector3& other);

	// operator overloads
	Vector3 operator + (const Vector3& other) const;
	Vector3 operator - (const Vector3& other) const;
	Vector3 operator * (const float scaler) const;
	Vector3 operator / (const float scaler) const;
	bool operator == (const Vector3& other) const;
	bool operator != (const Vector3& other) const;

	void operator += (const Vector3& other);
	void operator -= (const Vector3& other);
	void operator *= (const float scaler);
	void operator /= (const float scaler);
	Vector3 operator = (const Vector3& other);
};