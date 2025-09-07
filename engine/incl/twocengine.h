#ifndef TWOCENGINE_H
#define TWOCENGINE_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "twocengine_window.h"
#include "twocengine_texture.h"
#include "twocengine_entity.h"

typedef void (*tcengine_loop_func)(tcengine_window* win);

void tcengine_init();
void tcengine_delay();

void tcengine_run_loop(tcengine_window* win, tcengine_loop_func user_func);

#endif
