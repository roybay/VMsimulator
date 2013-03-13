#include "../lib/my.h"
void* xmalloc(int n){
	void *p;
	p = malloc(n);
	if (p == NULL){
		my_str("Virtual Memory Exhausted!");
		exit(1);
	}
	return (p);
}
