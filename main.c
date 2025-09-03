#include <stdio.h>
#include "engine/incl/twocengine.h"

int main() {
	tcengine_init();
	tcengine_window *window = tcengine_create_window("Hello world", 800, 600);
	return 0;
}
