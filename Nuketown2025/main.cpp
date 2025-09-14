
#include <SDL3/SDL.h>
#include <SDL3/SDL_video.h>
#include <iostream>

#ifdef _WIN32
#include <windows.h>
#include <GL/gl.h>
#elif __APPLE__
#include <OpenGL/gl3.h>  // or gl.h depending on OS version
#else // e.g. Linux
#include <GL/gl.h>
#endif

int main() {

	SDL_Init(SDL_INIT_VIDEO);

	SDL_Window* window = NULL;
	SDL_Renderer* renderer = NULL;
	SDL_CreateWindowAndRenderer("Game", 500, 300, SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE, &window, &renderer);

	SDL_GLContext glcontext = SDL_GL_CreateContext(window);

	int time = 0;

	bool quit = false;
	while (!quit) {
		SDL_Event event;
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_EVENT_QUIT) {
				quit = true;
			}
		}

		time++;

		glClearColor(0, 0, 0, 1);
		glClear(GL_COLOR_BUFFER_BIT);

		glBegin(GL_TRIANGLES);

		glColor3f(1.0, 0.0, sin(time * 0.001));
		glVertex2f(-0.5f, -0.5f);
		glVertex2f(0.0f, 0.5f);
		glVertex2f(0.5f, -0.5f);

		glColor3f(sin(time * 0.001), 1.0, 0.0);
		glVertex2f(-0.3, -0.3f);
		glVertex2f(0.0f, 0.3f);
		glVertex2f(0.3f, -0.3f);

		glEnd();

		SDL_GL_SwapWindow(window);

	}

	SDL_GL_DestroyContext(glcontext);
	SDL_Quit();

	return 0;
}