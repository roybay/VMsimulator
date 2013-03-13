#include "../lib/queue_c.h"

int c_node_update(queue_c_t *c, void *obj){
	c_node *node;
	node = c->head;

	if(c == NULL){
		return -1;
	}
	if((void*)obj == NULL){
		return -2;
	}	
	
	while (node->object != (void*)obj){
		node = node->next;
	}	
	node->r = 1;
	c->head = node->next;
	return 0;
}
