#include "../lib/queue_c.h"

void* c_pop(queue_c_t* c){
	void* object;
	c_node* node;
	c_node* current;
		
	if(c == NULL){
		return NULL;
	}

	if(c->head == NULL){
		return NULL;
	}

	current = c->head;
	
	while(current->r != 0 && current->next != c->head){
		current = current->next; /*found the position to pop*/
	}
	
/*check if all nodes of the circle is 1*/
	if (current->next == c->head){
		current = c->head;
		do{
			current->r = 0;
			current = current->next;
		}while(current != c->head);
	}
 	c->head = current;
	node = c->head;
	object = (void*)node->object;

	if(c->size-- == 1){
		c->head = NULL;
	}else{
		c->head = node->next;
		c->head->previous = node->previous;
		node->previous->next = c->head;
	}
	return (void*)object;
}
