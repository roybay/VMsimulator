#include "VMsimulator.h"

int get_instance_count(char* argc){
	int size=0;
	char ch;
	FILE *fd;
	fd = fopen(argc, "r");
	if (fd == NULL)
		printf("Error<E1006>: File could not be opened.\n");

	while((ch=fgetc(fd))!=EOF){
		if (ch=='\n'){
			size++; 
		}
	}	
	
	fclose(fd);
	return size;
}
