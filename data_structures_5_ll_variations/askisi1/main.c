#include <stdio.h>
#include "doubly_linked_list.h"

main() 
{
	LIST_PTR list; 
	
	DLL_init(&list);
	
	DLL_insert_start(&list, 3);
	DLL_insert_start(&list, 2);
	DLL_insert_start(&list, 1);
	
	DLL_print(list);
	printf("\n");
	DLL_print_reverse(list);
	
	DLL_destroy(&list);
	
}
