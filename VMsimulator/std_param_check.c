#include "VMsimulator.h"

int std_param_check(char* ch, int i)
{	
	int j, k;
	bool r = TRUE;	
	int val;
	switch (i){
		case 1:
			if(my_strlen(ch)>20){
				printf("ERROR<E1001>: First parameter is out of boundary\n");
				r = FALSE;
			}
			gl_plist = (char*)xmalloc(sizeof(char)*(my_strlen(ch)+2));
			gl_plist[0] = '.';
			gl_plist[1] = '/';	
			my_strcpy(gl_plist+2, ch);
			break;				
		case 2:
			if(my_strlen(ch)>20){
				printf("ERROR<E1002>: Second parameter is out of boundary\n");
				r = FALSE;
			}
			gl_ptrace = (char*)xmalloc(sizeof(char)*(my_strlen(ch)+2));
			gl_ptrace[0] = '.';
			gl_ptrace[1] = '/';	
			my_strcpy(gl_ptrace+2, ch);
			break;				
		case 3:
			val = my_atoi(ch);
			for (j=0, k=1; j <= POWER; j++, k*=2){
				if (val == k){
					gl_page_size = val;
					return r;
				}
			}
			printf("ERROR<E1003>: Third parameter is invalid. Check help menu!\n");
			r=FALSE;	
			break;				
		case 4: 
			if (!my_strcmp(ch, "FIFO"))
				gl_page_alg = FIFO;
			else if (!my_strcmp(ch, "LRU"))
				gl_page_alg = LRU;
			else if (!my_strcmp(ch, "CLOCK"))
				gl_page_alg = CLOCK;
			else{
				printf("ERROR<E1004>: Fourth parameter is invalid. Check help menu!\n");				
				r = FALSE;
			}
			break;
		case 5:			
			if(*ch == '+')	
				gl_page_flag = PLUS;
			else if (*ch == '-')
				gl_page_flag = MINUS;
			else{
				printf("ERROR<E1005>: Fifth parameter is invalid. Check help menu!\n");
				r=FALSE;
			}
			break;
	}
	return r;
}	
