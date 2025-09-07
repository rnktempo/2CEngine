#include <stdio.h>
#include "engine/incl/twocengine.h"

tcengine_entity* ship_entity;
tcengine_entity* bullet_entity;

void update_func(tcengine_window* win) {
	tcengine_draw_entity(win, ship_entity);
	tcengine_draw_entity(win, bullet_entity);

	if (win->keyD == 1) {
		ship_entity->x += 5;
	}

        if (win->keyA == 1) {
                ship_entity->x -= 5;
        }

        if (win->keyW == 1) {
                ship_entity->y -= 5;
        }

        if (win->keyS == 1) {
                ship_entity->y += 5;
        }

	if (win->keyL == 1) {
		bullet_entity->x = ship_entity->x + 45;
		bullet_entity->y = ship_entity->y;
		bullet_entity->visible = true;
	}

	bullet_entity->y -= 20;
}

int main() {
	tcengine_init();
	tcengine_window *window = tcengine_create_window("Ship war", 800, 600);
	tcengine_change_bg_color(window, 96, 128, 255, 255);

	// textures
	tcengine_texture* ship_texture = tcengine_import_texture(window, "./ship_sprite.png", 100, 100);
	tcengine_texture* bullet_texture = tcengine_import_texture(window, "./bullet_sprite.png", 10, 10);
	// entities
	ship_entity = tcengine_create_entity(ship_texture, 350, 500);
	bullet_entity = tcengine_create_entity(bullet_texture, 50, 50);

	bullet_entity->visible = false;

	tcengine_run_loop(window, update_func);
	tcengine_close_window(window);

	return 0;
}
