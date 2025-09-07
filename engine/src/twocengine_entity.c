#include "twocengine_entity.h"

#include "twocengine_texture.h"
#include "twocengine_window.h"

tcengine_entity* tcengine_create_entity(tcengine_texture* texture, int x, int y) {
        tcengine_entity *ent = malloc(sizeof(tcengine_entity));

        ent->texture = texture;
        ent->x = x;
        ent->y = y;

        return ent;
}

void tcengine_draw_entity(tcengine_window* window, tcengine_entity* entity) {
	SDL_Rect dst = {entity->x, entity->y, entity->texture->width, entity->texture->height};
	SDL_RenderCopy(window->sdl_renderer, entity->texture->sdl_texture, NULL, &dst);
}
