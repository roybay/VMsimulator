#include "../lib/queue_r.h"

int q_init(queue_r_t* q){
	q->size = 0;
	q->head = NULL;
	
	return 0;
}
