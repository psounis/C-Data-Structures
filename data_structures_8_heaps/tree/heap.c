/* heap.c: Kwdikas tis vivliothikis dendrou */
#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

void swap (elem *x, elem *y)
{
	elem temp;
	
	temp=*x;
	*x=*y;
	*y=temp;
}


/* HEAP_init(): arxikopoiei to dendro */
void HEAP_init(HEAP *heap)
{
   heap->N=0;
}

/* HEAP_insert(): Eisagei to stoixeio x
			sto dentro-swros heap */
int HEAP_insert(HEAP *heap,elem x)
{
	int posParent, posCurrent;
	
	/* An den xwraei sto swro */
	if (heap->N == MAX_SIZE)
		return FALSE;
	
	/* 1. Eisagwgi tou neou komvou */
	heap->data[heap->N]=x;
	heap->N ++;
	
	/* 2. Antimetathesi me to gonea
		  efoson vrei mikroteri timi */
	posCurrent=heap->N - 1;
	while (posCurrent>0)
	{
		posParent=(posCurrent-1)/2;
		/* 2.1 Exei megaliteri timi apo gonea. Antimetathesi. */
		if (heap->data[posCurrent] > heap->data[posParent])
		{
			swap(&heap->data[posCurrent],&heap->data[posParent]);
			posCurrent=posParent;					
		}
		/* 2.2 Pire tin oristiki tou thesi. Diakopi */
		else
			break;
	}

	return TRUE;
}


/* HEAP_delete(): Diagrafei ti riza tou dendrou */
int HEAP_delete(HEAP *heap,elem *x)
{
	int posCurrent, posLeft, posRight, pos;
	elem temp;

	/* An o swros den einai adeios */
	if (heap->N == 0)
		return FALSE;
		
	/* 1. Sigkratisi (epistrofi) tis rizas */
	*x=heap->data[0];
	
	/* 2. Topothetisi tou teleutaiou stoixeiou sti riza */
	heap->data[0]=heap->data[heap->N - 1];
	heap->N --;
	
	
	posCurrent=0;
	while(posCurrent<heap->N)
	{
		posLeft=2*posCurrent+1;
		posRight=2*posCurrent+2;
		
		if (posLeft >= heap->N)
			posLeft=-1;
		if (posRight >= heap->N)	
			posRight=-1;
			
		/* 1. Den exei paidia */
		if (posLeft==-1 && posRight==-1)
			break;
		/* 2. Exei mono aristero paidi */
		else if (posLeft!=-1 && posRight==-1)
		{
			if (heap->data[posCurrent] < heap->data[posLeft])
			{
				swap(&heap->data[posCurrent],&heap->data[posLeft]);
				posCurrent=posLeft;
			}
			else 
				break;
		}
		/* 3. Exei dyo paidia */
		else // posLeft!=-1 && posRight!=-1
		{
			/*3.1 Eyresi tou megaliterou apo ta dyo paidia */
			if (heap->data[posLeft] < heap->data[posRight])
				pos=posRight;
			else
				pos=posLeft;
				
			/*3.2 Antimetathesi an einai mikrotero */
			if (heap->data[posCurrent] < heap->data[pos])
			{
				swap(&heap->data[posCurrent],&heap->data[pos]);
				posCurrent=pos;
			}
			else 
				break;
		}				
	}
}
	

