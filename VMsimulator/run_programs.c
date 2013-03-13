#include "VMsimulator.h"

void run_programs(){
	switch (gl_page_alg){
	case FIFO:
		switch (gl_page_flag){
		case PLUS:
			prepaging_fifo_replacement();
			break;
		case MINUS:
			demand_fifo_replacement();
			break;
		}
		break;
	case LRU:
		switch (gl_page_flag){
		case PLUS:
			prepaging_lru_replacement();
			break;
		case MINUS:
			demand_lru_replacement();
			break;
		}
		break;
	case CLOCK:
		switch (gl_page_flag){
		case PLUS:
			prepaging_clock_replacement();
			break;
		case MINUS:
			demand_clock_replacement();
			break;
		}
		break;
	}
}	
