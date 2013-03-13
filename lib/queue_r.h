#ifndef _libqueue_r_
	#define _libqueue_r_
   
	#ifndef NULL
		#define NULL ((void*) 0)
	#endif /*NULL*/	
   
	#include <errno.h>  
	#include <stdio.h>
	#include <stdlib.h>
	#include <unistd.h>
	#include "../lib/my.h"	
/*----------------------------------------------------------*/
	typedef struct sq_node
	{
		void* object;
		struct sq_node *previous;
		struct sq_node *next;
	} 	q_node;
/*----------------------------------------------------------*/
	typedef struct squeue_r_t
	{
		q_node *head;
		int size;
	}	queue_r_t;
/*----------------------------------------------------------*/
	int q_init(queue_r_t *);
	int q_push(queue_r_t *, void *);
	void* q_pop(queue_r_t *);

/*----------------------------------------------------------*/
#endif /*_libqueue_r_*/
