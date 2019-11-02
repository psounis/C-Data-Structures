/* queue.c: Kwdikas tis vivliothikis ouras */
#include "queue.h"



/* QU_init(): arxikopoiei tin oura */
void QU_init(QUEUE *q)
{
	q->start =-1;
	q->finish=-1;
}

/* QU_empty(): epistrefei TRUE/FALSE
 *          analoga me to an i oura einai adeia */
int QU_empty(QUEUE q)
{
	return q.start==-1;
}

/* QU_full(): epistrefei TRUE/FALSE
 *          analoga me to an i oura einai gemati */
int QU_full(QUEUE q)
{
	return q.start==(q.finish+1)%QUEUE_SIZE;
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
		if (QU_empty(*q))
		{
			q->start=0;
			q->finish=0;
		}
		else
		{
			q->finish=(q->finish+1)%QUEUE_SIZE;
		}
		q->array[q->finish]=x;
		return TRUE;
	} 
}


/* QU_dequeue(): Kanei apomakrinsi tou prwtou stoixeiou tis ouras
 *	epistrefei TRUE: se periptwsi epitixias
 *		       FALSE: se periptwsi apotixias */
int QU_dequeue(QUEUE *q,elem *x)
{
	if (QU_empty(*q))
		return FALSE;
	else
	{
		*x=q->array[q->start];
		
		if (q->start == q->finish) /* H oura adeiase */
		{
			q->start=-1;
			q->finish=-1;
		}
		else
		{
			q->start=(q->start+1)%QUEUE_SIZE;	
		}

		return TRUE;
	}
}
