#include "../lib/queue_r.h"

void* q_pop(queue_r_t* q){
	void *object;
	q_node *node;

	if(q == NULL){
		return NULL;
	}		
	node = q->head->previous;
	object = node->object;

	if(q->size-- == 1){
		q->head = NULL;
	}else{
		q->head->previous = node->previous;
		node->previous->next = q->head;
	}	
	return (void*)object;
}
