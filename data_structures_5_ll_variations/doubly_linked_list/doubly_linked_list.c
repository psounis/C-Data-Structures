/* linked_list.c: Kwdikas tis vivliothikis sindedemenis listas */
#include <stdio.h>
#include <stdlib.h>
#include "doubly_linked_list.h"

/* DLL_init(): arxikopoiei tin lista */
void DLL_init(LIST_PTR *head)
{
	*head=NULL;
}

/* DLL_empty(): epistrefei TRUE/FALSE
 *          analoga me to an i lista einai adeia */
int DLL_empty(LIST_PTR head)
{
	return head == NULL;
}

/* DLL_data(): epistrefei ta dedomena tou komvou
			  pou deixnei o deiktis p */
elem DLL_data(LIST_PTR p)
{
	return p->data;
}

/* DLL_insert_start(): Eisagei to stoixeio x
			stin arxi tis listas */
int DLL_insert_start(LIST_PTR *head,elem x)
{
	LIST_PTR newnode;
	
	newnode=(LIST_NODE *)malloc(sizeof(LIST_NODE));
	if (!newnode)
	{
		printf("Adynamia desmeusis mnimis");
		return FALSE;
	}
	newnode->data=x;

	newnode->next=*head;
	newnode->prev=NULL;
	*head=newnode;
	if (newnode->next!=NULL)
		newnode->next->prev=newnode; 
	return TRUE;
}

/* DLL_insert_after(): Eisagei to stoixeio x
			meta to stoixeio pou deixnei o p */
int DLL_insert_after(LIST_PTR p,elem x)
{
	LIST_PTR newnode;
	
	newnode=(LIST_NODE *)malloc(sizeof(LIST_NODE));
	if (!newnode)
	{
		printf("Adynamia desmeusis mnimis");
		return FALSE;
	}
	newnode->data=x;
	
	newnode->next=p->next;
	newnode->prev=p; 
	p->next=newnode;
	if (p->next!=NULL)
		p->next->prev=newnode; 
	return TRUE;
}

/* DLL_delete_start(): Diagrafei ton komvo poy deixnei 
	i kefali tis listas */
int DLL_delete_start(LIST_PTR *head, elem *x)
{
	LIST_PTR current;
	
	if (*head==NULL)
		return FALSE;
		
	current=*head;
	*x=current->data;
	
	(*head)=(*head)->next;
	if ((*head)!=NULL)
		(*head)->prev=NULL; 
		
	free(current);
	return TRUE;
}

/* DLL_delete_after(): Diagrafei ton epomeno tou 
				komvou poy deixnei o prev */
int DLL_delete_after(LIST_PTR previous, elem *x)
{
	LIST_PTR current;
	
	if (previous->next==NULL)
		return FALSE;
		
	current=previous->next;
	*x=current->data;
	
	previous->next=current->next;
	if (current->next!=NULL)
		current->next->prev=previous; 
		
	free(current);
	return TRUE;
}

/* DLL_print(): Typwnei ta periexomena mias
				syndedemenis listas	 */

void DLL_print(LIST_PTR head)
{
	LIST_PTR current;
	
	current=head;
	while(current!=NULL)
	{
		printf("%d ",current->data);
		current=current->next;
	}
}

/* DLL_destroy(): Apodesmeyei to xwro poy exei 
				desmeusei i lista	 */

void DLL_destroy(LIST_PTR *head)
{
	LIST_PTR ptr;
	
	while (*head!=NULL)
	{
		ptr=*head;
		*head=(*head)->next;
		free(ptr);
	}
}
