#ifndef _libqueue_c_
	#define _libqueue_c_
   
	#ifndef NULL
		#define NULL ((void*) 0)
	#endif /*NULL*/	
   
	#include <errno.h>  
	#include <stdio.h>
	#include <stdlib.h>
	#include <unistd.h>
	#include "../lib/my.h"	
/*----------------------------------------------------------*/
	typedef struct sc_node
	{
		int* object;
		struct sc_node *previous;
		struct sc_node *next;
		int r;
	} 	c_node;
/*----------------------------------------------------------*/
	typedef struct squeue_c_t
	{
		c_node *head;
		int size;
	}	queue_c_t;
/*----------------------------------------------------------*/
	int c_init(queue_c_t *);
	int c_push(queue_c_t *, void *);
	int c_node_update(queue_c_t *, void *);
	void* c_pop(queue_c_t *);	
/*----------------------------------------------------------*/
#endif /*_libqueue_c_*/
