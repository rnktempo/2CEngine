#include <stdio.h>
#include "engine/incl/twocengine.h"

tcengine_texture *ship_texture;
int x;

void update_func(tcengine_window* win) {
        tcengine_draw_texture(win, ship_texture, x, 0, 200, 200);
	x += 5;
}

int main() {
	x=0;
	tcengine_init();
	tcengine_window *window = tcengine_create_window("Ship war", 800, 600);
	tcengine_change_bg_color(window, 96, 128, 255, 255);

	ship_texture = tcengine_import_texture(window, "./ship_sprite.png");

	tcengine_run_loop(window, update_func);
	tcengine_close_window(window);

	return 0;
}
