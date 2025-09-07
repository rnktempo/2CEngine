#include "twocengine_texture.h"
#include "twocengine_window.h"

tcengine_texture* tcengine_import_texture(tcengine_window *win, const char *location, int width, int height) {
	tcengine_texture *texture = malloc(sizeof(tcengine_texture));
	if (!texture) {
		printf("2CEngine has detected no sufficient ram to import the texture!\n");
		return NULL;
	}

	texture->location = location;

	texture->sdl_surface = IMG_Load(location);
	if (!texture->sdl_surface) {
		printf("2CEngine had an error while loading the texture: %s\n", IMG_GetError());
		return NULL;
	}

	printf("2CEngine loaded the texture succesfully!\n");

	texture->sdl_texture = SDL_CreateTextureFromSurface(win->sdl_renderer, texture->sdl_surface);
	SDL_FreeSurface(texture->sdl_surface);
	if (!texture->sdl_texture) {
		printf("2CEngine had an error while creating the texture: %s\n", IMG_GetError());
		return NULL;
	}

	texture->width = width;
	texture->height = height;

	printf("2CEngine created the texture succesfully!\n");

	return texture;
}

void tcengine_draw_texture(tcengine_window *win, tcengine_texture *texture, int x, int y) {
	SDL_Rect dst = {x, y, texture->width, texture->height};
	SDL_RenderCopy(win->sdl_renderer, texture->sdl_texture, NULL, &dst);
}
