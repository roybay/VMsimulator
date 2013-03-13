#include "VMsimulator.h"

struct timeval time_stamp(){
	struct timeval tv;
	gettimeofday(&tv, NULL); 
		
	return tv;
}
