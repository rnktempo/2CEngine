#include <stdio.h>
#include "engine/incl/twocengine.h"

int main() {
	tcengine_init();
	tcengine_window *window = tcengine_create_window("Hello world", 800, 600);
	tcengine_close_window(window);
	return 0;
}
