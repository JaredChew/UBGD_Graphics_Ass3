#pragma once

#include "demo_base.h"

#include <windows.h>
#include <math.h>

#include "GameObject/lightning.h"
#include "GameObject/wave.h"

#include "audio.hpp"
#include "transform.h"

#define SPECTRUM_SIZE 256

#define AUDIO_CUBES 20
#define AUDIO_CUBE_WIDTH 0.25f
#define AUDIO_CUBE_HEIGHT 0.25f
#define AUDIO_CUBE_DEPTH 0.25f

#define WAVE_WIDTH 20
#define WAVE_HEIGHT 10
#define WAVE_SIZE_W 0.5f
#define WAVE_SIZE_H 0.5f
#define WAVE_DEFAULT_H_FREQUENCY 0.25f
#define WAVE_DEFAULT_SPEED 0.1f

#define LIGHTNING_LENGTH 3.0f
#define LIGHTNING_HEIGHT 0.5f
#define LIGHTNING_WIDTH 0.1f
#define LIGHTNING_SPLITS 3

class Assignment3_Demo : public DemoBase {

	private:
		Audio<SPECTRUM_SIZE>* audio;

		Lightning* lightningLeft;
		Lightning* lightningRight;

		Wave* wave;

		float audioSpectrumLevelAverage;

	private:
		void calculateAudioSpectrumLevelAverage();

		void drawAxis(const Matrix& viewMatrix);
		void initCube_AudioVisualiser(const float& x, const float& y, const float& z, const float& width, const float& height, const float& depth, const float& audioSpectrumFrequency);
		void drawAudioVisualiser(const Matrix& viewMatrix, const float& intensity);

	public:void init();
		void deinit();

		void draw(const Matrix& viewMatrix);

};