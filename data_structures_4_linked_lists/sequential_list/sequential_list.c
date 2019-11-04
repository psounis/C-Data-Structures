/* linked_list.c: Kwdikas tis vivliothikis akolouthiakis listas */
#include <stdio.h>
#include "sequential_list.h"

/* SL_init(): arxikopoiei tin lista */
void SL_init(LIST *l)
{
	l->N=0;
}

/* SL_empty(): epistrefei TRUE/FALSE
 *          analoga me to an i lista einai adeia */
int SL_empty(LIST l)
{
	return l.N == 0;
}

/* SL_data(): epistrefei ta dedomena tou komvou
			  tou index ind */
elem SL_data(LIST l, int ind)
{
	return l.data[ind];
}

/* SL_insert(): Eisagei to stoixeio x sti thesi ind */
int SL_insert(LIST *l, int ind, elem x)
{
	int i; 

	if (ind<0 || ind>l->N)
		return FALSE; 
	
	if (l->N < SIZE)
	{
		for (i=l->N; i>ind; i--)	
			l->data[i]=l->data[i-1];
		
		l->data[ind]=x; 
		l->N++;
		return TRUE; 
	}
	else
		return FALSE; 
}

/* SL_delete(): Diagrafei ta data pou vriskontai 
   sti thesi ind */
int SL_delete(LIST *l, int ind, elem *x)
{
	int i; 

	if (ind<0 || ind>=l->N)
		return FALSE; 
	
	*x = l->data[ind]; 
	
	for (i=ind; i<l->N; i++)	
		l->data[i]=l->data[i+1];
	
	l->N--;
	return TRUE;

}

/* SL_print(): Typwnei ta periexomena mias
				akolouthiakis listas	 */

void SL_print(LIST l)
{
	int i; 

	for (i=0; i<l.N; i++)	
		printf("%d ",l.data[i]);
}


