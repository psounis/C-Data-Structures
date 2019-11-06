#include <stdio.h>
#include "circular_list.h"

main() 
{
	LIST_PTR list; 
	elem x; 
	
	CL_init(&list);
	
	CL_insert_start(&list, 4);
	CL_insert_start(&list, 3);
	CL_insert_start(&list, 2);
	CL_insert_start(&list, 1);
	CL_print(list);
	
	CL_get_i(list, 13, &x);
	printf("To 13o stoixeio einai: %d", x);
	
	CL_destroy(&list);
}
