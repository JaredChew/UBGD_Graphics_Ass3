#pragma once

#include <GLFW/glfw3.h>
#include <vector>

#include "../audio.hpp"
#include "../matrix.h"

#include "../Utilities/random.h"

class AudioVisualiser {

	private:
		std::vector<GLuint> audioVisualiserVertices;
		//std::vector<GLuint> audioVisualiserColour;

		GLuint textureID;

		int rangeToDisplay;

	public:
		void drawCube(const float& x, const float& y, const float& z,
			const float& width, const float& height, const float& depth,
			const float& audioSpectrumFrequency);

};