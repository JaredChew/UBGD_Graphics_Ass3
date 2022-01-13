#include "Vector3.h"

Vector3::Vector3(float x, float y, float z) {

	this->x = x;
	this->y = y;
	this->z = z;

}

Vector3::~Vector3() { }

Vector3 Vector3::operator + (const Vector3 &passedValue) const {

	return Vector3(x + passedValue.x, y + passedValue.y, z + passedValue.z);

}

Vector3 Vector3::operator - (const Vector3 &passedValue) const {

	return Vector3(x - passedValue.x, y - passedValue.y, z - passedValue.z);

}

Vector3 Vector3::operator * (const float &passedValue) const {

	return Vector3(x * passedValue, y * passedValue, z * passedValue);

}

Vector3 Vector3::operator / (const float &passedValue) const {

	return Vector3(x / passedValue, y / passedValue,  z / passedValue);

}

float Vector3::magnitude() const {

	return (float) sqrt((x * x) + (y * y) + (z * z));

}

void Vector3::normalise() {

	float size = magnitude();

	x /= size;
	y /= size;
	z /= size;

}

float Vector3::dotProduct(const Vector3& passedValue) const {

	return ((this->x * passedValue.x) + (this->y * passedValue.y) + (this->z * passedValue.z));

}

Vector3 Vector3::crossProduct(const Vector3& passedValue) const {

	return Vector3( (y * passedValue.z) - (z * passedValue.y),
					(z * passedValue.x) - (x * passedValue.z),
					(x * passedValue.y) - (y * passedValue.x) );

}