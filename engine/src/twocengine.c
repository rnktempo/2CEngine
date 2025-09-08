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

	if (!(TTF_Init() != 0)) {
		printf("Error while starting SDL_ttf: %s\n", TTF_GetError());
		SDL_Quit();
	}
}

void tcengine_delay(int ms) {
	SDL_Delay(ms);
}

void doKeyDown(tcengine_window* win, SDL_KeyboardEvent *event) {
	if (event->repeat == 0) {
		if (event->keysym.scancode == SDL_SCANCODE_Q) {
			win->keyQ = 1;
		}
                if (event->keysym.scancode == SDL_SCANCODE_W) {
                        win->keyW = 1;
                }
                if (event->keysym.scancode == SDL_SCANCODE_E) {
                        win->keyE = 1;
                }
                if (event->keysym.scancode == SDL_SCANCODE_R) {
                        win->keyR = 1;
                }
                if (event->keysym.scancode == SDL_SCANCODE_T) {
                        win->keyT = 1;
                }
                if (event->keysym.scancode == SDL_SCANCODE_Y) {
                        win->keyY = 1;
                }
                if (event->keysym.scancode == SDL_SCANCODE_U) {
                        win->keyU = 1;
                }
                if (event->keysym.scancode == SDL_SCANCODE_I) {
                        win->keyI = 1;
                }
                if (event->keysym.scancode == SDL_SCANCODE_O) {
                        win->keyO = 1;
                }
                if (event->keysym.scancode == SDL_SCANCODE_P) {
                        win->keyP = 1;
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
                if (event->keysym.scancode == SDL_SCANCODE_F) {
                        win->keyF = 1;
                }
                if (event->keysym.scancode == SDL_SCANCODE_G) {
                        win->keyG = 1;
                }
                if (event->keysym.scancode == SDL_SCANCODE_H) {
                        win->keyH = 1;
                }
                if (event->keysym.scancode == SDL_SCANCODE_J) {
                        win->keyJ = 1;
                }
                if (event->keysym.scancode == SDL_SCANCODE_K) {
                        win->keyK = 1;
                }
                if (event->keysym.scancode == SDL_SCANCODE_L) {
                        win->keyL = 1;
                }
                if (event->keysym.scancode == SDL_SCANCODE_Z) {
                        win->keyZ = 1;
                }
                if (event->keysym.scancode == SDL_SCANCODE_X) {
                        win->keyX = 1;
                }
                if (event->keysym.scancode == SDL_SCANCODE_C) {
                        win->keyC = 1;
                }
                if (event->keysym.scancode == SDL_SCANCODE_V) {
                        win->keyV = 1;
                }
                if (event->keysym.scancode == SDL_SCANCODE_B) {
                        win->keyB = 1;
                }
                if (event->keysym.scancode == SDL_SCANCODE_N) {
                        win->keyN = 1;
                }
                if (event->keysym.scancode == SDL_SCANCODE_M) {
                        win->keyM = 1;
                }


		if (event->keysym.scancode == SDL_SCANCODE_1) {
                        win->key1 = 1;
                }
                if (event->keysym.scancode == SDL_SCANCODE_2) {
                        win->key2 = 1;
                }
                if (event->keysym.scancode == SDL_SCANCODE_3) {
                        win->key3 = 1;
                }
                if (event->keysym.scancode == SDL_SCANCODE_4) {
                        win->key4 = 1;
                }
                if (event->keysym.scancode == SDL_SCANCODE_5) {
                        win->key5 = 1;
                }
                if (event->keysym.scancode == SDL_SCANCODE_6) {
                        win->key6 = 1;
                }
                if (event->keysym.scancode == SDL_SCANCODE_7) {
                        win->key7 = 1;
                }
                if (event->keysym.scancode == SDL_SCANCODE_8) {
                        win->key8 = 1;
                }
                if (event->keysym.scancode == SDL_SCANCODE_9) {
                        win->key9 = 1;
                }
                if (event->keysym.scancode == SDL_SCANCODE_0) {
                        win->key0 = 1;
                }
	}
}

void doKeyUp(tcengine_window* win, SDL_KeyboardEvent *event) {
        if (event->repeat == 0) {
		if (event->keysym.scancode == SDL_SCANCODE_Q) {
                        win->keyQ = 0;
                }
                if (event->keysym.scancode == SDL_SCANCODE_W) {
                        win->keyW = 0;
                }
                if (event->keysym.scancode == SDL_SCANCODE_E) {
                        win->keyE = 0;
                }
                if (event->keysym.scancode == SDL_SCANCODE_R) {
                        win->keyR = 0;
                }
                if (event->keysym.scancode == SDL_SCANCODE_T) {
                        win->keyT = 0;
                }
                if (event->keysym.scancode == SDL_SCANCODE_Y) {
                        win->keyY = 0;
                }
                if (event->keysym.scancode == SDL_SCANCODE_U) {
                        win->keyU = 0;
                }
                if (event->keysym.scancode == SDL_SCANCODE_I) {
                        win->keyI = 0;
                }
                if (event->keysym.scancode == SDL_SCANCODE_O) {
                        win->keyO = 0;
                }
                if (event->keysym.scancode == SDL_SCANCODE_P) {
                        win->keyP = 0;
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
                if (event->keysym.scancode == SDL_SCANCODE_F) {
                        win->keyF = 0;
                }
                if (event->keysym.scancode == SDL_SCANCODE_G) {
                        win->keyG = 0;
                }
                if (event->keysym.scancode == SDL_SCANCODE_H) {
                        win->keyH = 0;
                }
                if (event->keysym.scancode == SDL_SCANCODE_J) {
                        win->keyJ = 0;
                }
                if (event->keysym.scancode == SDL_SCANCODE_K) {
                        win->keyK = 0;
                }
                if (event->keysym.scancode == SDL_SCANCODE_L) {
                        win->keyL = 0;
                }
                if (event->keysym.scancode == SDL_SCANCODE_Z) {
                        win->keyZ = 0;
                }
                if (event->keysym.scancode == SDL_SCANCODE_X) {
                        win->keyX = 0;
                }
                if (event->keysym.scancode == SDL_SCANCODE_C) {
                        win->keyC = 0;
                }
                if (event->keysym.scancode == SDL_SCANCODE_V) {
                        win->keyV = 0;
                }
                if (event->keysym.scancode == SDL_SCANCODE_B) {
                        win->keyB = 0;
                }
                if (event->keysym.scancode == SDL_SCANCODE_N) {
                        win->keyN = 0;
                }
                if (event->keysym.scancode == SDL_SCANCODE_M) {
                        win->keyM = 0;
                }


                if (event->keysym.scancode == SDL_SCANCODE_1) {
                        win->key1 = 0;
                }
                if (event->keysym.scancode == SDL_SCANCODE_2) {
                        win->key2 = 0;
                }
                if (event->keysym.scancode == SDL_SCANCODE_3) {
                        win->key3 = 0;
                }
                if (event->keysym.scancode == SDL_SCANCODE_4) {
                        win->key4 = 0;
                }
                if (event->keysym.scancode == SDL_SCANCODE_5) {
                        win->key5 = 0;
                }
                if (event->keysym.scancode == SDL_SCANCODE_6) {
                        win->key6 = 0;
                }
                if (event->keysym.scancode == SDL_SCANCODE_7) {
                        win->key7 = 0;
                }
                if (event->keysym.scancode == SDL_SCANCODE_8) {
                        win->key8 = 0;
                }
                if (event->keysym.scancode == SDL_SCANCODE_9) {
                        win->key9 = 0;
                }
                if (event->keysym.scancode == SDL_SCANCODE_0) {
                        win->key0 = 0;
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
