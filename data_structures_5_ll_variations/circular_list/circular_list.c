/* circular_list.c: Kwdikas tis vivliothikis sindedemenis listas */
#include <stdio.h>
#include <stdlib.h>
#include "circular_list.h"

/* CL_init(): arxikopoiei tin lista */
void CL_init(LIST_PTR *head)
{
	*head=NULL;
}

/* CL_empty(): epistrefei TRUE/FALSE
 *          analoga me to an i lista einai adeia */
int CL_empty(LIST_PTR head)
{
	return head == NULL;
}

/* CL_data(): epistrefei ta dedomena tou komvou
			  pou deixnei o deiktis p */
elem CL_data(LIST_PTR p)
{
	return p->data;
}

/* CL_insert_start(): Eisagei to stoixeio x
			stin arxi tis listas */
int CL_insert_start(LIST_PTR *head,elem x)
{
	LIST_PTR newnode, last;
	// 1
	newnode=(LIST_NODE *)malloc(sizeof(LIST_NODE));
	if (!newnode)
	{
		printf("Adynamia desmeusis mnimis");
		return FALSE;
	}
	newnode->data=x;

	if (*head == NULL)
	{   // 2
		newnode->next=newnode; 
		*head=newnode;
	}
	else
	{
		// 3.1 
		last = *head;
		while (last->next!=*head)
			last=last->next;
		last->next=newnode;
			
		// 3.2 
		newnode->next=*head;
		
		// 3.3
		*head=newnode;
	}
	
	return TRUE;
}

/* CL_insert_after(): Eisagei to stoixeio x
			meta to stoixeio pou deixnei o p */
int CL_insert_after(LIST_PTR p,elem x)
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
	p->next=newnode;
	return TRUE;
}

/* CL_delete_start(): Diagrafei ton komvo poy deixnei 
	i kefali tis listas */
int CL_delete_start(LIST_PTR *head, elem *x)
{
	LIST_PTR next, last;
	
	// 0 stoixeia
	if (*head==NULL)
		return FALSE;
		
	// 1 stoixeio
	if (*head==(*head)->next)
	{
		*x=(*head)->data;
		free(*head);
		*head=NULL;
		return TRUE; 
	}
	// >=2 stoixeia
	last=(*head)->next; 
	while (last->next!=(*head))
		last=last->next;
	last->next=(*head)->next;
	
	*x=(*head)->data; 
	free(*head);
	(*head)=last->next;
	return TRUE;
}

/* CL_delete_after(): Diagrafei ton komvo
                      poy deixnei o current */
int CL_delete_after(LIST_PTR current, elem *x)
{
	LIST_PTR prev;
	
	while (prev->next!=current)
		prev=prev->next;
		
	*x=current->data;
	
	prev->next=current->next;
	free(current);
	return TRUE;
}

/* CL_print(): Typwnei ta periexomena tis listas	 */
void CL_print(LIST_PTR head)
{
	LIST_PTR current;
	
	if (head!=NULL)
	{
		printf("%d ", head->data);
		
		current=head->next;
		while(current!=head)
		{
			printf("%d ",current->data);
			current=current->next;
		}
	}
}

/* CL_destroy(): Apodesmeyei to xwro poy exei 
				desmeusei i lista	 */
void CL_destroy(LIST_PTR *head)
{
	LIST_PTR ptr;
	elem temp;
	
	while (*head!=NULL)
		CL_delete_start(head, &temp);
}
