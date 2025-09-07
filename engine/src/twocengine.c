#include "twocengine.h"
#include "twocengine_window.h"
#include <stdio.h>

void tcengine_init() {
	// SDL_Init(SDL_INIT_EVERYTHING); devuelve 1 si error

	if (SDL_Init(SDL_INIT_EVERYTHING)) {
		printf("Error while starting SDL: %s\n", SDL_GetError());
	} else {
		printf("2CEngine started SDL succesfully!\n");
	}

	if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)) {
		printf("Error while starting SDL_image: %s\n", IMG_GetError());
		SDL_Quit();
	}
}

void tcengine_delay(int ms) {
	SDL_Delay(ms);
}

void doKeyDown(tcengine_window* win, SDL_KeyboardEvent *event) {
	if (event->repeat == 0) {
		if (event->keysym.scancode == SDL_SCANCODE_W) {
			win->keyW = 1;
		}

		if (event->keysym.scancode == SDL_SCANCODE_A) {
			win->keyA = 1;
		}

                if (event->keysym.scancode == SDL_SCANCODE_S) {
                        win->keyS = 1;
                }

                if (event->keysym.scancode == SDL_SCANCODE_D) {
                        win->keyD = 1;
                }
	}
}

void doKeyUp(tcengine_window* win, SDL_KeyboardEvent *event) {
        if (event->repeat == 0) {
                if (event->keysym.scancode == SDL_SCANCODE_W) {
                        win->keyW = 0;
                }

                if (event->keysym.scancode == SDL_SCANCODE_A) {
                        win->keyA = 0;
                }

                if (event->keysym.scancode == SDL_SCANCODE_S) {
                        win->keyS = 0;
                }

                if (event->keysym.scancode == SDL_SCANCODE_D) {
                        win->keyD = 0;
                }
        }
}

void tcengine_run_loop(tcengine_window* win, tcengine_loop_func user_func) {
	int running = 1;
	SDL_Event event;

	while (running) {
		tcengine_clear_window(win);

		while (SDL_PollEvent(&event)) {
			switch (event.type) {
				case SDL_QUIT:
					running = 0;
					break;
				case SDL_KEYDOWN:
					doKeyDown(win, &event.key);
					break;
				case SDL_KEYUP:
					doKeyUp(win, &event.key);
					break;

				default:
					break;
			}
		}

		user_func(win);
		tcengine_delay(16); // ~60 FPS
		tcengine_update_window(win);
	}
}
