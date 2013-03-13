#include "VMsimulator.h"

int std_input_check(int argc, char** argv){
	int r = TRUE;
	int i;

	if (argc<6){
		if (!my_strcmp("?", argv[1]) || !my_strcmp("help", argv[1]))
			r= std_input_error(0);
		else
			r = std_input_error(6-argc);	
	}else{	
		for (i=1; i<6; i++){
			r = std_param_check(argv[i], i);
			if (r != TRUE){
				r = std_input_error(i);
				return r;
			}				
		}
	}
	return r;	
}
