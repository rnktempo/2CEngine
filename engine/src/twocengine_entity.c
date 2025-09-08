#include "twocengine_entity.h"

#include "twocengine_texture.h"
#include "twocengine_window.h"

tcengine_entity* tcengine_create_entity(tcengine_texture* texture, int x, int y) {
        tcengine_entity *ent = malloc(sizeof(tcengine_entity));

        ent->texture = texture;
        ent->x = x;
        ent->y = y;

	ent->visible = true;

        return ent;
}

void tcengine_draw_entity(tcengine_window* window, tcengine_entity* entity) {
	if (entity->visible) {
		SDL_Rect dst = {entity->x, entity->y, entity->texture->width, entity->texture->height};
		SDL_RenderCopy(window->sdl_renderer, entity->texture->sdl_texture, NULL, &dst);
	}
}

int tcengine_check_entity_collision(tcengine_entity* ent1, tcengine_entity* ent2) {
	int left1   = ent1->x;
    	int right1  = ent1->x + ent1->texture->width;
    	int top1    = ent1->y;
    	int bottom1 = ent1->y + ent1->texture->height;

    	int left2   = ent2->x;
    	int right2  = ent2->x + ent2->texture->width;
    	int top2    = ent2->y;
    	int bottom2 = ent2->y + ent2->texture->height;

    	if (right1 <= left2)  return 0;
    	if (left1 >= right2)  return 0;
    	if (bottom1 <= top2)  return 0;
    	if (top1 >= bottom2)  return 0;

    	return 1;
}
