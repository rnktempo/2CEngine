#include "twocengine_font.h"

tcengine_font* tcengine_import_font(const char *location, int size) {
	tcengine_font* font = malloc(sizeof(tcengine_font));

	font->size = size;

	font->sdl_font = TTF_OpenFont(location, size);
	if (!font->sdl_font) {
		printf("2CEngine had a problem while loading a font: %s\n", TTF_GetError());
		TTF_Quit();
	}

	return font;
}

tcengine_text* tcengine_create_text(tcengine_window* window, tcengine_font* font, const char* text, int color_r, int color_g, int color_b, int color_a) {
	tcengine_text* textObj = malloc(sizeof(tcengine_text));

	textObj->color_r = color_r;
	textObj->color_g = color_g;
	textObj->color_b = color_b;
	textObj->color_a = color_a;

	textObj->label = text;

	SDL_Color color = {color_r, color_g, color_b, color_a};
	textObj->sdl_surface = TTF_RenderText_Solid(font->sdl_font, text, color);
	textObj->sdl_texture = SDL_CreateTextureFromSurface(window->sdl_renderer, textObj->sdl_surface);

	return textObj;
}

void tcengine_draw_text(tcengine_window* window, tcengine_text* text, int x, int y) {
	SDL_Rect rect = {x, y, text->sdl_surface->w, text->sdl_surface->h};
	SDL_RenderCopy(window->sdl_renderer, text->sdl_texture, NULL, &rect);
}
