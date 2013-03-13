#include "VMsimulator.h"
//1100110 record
//------------------------------------------------------------------------------
int main(int argc, char *argv[]){
	int i;
	
	if(! std_input_check(argc, argv))
		return EXIT_FAILURE;

	gl_pageID = 1;
	init_programs();
	for (i=0 ; i<gl_program_count; i++){
		printf("pid:%i  \t  initML: %i  \t  totalML:%i  \t  totalPages: %i P#:%i \t Flag:%i \n",\
				gl_programs[i].pid, \
				gl_programs[i].init_memorylocation, \
				gl_programs[i].total_memorylocation, \
				gl_programs[i].total_pages, \
				gl_programs[i].pagetable[gl_programs[0].init_memorylocation].pagenumber,\
				gl_programs[i].pagetable[gl_programs[0].init_memorylocation].validbid);
				//gl_programs[0] because it was the border point
	}
	run_programs();	
}
