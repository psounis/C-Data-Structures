#include <stdio.h>
#include "stack.h"

main() 
{
	STACK s; 
	elem x; 
	
	ST_init(&s);
	
	ST_push(&s, 1);
	ST_push(&s, 2);
	ST_push(&s, 3);
	
	ST_print(s);
	
	ST_pop(&s, &x);
	printf("\n\nTo stoixeio: %d\n", x);
	ST_print(s);
	
	ST_destroy(&s);
}
