#include "../lib/queue_c.h"

int main(){


	queue_c_t* c;
	c_node* node;
	int *z;
	int k;
	int i[20] = {100,101,102,103,104,105,106,107,108,109, 
			   110,111,112,113,114,115,116,117,118,119};
	z = (int*)xmalloc(sizeof(int));

	c = (queue_c_t*)xmalloc(sizeof(queue_c_t));
	c_init(c);

	node = c->head;

	c_push(c, &i[0]);//100 1 
	c_push(c, &i[1]);//101 5
	c_push(c, &i[2]);//102 1
	c_push(c, &i[3]);//103 1
	c_push(c, &i[4]);//104 4
	c_push(c, &i[5]);//105 1
	c_push(c, &i[6]);//106 7
	c_push(c, &i[7]);//107 1
	c_push(c, &i[8]);//108 1
	c_push(c, &i[9]);//109 2
	//c->head->next->next->next->r =0;
	
	/*z = c_pop(c);	
	printf("pop :%i \n", z[0]);
	c_push(c, &i[14], 1);//114 1
	*/
	printf("c size:%i\n", c->size);

	for(k=0; k<10 ; k++){
		z = c_pop(c);	
		printf("pop :%i \n", z[0]);
	}
	printf("TEST MAIN\n");
	c_push(c, &i[0]);//100 1 
	c_push(c, &i[1]);//101 5
	c_push(c, &i[2]);//102 1
	c_push(c, &i[3]);//103 1
	c_push(c, &i[4]);//104 4
	c_push(c, &i[5]);//105 1
	c_push(c, &i[6]);//106 7
	c_push(c, &i[7]);//107 1
	c_push(c, &i[8]);//108 1
	c_push(c, &i[9]);//109 2
	c_node_update(c, &(i[4])); //104 5
	c_node_update(c, &(i[4])); //104 6
	c_node_update(c, &(i[4])); //104 7
	printf("update item\n");
	for(k=0; k<10 ; k++){
		z = c_pop(c);	
		printf("pop :%i \n", z[0]);
	}

	return 1;
}
