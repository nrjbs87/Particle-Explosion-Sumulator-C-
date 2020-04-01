#include <iostream>
#include <SDL.h>
#include "Screen.h"
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "Swarm.h"
using namespace std;
using namespace nb;

int main() {

	srand(time(NULL));

	Screen screen;

	if (!screen.init()) {

		cout << "Error init SDL" << endl;
	}

	Swarm swarm;

	bool quit = false;

	while (!quit) {
		// update particles

		// draw particles

		// sin will try to level any value passed to it to 1 or -1. good way to slowly
		// transition colors

		int elapsed = SDL_GetTicks();


		swarm.update(elapsed);

		unsigned char green =
		(unsigned char) ((1 + sin(elapsed * 0.0001)) * 128);
		unsigned char red = (unsigned char) ((1 + sin(elapsed * 0.0002)) * 128);
		unsigned char blue = (unsigned char) ((1 + sin(elapsed * 0.0003)) * 128);

		const Particle *const pParticles = swarm.getParticles();

		for (int i = 0; i < Swarm::NPARTICLES; i++) {
			Particle particle = pParticles[i];

			int x = (particle.m_x + 1) * Screen::SCREEN_WIDTH / 2;
			int y = particle.m_y * Screen::SCREEN_WIDTH / 2 + Screen::SCREEN_HEIGHT/2;

			screen.setPixel(x, y, red, green, blue);
		}

		screen.boxBlur();

		screen.update();

		// check for messages/events
		if (screen.processEvents() == false) {
			break;
		}

	}

	screen.close();

	return 0;
}
