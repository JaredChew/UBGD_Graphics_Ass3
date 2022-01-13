#include "assignment3_demo.h"

void Assignment3_Demo::init() {

	Utilities::Random::seedRandom();

	lightningLeft = new Lightning(0, 0, -1.5f, LIGHTNING_LENGTH, LIGHTNING_HEIGHT, LIGHTNING_WIDTH, LIGHTNING_SPLITS);
	lightningRight = new Lightning(0, 0, -1.5f, LIGHTNING_LENGTH, LIGHTNING_HEIGHT, LIGHTNING_WIDTH, LIGHTNING_SPLITS);

	wave = new Wave(-(WAVE_WIDTH * WAVE_SIZE_W) / 2, -3, -10, WAVE_WIDTH, WAVE_HEIGHT, WAVE_SIZE_W, WAVE_SIZE_H, WAVE_DEFAULT_H_FREQUENCY, WAVE_DEFAULT_SPEED);

	audio = new Audio<SPECTRUM_SIZE>("media/assignment3_audio.mp3");
	audio->playAudio(AudioLoop::forever);

	audioSpectrumLevelAverage = 0.0f;

	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); //Change if needed different background colour

}

void Assignment3_Demo::deinit() {

	delete lightningLeft;
	lightningLeft = nullptr;

	delete lightningRight;
	lightningRight = nullptr;

	delete wave;
	wave = nullptr;

	delete audio;
	audio = nullptr;

}

void Assignment3_Demo::drawAxis(const Matrix& viewMatrix) {

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

void Assignment3_Demo::calculateAudioSpectrumLevelAverage() {

	audioSpectrumLevelAverage = 0;

	for (int i = 0; i < AUDIO_CUBES; i++) {

		audioSpectrumLevelAverage += (audio->getSpectrumLeft(i) * audio->getSpectrumRight(i)) / 2;

	}

	audioSpectrumLevelAverage /= AUDIO_CUBES;

}

void Assignment3_Demo::initCube_AudioVisualiser(const float& x, const float& y, const float& z, const float& width, const float& height, const float& depth, const float& audioSpectrumFrequency) {

	GLfloat vertices[] = {

		//front (x, y, z)
		x - (width / 2), y - (height / 2), z + (depth / 2),
		x + (width / 2), y - (height / 2), z + (depth / 2),
		x - (width / 2), y + (height / 2) + audioSpectrumFrequency, z + (depth / 2),

		x - (width / 2), y + (height / 2) + audioSpectrumFrequency, z + (depth / 2),
		x + (width / 2), y + (height / 2) + audioSpectrumFrequency, z + (depth / 2),
		x + (width / 2), y - (height / 2), z + (depth / 2),

		//back (x, y, z)
		x - (width / 2), y - (height / 2), z - (depth / 2),
		x + (width / 2), y - (height / 2), z - (depth / 2),
		x + (width / 2), y + (height / 2) + audioSpectrumFrequency, z - (depth / 2),

		x + (width / 2), y + (height / 2) + audioSpectrumFrequency, z - (depth / 2),
		x - (width / 2), y + (height / 2) + audioSpectrumFrequency, z - (depth / 2),
		x - (width / 2), y - (height / 2), z - (depth / 2),

		//left (z, x, y)
		x - (width / 2), y - (height / 2), z + (depth / 2),
		x - (width / 2), y - (height / 2), z - (depth / 2),
		x - (width / 2), y + (height / 2) + audioSpectrumFrequency, z - (depth / 2),

		x - (width / 2), y + (height / 2) + audioSpectrumFrequency, z - (depth / 2),
		x - (width / 2), y + (height / 2), z + (depth / 2),
		x - (width / 2), y - (height / 2), z + (depth / 2),

		//right (z, x, y)
		x + (width / 2), y - (height / 2), z - (depth / 2),
		x + (width / 2), y - (height / 2), z + (depth / 2),
		x + (width / 2), y + (height / 2) + audioSpectrumFrequency, z + (depth / 2),

		x + (width / 2), y + (height / 2) + audioSpectrumFrequency, z + (depth / 2),
		x + (width / 2), y + (height / 2), z - (depth / 2),
		x + (width / 2), y - (height / 2), z - (depth / 2),

		//down (x,z,y)
		x - (width / 2), y - (height / 2), z - (depth / 2),
		x + (width / 2), y - (height / 2), z - (depth / 2),
		x + (width / 2), y - (height / 2), z + (depth / 2),

		x + (width / 2), y - (height / 2), z + (depth / 2),
		x - (width / 2), y - (height / 2), z + (depth / 2),
		x - (width / 2), y - (height / 2), z - (depth / 2),

		//up (x,z,y)
		x - (width / 2), y + (height / 2) + audioSpectrumFrequency, z - (depth / 2),
		x + (width / 2), y + (height / 2) + audioSpectrumFrequency, z - (depth / 2),
		x + (width / 2), y + (height / 2) + audioSpectrumFrequency, z + (depth / 2),

		x + (width / 2), y + (height / 2) + audioSpectrumFrequency, z + (depth / 2),
		x - (width / 2), y + (height / 2) + audioSpectrumFrequency, z + (depth / 2),
		x - (width / 2), y + (height / 2) + audioSpectrumFrequency, z - (depth / 2)

	};

	glEnableClientState(GL_VERTEX_ARRAY);
	//glEnableClientState(GL_COLOR_ARRAY);

	glVertexPointer(3, GL_FLOAT, 0, vertices);
	//glColorPointer(4, GL_UNSIGNED_BYTE, 0, colours);

	glDrawArrays(GL_TRIANGLES, 0, (108 / 3) - 1); //(sizeof(vertices) / sizeof(*vertices) * 3)); 

	glDisable(GL_COLOR_ARRAY);
	//glDisable(GL_VERTEX_ARRAY);

}

void Assignment3_Demo::drawAudioVisualiser(const Matrix& viewMatrix, const float& intensity) {

	static float r = 1;
	static float g = 1;
	static float b = 1;

	glColor3f(r, g, b);

	for (float i = 0; i < AUDIO_CUBES; i++) {

		float audioSprectrumLevel = (audio->getSpectrumLeft(i) * audio->getSpectrumRight(i)) / 2;

		if (audioSprectrumLevel * 100 > 0.5f) {
			r = Utilities::Random::randBetweenFloat(0, 1);
			g = Utilities::Random::randBetweenFloat(0, 1);
			b = Utilities::Random::randBetweenFloat(0, 1);
		}

		Transform::translate(viewMatrix , -(AUDIO_CUBES * AUDIO_CUBE_WIDTH) / 2 + (i * AUDIO_CUBE_WIDTH), 0.0f, 0.0f); //-audioSprectrumLevel * 1000

		initCube_AudioVisualiser(0, 0, 0, AUDIO_CUBE_WIDTH, AUDIO_CUBE_HEIGHT, AUDIO_CUBE_DEPTH, audioSprectrumLevel * 1000);

	}

	Transform::transformToDefault(viewMatrix);

}

void Assignment3_Demo::draw(const Matrix& viewMatrix) {

	drawAxis(viewMatrix);

	glLoadMatrixf((GLfloat*)viewMatrix.mVal);

	//enable wireframe mode
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	//default colour state
	glColor3f(1.0f, 1.0f, 1.0f);

	audio->update();

	calculateAudioSpectrumLevelAverage();

	drawAudioVisualiser(viewMatrix, 100);

	wave->draw(audioSpectrumLevelAverage * 100, audioSpectrumLevelAverage * 300);

	{ //Left lightning temp scope

		Matrix translate = Matrix::makeTranslationMatrix(-4.5f, 3.0f, (-2 + audioSpectrumLevelAverage * 1000));
		Matrix rotate = Matrix::makeRotateMatrix(90, Vector(0.0f, 0.0f, 1.0f));

		Matrix viewSpaceMatrix = viewMatrix * (translate * rotate);

		glLoadMatrixf((GLfloat*)viewSpaceMatrix.mVal);

		lightningLeft->draw(audioSpectrumLevelAverage * 100);

	} //End of left lightning temp scope

	Transform::transformToDefault(viewMatrix);

	{ //Right lightning temp scope

		Matrix translate = Matrix::makeTranslationMatrix(4.5f, 3.0f,(-2 + audioSpectrumLevelAverage * 1000));
		Matrix rotate = Matrix::makeRotateMatrix(90, Vector(0.0f, 0.0f, 1.0f));

		Matrix viewSpaceMatrix = viewMatrix * (translate * rotate);

		glLoadMatrixf((GLfloat*)viewSpaceMatrix.mVal);

		lightningRight->draw(audioSpectrumLevelAverage * 100);

	} //End of right lightning temp scope

	Transform::transformToDefault(viewMatrix);

}
