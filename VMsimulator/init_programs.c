#include "VMsimulator.h"

void init_programs(){
	FILE *fd;
	int i,j;

	gl_page_count = MAIN_MEMORY / gl_page_size;
	
	gl_program_count = get_instance_count(gl_plist);

	gl_programs = (t_program*)xmalloc(sizeof(t_program) * gl_program_count);
	fd = fopen(gl_plist, "r");
	if (fd == NULL)
		printf("Error<E1007>: File could not be opened.\n");

	for (i=0 ; i<gl_program_count ; i++){	
		if(fscanf(fd, "%i %i" , &gl_programs[i].pid, &gl_programs[i].total_memorylocation)!=2)
			printf("WARNING<W1001>: Having empty line in plist cause an inefficient memory distribution.\n");
		else{
			gl_programs[i].init_memorylocation = gl_page_count / (gl_program_count - i);
			gl_programs[i].total_pages = gl_programs[i].total_memorylocation / gl_page_size;
			if (gl_programs[i].total_pages * gl_page_size < gl_programs[i].total_memorylocation)
				gl_programs[i].total_pages++;
			gl_page_count -= gl_programs[i].init_memorylocation;
			gl_programs[i].pagetable = (t_page*)xmalloc(sizeof(t_page) * gl_programs[i].total_pages );
			switch (gl_page_alg){
			case FIFO:	
				gl_programs[i].q = (queue_r_t*)xmalloc(sizeof(queue_r_t)+1);
				q_init(gl_programs[i].q);
				break;
			case LRU:
				gl_programs[i].p = (queue_p_t*)xmalloc(sizeof(queue_p_t)+1);
				p_init(gl_programs[i].p);
				break;
			case CLOCK:
				gl_programs[i].c = (queue_c_t*)xmalloc(sizeof(queue_c_t)+1);
				c_init(gl_programs[i].c);
				break;
			}				
			init_pages(i);
		}
	}
	fclose(fd);	
}	
