#include "transform.h"

void Transform::translate(const Matrix& viewMatrix, const float& x, const float& y, const float& z) {

	glLoadMatrixf((GLfloat*)(viewMatrix * Matrix::makeTranslationMatrix(x, y, z)).mVal);

}

void Transform::scale(const Matrix& viewMatrix, const float& x, const float& y, const float& z) {

	glLoadMatrixf((GLfloat*)(viewMatrix * Matrix::makeScaleMatrix(x, y, z)).mVal);

}

void Transform::rotate(const Matrix& viewMatrix, const float& angle, const float& x, const float& y, const float& z) {

	glLoadMatrixf((GLfloat*)(viewMatrix * Matrix::makeRotateMatrix(angle, Vector(x, y, z))).mVal);

}

void Transform::transformToDefault(const Matrix& viewMatrix) {

	Matrix translate = Matrix::makeTranslationMatrix(0.0f, 0.0f, 0.0f);
	Matrix scale = Matrix::makeScaleMatrix(1.0f, 1.0f, 1.0f);
	Matrix rotate = Matrix::makeRotateMatrix(0, Vector(1.0f, 1.0f, 1.0f));

	Matrix viewSpaceMatrix = viewMatrix * (translate * scale * rotate);

	glLoadMatrixf((GLfloat*)viewSpaceMatrix.mVal);

}