#ifndef TWOCENGINE_TEXTURE_H
#define TWOCENGINE_TEXTURE_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "twocengine.h"

typedef struct tcengine_texture {
	const char *location;

	SDL_Surface *sdl_surface;
	SDL_Texture *sdl_texture;
} tcengine_texture;

tcengine_texture* tcengine_import_texture(tcengine_window *win, const char *location);

void tcengine_draw_texture(tcengine_window *win, tcengine_texture *texture, int x, int y, int w, int h);

#endif
