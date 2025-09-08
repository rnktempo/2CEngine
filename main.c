#include "engine/incl/twocengine.h"

tcengine_texture* sky_texture;
tcengine_texture* ground_texture;

tcengine_text* titleText;

void game_loop(tcengine_window* window) {
	tcengine_draw_texture(window, sky_texture, 0, 0);
	tcengine_draw_texture(window, ground_texture, 0, 300);
	tcengine_draw_text(window, titleText, 300, 50);
}

int main() {
	tcengine_init();
	tcengine_window* window = tcengine_create_window("Runner", 800, 400);

	// FONTS
	tcengine_font* gameFont = tcengine_import_font("./fonts/Pixeltype.ttf", 50);
	// TEXTS
	titleText = tcengine_create_text(window, gameFont, "My game", 0, 0, 0, 255);
	// TEXTURES
	sky_texture = tcengine_import_texture(window, "sprites/Sky.png", 800, 400);
	ground_texture = tcengine_import_texture(window, "sprites/ground.png", 800, 168);
	// ENTITIES

	tcengine_run_loop(window, game_loop);
	tcengine_close_window(window);
	return 0;
}
