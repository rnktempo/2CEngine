#ifndef TWOCENGINE_FONT_H
#define TWOCENGINE_FONT_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include "twocengine_window.h"

typedef struct tcengine_font {
	TTF_Font* sdl_font;
	int size;
} tcengine_font;

typedef struct tcengine_text {
	SDL_Surface* sdl_surface;
	SDL_Texture* sdl_texture;

	int color_r;
	int color_g;
	int color_b;
	int color_a;

	const char *label;
} tcengine_text;

tcengine_font* tcengine_import_font(const char *location, int size);
tcengine_text* tcengine_create_text(tcengine_window* window, tcengine_font* font, const char* text, int color_r, int color_g, int color_b, int color_a);

void tcengine_draw_text(tcengine_window* window, tcengine_text* text, int x, int y);

#endif
