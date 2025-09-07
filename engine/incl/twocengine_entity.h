#ifndef TWOCENGINE_ENTITY_H
#define TWOCENGINE_ENTITY_H

#include <stdbool.h>

#include <SDL2/SDL.h>

typedef struct tcengine_texture tcengine_texture;
typedef struct tcengine_window tcengine_window;

typedef struct tcengine_entity {
	tcengine_texture* texture;
	int x;
	int y;
	bool visible;
} tcengine_entity;

tcengine_entity* tcengine_create_entity(tcengine_texture* texture, int x, int y);
void tcengine_draw_entity(tcengine_window* window, tcengine_entity* entity);

#endif
