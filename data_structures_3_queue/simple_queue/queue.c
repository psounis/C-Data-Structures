/* queue.c: Kwdikas tis vivliothikis ouras */
#include "queue.h"



/* QU_init(): arxikopoiei tin oura */
void QU_init(QUEUE *q)
{
	q->finish=-1;
}

/* QU_empty(): epistrefei TRUE/FALSE
 *          analoga me to an i oura einai adeia */
int QU_empty(QUEUE q)
{
	return q.finish==-1;
}

/* QU_full(): epistrefei TRUE/FALSE
 *          analoga me to an i oura einai gemati */
int QU_full(QUEUE q)
{
	return q.finish==QUEUE_SIZE-1;
}

/* QU_enqueue(): Eisagei to x stin oura q
 *	epistrefei TRUE: se periptwsi epitixias
 *		       FALSE: se periptwsi apotixias */
int QU_enqueue(QUEUE *q,elem x)
{
	if (QU_full(*q))
		return FALSE;
	else
	{
		q->finish++;
		q->array[q->finish]=x;
		return TRUE;
	}
}


/* QU_dequeue(): Kanei apomakrinsi tou prwtou stoixeiou tis ouras
 *	epistrefei TRUE: se periptwsi epitixias
 *		       FALSE: se periptwsi apotixias */
int QU_dequeue(QUEUE *q,elem *x)
{
	int i;
	
	if (QU_empty(*q))
		return FALSE;
	else
	{
		/* 1. Apothikeysi tou stoixeiou pou eksagetai*/
		*x=q->array[0];
		
		/* 2. Aristeri metakinisi twn stoixeiwn kata mia thesi */
		for (i=0; i<q->finish; i++)
			q->array[i]=q->array[i+1];

		/* 3. To finish meiwnetai kata 1 */
		q->finish--;
		
		return TRUE;
	}
}
