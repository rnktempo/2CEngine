#include "engine/incl/twocengine.h"
#include <stdio.h>

tcengine_texture* sky_texture;
tcengine_texture* ground_texture;

tcengine_text* titleText;

tcengine_entity* snailEntity;
tcengine_entity* playerEntity;

int playerGravity = 0;

void game_loop(tcengine_window* window) {
	tcengine_draw_texture(window, sky_texture, 0, 0);
	tcengine_draw_texture(window, ground_texture, 0, 300);
	tcengine_draw_text(window, titleText, 300, 50);
	tcengine_draw_entity(window, snailEntity);
	tcengine_draw_entity(window, playerEntity);

	snailEntity->x -=6;
	playerGravity += 1;
	playerEntity->y += playerGravity;
	if (snailEntity->x < -100) {snailEntity->x = 800;}

	if (tcengine_check_entity_collision(snailEntity, playerEntity)) {
		tcengine_close_window(window);
	}

	if (window->keyJ && playerEntity->y + playerEntity->texture->height >= 300) {
		playerGravity = -20;
	}

	if (playerEntity->y + playerEntity->texture->height >= 300) {
		playerEntity->y = 300 - playerEntity->texture->height;
	}
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
	tcengine_texture* snail_texture1 = tcengine_import_texture(window, "sprites/snail1.png", 72, 36);
	tcengine_texture* player_texture_walk1 = tcengine_import_texture(window, "sprites/player_walk_1.png", 64, 84);

	// ENTITIES
	snailEntity = tcengine_create_entity(snail_texture1, 600, 260);
	playerEntity = tcengine_create_entity(player_texture_walk1, 80, 200);

	tcengine_run_loop(window, game_loop);
	tcengine_close_window(window);

	return 0;
}
