#pragma once

#include <GLFW/glfw3.h>
#include <vector>

#include "../Utilities/resourcesLoader.h"

#include "../vector3.h"

class Wave {

	private:
		std::vector<GLfloat> waveVertices;
		std::vector<GLfloat> waveTexture;

		GLuint textureID;

		Vector3 startingPosition;

		int textureCoverage;

		int waveWidth;
		int waveHeight;

		float sizeWidth;
		float sizeHeight;

		float heightFrequency;
		float speed;

		float radian;

	private:
		void init();

	public:
		Wave(const float& x, const float& y, const float& z,
			const int& waveWidth, const int& waveHeight,
			const float& sizeWidth, const float& sizeHeight,
			const float& heightFrequency, const float& speed);

		~Wave();

		void initTexture(const char* directiory, const int& textureCoverage);

		void setHeightFrequency(const float& heightFrequency);
		void setSpeed(const float& speed);

		void draw(const float& affectHeightFrequency = 0, const float& affectSpeed = 0);

};