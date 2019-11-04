/* linked_list.c: Kwdikas tis vivliothikis sindedemenis listas */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linked_list.h"

/* LL_init(): arxikopoiei tin lista */
void LL_init(LIST_PTR *head)
{
	*head=NULL;
}

/* LL_empty(): epistrefei TRUE/FALSE
 *          analoga me to an i lista einai adeia */
int LL_empty(LIST_PTR head)
{
	return head == NULL;
}

/* LL_data(): epistrefei ta dedomena tou komvou
			  pou deixnei o deiktis p */
elem LL_data(LIST_PTR p)
{
	return p->data;
}

/* LL_insert_start(): Eisagei to stoixeio x
			stin arxi tis listas */
int LL_insert_start(LIST_PTR *head,elem x)
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
	*head=newnode;
	return TRUE;
}

/* LL_insert_after(): Eisagei to stoixeio x
			meta to stoixeio pou deixnei o p */
int LL_insert_after(LIST_PTR p,elem x)
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

/* LL_delete_start(): Diagrafei ton komvo poy deixnei 
	i kefali tis listas */
int LL_delete_start(LIST_PTR *head, elem *x)
{
	LIST_PTR current;
	
	if (*head==NULL)
		return FALSE;
		
	current=*head;
	*x=current->data;
	
	(*head)=(*head)->next;
	free(current);
	return TRUE;
}

/* LL_delete_after(): Diagrafei ton epomeno tou 
				komvou poy deixnei o prev */
int LL_delete_after(LIST_PTR prev, elem *x)
{
	LIST_PTR current;
	
	if (prev->next==NULL)
		return FALSE;
		
	current=prev->next;
	*x=current->data;
	
	prev->next=current->next;
	free(current);
	return TRUE;
}

/* LL_print(): Typwnei ta periexomena mias
				syndedemenis listas	 */

void LL_print(LIST_PTR head)
{
	LIST_PTR current;
	
	current=head;
	while(current!=NULL)
	{
		printf("(%s, %d)->",current->data.name, current->data.grade);
		current=current->next;
	}
	printf(".");
}

/* LL_destroy(): Apodesmeyei to xwro poy exei 
				desmeusei i lista	 */

void LL_destroy(LIST_PTR *head)
{
	LIST_PTR ptr;
	
	while (*head!=NULL)
	{
		ptr=*head;
		*head=(*head)->next;
		free(ptr);
	}
}

int LL_insert(LIST_PTR *head, elem x)
{
	LIST_PTR current, prev; 
	
	if (*head==NULL)
		return LL_insert_start(head, x);
	else
	{
		current=*head;
		prev=current;
		
		while(current!=NULL)
		{
			if (strcmp(current->data.name, x.name)>0)	
			{
				if (current==*head)
					return LL_insert_start(head, x);
				else 
					return LL_insert_after(prev, x);
			}
			
			prev=current; 
			current=current->next;
		}
		
		return LL_insert_after(prev, x);
	}	
}

int LL_delete(LIST_PTR *head, char *s)
{
	LIST_PTR current, prev; 
	elem temp; 

	if (*head==NULL)
		return FALSE; 
	
	current = *head; 
	prev=current; 
	while(current!=NULL)
	{
		
		if (strcmp(current->data.name,s)==0)
		{
			if (current==*head)
				return LL_delete_start(head, &temp);
			else 
				return LL_delete_after(prev, &temp);
		}
		
		prev = current; 
		current=current->next;
	}
	
	return FALSE;
}

double LL_average(LIST_PTR head)
{
	LIST_PTR current; 
	int sum, cnt; 
	
	current=head;
	sum=0; 
	cnt=0; 
	while (current!=NULL)
	{
		sum += current->data.grade; 
		cnt += 1; 
		current=current->next; 
	}
	
	return sum/(double)cnt; 
}

int LL_pass(LIST_PTR head)
{
	LIST_PTR current;
	int cnt; 
	
	current=head;
	cnt=0; 
	while (current!=NULL)
	{
		if (current->data.grade>=5)
			cnt++; 
		
		current=current->next;
	}
	
	return cnt; 
}

