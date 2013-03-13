#include "VMsimulator.h"

void prepaging_fifo_replacement(){
	FILE *fd;
	int k,j;
	t_page *pop;

	unsigned int count = 0;
	unsigned int pageFault = 0;
	printf("total record: %i \n", get_instance_count(gl_ptrace));
	fd = fopen(gl_ptrace, "r");
	if (fd == NULL)
		printf("Error<E1008>: File could not be opened.\n");

	while (fscanf(fd, "%i %i" , &k, &j)==2){
		j = j / gl_page_size;
		if (j == gl_programs[k].total_pages)
			j--;
		if (gl_programs[k].pagetable[j].validbid == FALSE){
//			printf("Page Fault : Program %i \t Page: %i  \n", k, gl_programs[k].pagetable[j].pagenumber);			
			pop = q_pop(gl_programs[k].q);
			pop->validbid = 0;
//			printf("Swap Page  : Program %i \t Page: %i  \n", k, pop->pagenumber);
			gl_programs[k].pagetable[j].validbid = 1;		
			q_push(gl_programs[k].q, &(gl_programs[k].pagetable[j]));  
			
			//find second page for pre_load
			while (gl_programs[k].pagetable[++j].validbid == 1 && j == gl_programs[k].total_pages){
				if (j == gl_programs[k].total_pages)
					j=-1;//it returns begining of the page table.
			}
//			printf("Pre Pageing: Program %i \t Page: %i  \n", k, gl_programs[k].pagetable[j].pagenumber);			
			pop = q_pop(gl_programs[k].q);
			pop->validbid = 0;
//			printf("Swap Page  : Program %i \t Page: %i  \n", k, pop->pagenumber);
			gl_programs[k].pagetable[j].validbid = 1;
			q_push(gl_programs[k].q, &(gl_programs[k].pagetable[j])); 
			pageFault++;
		}else{
	//		printf("In Memory : Program %i \t Page: %i  \n", k, gl_programs[k].pagetable[j].pagenumber);			
		}	
		count++;
	}

	printf("Alg: %i \tPaging: %i \tPage Sz: %i \tTot.Rec.: %u \tPgFault: %u \n ", gl_page_alg, gl_page_flag, gl_page_size, count, pageFault);
	fclose(fd);
}
