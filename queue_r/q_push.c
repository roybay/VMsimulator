#include "../lib/queue_r.h"

int q_push(queue_r_t* q, void* obj){
	q_node* node;

	if(q == NULL){
		return -1;
	}
	if(obj == NULL){
		return -2;
	}	
	
	node = (q_node*)xmalloc(sizeof(q_node));
	node->object = obj;
	
	if(q->size < 1){
		q->head = node;
		node->previous = node;
		node->next = node;
	}else{
		node->next = q->head;
		node->previous = q->head->previous;
		node->previous->next = node;
		node->next->previous = node;
		q->head = node;
	}
	q->size++;
	return 0;
}
