#include <stdio.h>
#include "engine/incl/twocengine.h"

tcengine_entity* ship_entity;

void update_func(tcengine_window* win) {
	tcengine_draw_entity(win, ship_entity);

	if (win->keyD == 1) {
		ship_entity->x += 5;
	} else if (win->keyA == 1) {
		ship_entity->x -= 5;
	}
}

int main() {
	tcengine_init();
	tcengine_window *window = tcengine_create_window("Ship war", 800, 600);
	tcengine_change_bg_color(window, 96, 128, 255, 255);

	// textures
	tcengine_texture* ship_texture = tcengine_import_texture(window, "./ship_sprite.png", 100, 100);
	// entities
	ship_entity = tcengine_create_entity(ship_texture, 50, 50);

	tcengine_run_loop(window, update_func);
	tcengine_close_window(window);

	return 0;
}
