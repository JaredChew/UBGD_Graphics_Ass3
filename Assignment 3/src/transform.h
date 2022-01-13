#pragma once

#include <GLFW/glfw3.h>

#include "matrix.h"
#include "vector3.h"

struct Transform {

	static void translate(const Matrix& viewMatrix, const float& x, const float& y, const float& z);
	static void rotate(const Matrix& viewMatrix, const float& angle, const float& x, const float& y, const float& z);
	static void scale(const Matrix& viewMatrix, const float& x, const float& y, const float& z);

	static void transformToDefault(const Matrix& viewMatrix);

};