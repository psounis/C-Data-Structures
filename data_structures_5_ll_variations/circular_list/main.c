#include <stdio.h>
#include <stdlib.h>
#include "circular_list.h"

main() 
{
	LIST_PTR list; 
	elem temp; 
	
	CL_init(&list);
	
	CL_insert_start(&list, 1);
	CL_print(list);
	printf("\n");
	
	CL_insert_start(&list, 2);
	CL_print(list);
	printf("\n");
	
	CL_insert_after(list->next, 3);
	CL_print(list);
	printf("\n");

	CL_insert_after(list, 4);
	CL_print(list);
	printf("\n");
	
	CL_delete_start(&list, &temp);
	CL_print(list);
	printf("\n");

	CL_delete_after(list->next, &temp);
	CL_print(list);
	printf("\n");

	CL_delete_start(&list, &temp);
	CL_print(list);
	printf("\n");

	CL_delete_start(&list, &temp);
	CL_print(list);
	printf("\n");
	
	CL_destroy(&list);
}
