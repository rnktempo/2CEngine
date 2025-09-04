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
}

void tcengine_delay(int ms) {
	SDL_Delay(ms);
}

void tcengine_run_loop(tcengine_window* win, tcengine_loop_func user_func) {
	int running = 1;
	SDL_Event event;

	while (running) {
		tcengine_clear_window(win);

		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				running = 0;
			}
		}

		user_func(win);

		tcengine_update_window(win);
	}
}
