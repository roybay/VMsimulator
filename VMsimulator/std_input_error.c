#include "VMsimulator.h"

int std_input_error(int arg){
	if (arg == 0)
	{
		read_file("README.txt");
	}	
	else if (arg<6)
	{	
		my_str("Invalid input: ");
		my_int(arg);
		my_str(" parameter(s) missing\n");
		my_str("For more info:./VMsimulator ? or ./VMsimulator help\n");
	}
	else 
	{	
		my_int(arg-6);
		my_str(" parameter must be in a form of ./VMsimulator plist ptrace 2 FIFO +\n");
		my_str("For more info:./VMsimulator ? or ./VMsimulator help\n");
	}
	return FALSE;
}
