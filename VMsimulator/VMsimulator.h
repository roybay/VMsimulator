#ifndef _VMsimulator_H_
#define _VMsimulator_H_
//------------------------------------------------------------
//Preprocessor
	#ifndef NULL
		#define NULL ((void*) 0)
	#endif /*NULL*/
	
	#define FALSE 0
	#define TRUE 1
	#define POWER 5

	#define FIFO 0
	#define LRU 1
	#define CLOCK 2
	#define PLUS 1
	#define MINUS 0

	#define MAIN_MEMORY 512	
//------------------------------------------------------------
//Libraries 
	#include <sys/time.h>
	#include <time.h>
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include <unistd.h>
	#include <fcntl.h>
	#include <errno.h>
	#include "../lib/my.h"
	#include "../lib/queue_c.h"	
	#include "../lib/queue_r.h"
	#include "../lib/queue_p.h"
		
//------------------------------------------------------------
//struct ~ type
	typedef int algorithms;
	typedef int bool;
	
	struct timeval tvbegin;

	typedef struct s_page{
		int pagenumber;
		bool validbid;
	} 	t_page;

	typedef struct s_program{
		int pid;
		int init_memorylocation;
		int total_memorylocation;
		int total_pages;
		t_page *pagetable;
		queue_r_t* q;	
		queue_p_t* p;	
		queue_c_t* c;	
	} 	t_program;

//------------------------------------------------------------
//gl_vars
	//init value
	char *gl_plist;
	char *gl_ptrace;
	int gl_page_size;
	algorithms gl_page_alg;
	bool gl_page_flag;
	
	//gl_vars
	t_program *gl_programs;
	int gl_page_count;
	int gl_program_count;
	int gl_pageID;


//------------------------------------------------------------
	int std_input_check(int, char**);
	int std_input_error(int);
	int std_param_check(char*, int);
	void read_file(char*);
	int get_instance_count(char*);
	void init_programs();
	void init_pages(int);
	void run_programs();
	void demand_fifo_replacement();
	void demand_clock_replacement();
	void demand_lru_replacement();
	void prepaging_fifo_replacement();
	void prepaging_clock_replacement();
	void prepaging_lru_replacement();

	struct timeval time_stamp();
//------------------------------------------------------------
#endif /*_VMsimulator_H_*/
