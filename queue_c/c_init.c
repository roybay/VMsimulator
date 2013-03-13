#include "../lib/queue_c.h"

int c_init(queue_c_t* c) {
	c->size = 0;
	c->head = NULL;
	return 0;
}
