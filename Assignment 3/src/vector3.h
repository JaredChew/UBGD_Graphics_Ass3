#pragma once

#include <math.h>

class Vector3 {

public:
	float x;
	float y;
	float z;

public:
	Vector3(float x = 0.0f, float y = 0.0f, float z = 0.0f);

	~Vector3();

	Vector3 operator + (const Vector3&) const;
	Vector3 operator - (const Vector3&) const;

	Vector3 operator * (const float&) const;
	Vector3 operator / (const float&) const;

	void normalise();

	float magnitude() const;

	float dotProduct(const Vector3& b) const;
	Vector3 crossProduct(const Vector3&) const;

};