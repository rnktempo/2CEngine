#include <stdio.h>
#include <stdlib.h>
#include "twocengine_window.h"

tcengine_window* tcengine_create_window(const char *title, int width, int height) {
        tcengine_window *win = malloc(sizeof(tcengine_window));
        if (!win) {
                printf("2CEngine detected that ram is full for creating a window!\n");
                return NULL;
        }

        win->title = title;

        win->width = width;
        win->height = height;

        win->sdl_window = SDL_CreateWindow(
                win->title,
                SDL_WINDOWPOS_CENTERED,
                SDL_WINDOWPOS_CENTERED,
                win->width,
                win->height,
                SDL_WINDOW_SHOWN
        );

        if(win->sdl_window) {
                printf("2CEngine created the window succesfully!\n");
        } else {
                printf("2CEngine had a problem while creating the window: %s\n", SDL_GetError()); free(win); return NULL;
        }

	win->sdl_renderer = SDL_CreateRenderer(win->sdl_window, -1, 0);

	if (!win->sdl_renderer) {
		printf("2CEngine had a problem while creating the renderer: %s\n", SDL_GetError());
		free(win);
		return NULL;
	}

        return win;
}

void tcengine_close_window(tcengine_window *win) {
	SDL_DestroyRenderer(win->sdl_renderer);
	printf("2CEngine has destroyed renderer\n");
	SDL_DestroyWindow(win->sdl_window);
        printf("2CEngine has destroyed window\n");
	SDL_Quit();

	printf("2CEngine has destroyed everything succesfully, now closing...\n");

	exit(0);
}

void tcengine_clear_window(tcengine_window *win) {
	SDL_RenderClear(win->sdl_renderer);
}

void tcengine_update_window(tcengine_window *win) {
	SDL_RenderPresent(win->sdl_renderer);
}
