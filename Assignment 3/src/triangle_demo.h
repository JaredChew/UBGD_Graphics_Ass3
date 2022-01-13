#ifndef _TRIANGLE_DEMO_H
#define _TRIANGLE_DEMO_H

#include "demo_base.h"

#include <windows.h>
#include <math.h>

#include "Utilities/random.h"
#include "Utilities/resourcesLoader.h"

#include "audio.h"

#define AUDIO_CUBES 20
#define SPECTRUM_SIZE 256

#define WAVE_WIDTH 20
#define WAVE_HEIGHT 10

class Assignment3_Demo : public DemoBase {

private:

	Audio<SPECTRUM_SIZE> *audio;

public:

	void init() {

		Utilities::Random::seedRandom();

		audio = new Audio<SPECTRUM_SIZE>("media/assignment3_audio.mp3");
		audio->playAudio(AudioLoop::forever);

		Utilities::ResourcesLoader::loadTexture("media/lightning.bmp", textureID);
		
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f); //Change if needed different background colour

	}

	void deinit() { }

	void drawAxis(const Matrix& viewMatrix) {

		glLoadMatrixf((GLfloat*)viewMatrix.mVal);

		glBegin(GL_LINES);

		glColor3f(1.0f, 0.3f, 0.3f);
		glVertex3f(0.0f, 0.0f, 0.0f);
		glVertex3f(1.0f, 0.0f, 0.0f);

		glColor3f(0.3f, 1.0f, 0.3f);
		glVertex3f(0.0f, 0.0f, 0.0f);
		glVertex3f(0.0f, 1.0f, 0.0f);

		glColor3f(0.3f, 0.3f, 1.0f);
		glVertex3f(0.0f, 0.0f, 0.0f);
		glVertex3f(0.0f, 0.0f, 1.0f);

		glEnd();

	}

	void draw(const Matrix& viewMatrix) {

		drawAxis(viewMatrix);

		glLoadMatrixf((GLfloat*)viewMatrix.mVal);

		//enable wireframe mode
		glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );

		//default colour state
		glColor3f(1.0f, 1.0f, 1.0f);

		audio->update();

		drawAudioVisualiser(viewMatrix, 1000);

		//drawLightningHorizontal2D(10, 0.5, 0.1, 10);

		float average = 0;

		for(int i = 0; i < AUDIO_CUBES; i++) {

			average += (audio->getSpectrumLeft(i) * audio->getSpectrumRight(i)) / 2;

		}

		//drawWave(-10, -5, -20, 20, 10, 1, 1, 0.2 + (average / AUDIO_CUBES) * 100, 0.1 + (average / AUDIO_CUBES) * 1000, 5);

	}

};

#endif
