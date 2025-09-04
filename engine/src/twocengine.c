#include "twocengine.h"
#include <stdio.h>

void tcengine_init() {
	// SDL_Init(SDL_INIT_EVERYTHING); devuelve 1 si error

	if (SDL_Init(SDL_INIT_EVERYTHING)) {
		printf("Error while starting SDL: %s\n", SDL_GetError());
	} else {
		printf("2CEngine started SDL succesfully!\n");
	}
}
