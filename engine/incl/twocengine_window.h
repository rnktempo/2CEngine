#ifndef TWOCENGINE_WINDOW_H
#define TWOCENGINE_WINDOW_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

typedef struct tcengine_window {
        int width;
        int height;
        const char *title;

        SDL_Window *sdl_window;
        SDL_Renderer *sdl_renderer;

	int keyQ;
	int keyW;
        int keyE;
        int keyR;
        int keyT;
        int keyY;
        int keyU;
        int keyI;
        int keyO;
        int keyP;
        int keyA;
        int keyS;
        int keyD;
        int keyF;
        int keyG;
        int keyH;
        int keyJ;
        int keyK;
        int keyL;
        int keyZ;
        int keyX;
        int keyC;
        int keyV;
        int keyB;
        int keyN;
        int keyM;

        int keyComma;
        int keyDot;
	int keyShift;
	int keyTab;
	int keyBackspace;
	int keyEnter;

        int key1;
        int key2;
        int key3;
        int key4;
        int key5;
        int key6;
        int key7;
        int key8;
        int key9;
	int key0;
} tcengine_window;

tcengine_window* tcengine_create_window(const char *title, int width, int height);

void tcengine_close_window(tcengine_window *win);

void tcengine_clear_window(tcengine_window *win);
void tcengine_update_window(tcengine_window *win);
void tcengine_change_bg_color(tcengine_window *win, int r, int g, int b, int a);

#endif
