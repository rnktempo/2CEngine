#ifndef TWOCENGINE_WINDOW_H
#define TWOCENGINE_WINDOW_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

typedef struct tcengine_window {
        int width;
        int height;
        const char *title;

        SDL_Window *sdl_window;
        SDL_Renderer *sdl_renderer;
} tcengine_window;

tcengine_window* tcengine_create_window(const char *title, int width, int height);

void tcengine_close_window(tcengine_window *win);

void tcengine_clear_window(tcengine_window *win);
void tcengine_update_window(tcengine_window *win);
void tcengine_change_bg_color(tcengine_window *win, int r, int g, int b, int a);

#endif
