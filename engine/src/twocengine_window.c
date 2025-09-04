#include <stdio.h>
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

        return win;
}

