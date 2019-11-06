#include <stdio.h>
#include <stdlib.h>
#include "doubly_linked_list.h"

main() 
{
	int elem;
	LIST_PTR head,prev,current;
	
	DLL_init(&head);
	
	/* Eisagwgi tou "1" */
	DLL_insert_start(&head, 1);
	
	printf("\n");
	DLL_print(head);
	
	/* Eisagwgi tou "2" stin arxi */
	DLL_insert_start(&head, 2);
	
	printf("\n");
	DLL_print(head);
	
	/* Eisagwgi tou "3" meta to 1o stoixeio */
	DLL_insert_after(head, 3);
	
	printf("\n");
	DLL_print(head);
	
	/* Eisagwgi tou "4" meta to 2o stoixeio */
	DLL_insert_after(head->next, 4);
	
	printf("\n");
	DLL_print(head);
	
	/* Eisagwgi tou "5" stin arxi */
	DLL_insert_start(&head, 5);
	
	printf("\n");
	DLL_print(head);
	
	/* Eisagwgi tou "6" stin arxi */
	DLL_insert_start(&head, 6);
	
	printf("\n");
	DLL_print(head);
	
	/* Eisagwgi tou "7" sto telos */
	current=head;
	prev=current;
	while(current->next!=NULL)
	{
		prev=current;
		current=current->next;
	}
	DLL_insert_after(prev, 7);

	printf("\n");
	DLL_print(head);

	/* Diagrafi tou 1ou stoixeiou */
	DLL_delete_start(&head,&elem);
	
	printf("\n");
	DLL_print(head);

	/* Diagrafi tou teleytaiou stoixeiou */
	current=head;
	while(current->next!=NULL)
	{
		prev=current;
		current=current->next;
	}
	DLL_delete_after(prev,&elem);
	
	printf("\n");
	DLL_print(head);

	DLL_destroy(&head);
}
