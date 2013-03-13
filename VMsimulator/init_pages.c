#include "VMsimulator.h"

void init_pages(int x){
	int i;
	int j;

	for(i=0; i < gl_programs[x].total_pages ; i++){
		gl_programs[x].pagetable[i].pagenumber = gl_pageID++;
		gl_programs[x].pagetable[i].validbid = FALSE;
	//	printf("%i\t", gl_programs[p].pagetable[i].validbid);
	}
	if (gl_programs[x].init_memorylocation > gl_programs[x].total_pages)
		j = gl_programs[x].total_pages;
	else
		j = gl_programs[x].init_memorylocation;

	for(i=0; i < j ; i++){
		gl_programs[x].pagetable[i].validbid = TRUE;
		switch (gl_page_alg){
		case FIFO:	
			q_push(gl_programs[x].q, &gl_programs[x].pagetable[i]);
			break;
		case LRU:
			p_push(gl_programs[x].p, &gl_programs[x].pagetable[i], 1);
			break;
		case CLOCK:
			c_push(gl_programs[x].c, &gl_programs[x].pagetable[i]);
			break;
		}
	}
}		
