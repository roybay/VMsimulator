#include "../lib/queue_c.h"

int c_push(queue_c_t* c, void* obj){
	c_node* node;

	if(c == NULL){
		return -1;
	}
	if((void*)obj == NULL){
		return -2;
	}	
	
	node = (c_node*)xmalloc(sizeof(c_node)+1);
	node->object = (void*)obj;
	node->r = 1;
	
	if(c->size < 1){
		c->head = node;
		node->previous = node;
		node->next = node;
	}else{
		node->next = c->head;
		node->previous = c->head->previous;
		node->previous->next = node;
		node->next->previous = node;
		c->head = node->next;
	}
	c->size++;
	return 0;
}
