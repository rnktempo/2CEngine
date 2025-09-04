#include <stdio.h>
#include "engine/incl/twocengine.h"

void update_func(tcengine_window* win) {

}

int main() {
	tcengine_init();
	tcengine_window *window = tcengine_create_window("Hello world", 800, 600);

	tcengine_run_loop(window, update_func);

	tcengine_close_window(window);
	return 0;
}
