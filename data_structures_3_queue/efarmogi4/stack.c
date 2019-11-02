/* stack.c: Kwdikas tis vivliothikis stoivas */
#include "stack.h"



/* ST_init(): arxikopoiei ti lista */
void ST_init(STACK *s)
{
	s->top=-1;
}

/* ST_empty(): epistrefei TRUE/FALSE
 *          analoga me to an i stoiva einai adeia */
int ST_empty(STACK s)
{
	return s.top==-1;
}

/* ST_full(): epistrefei TRUE/FALSE
 *          analoga me to an i stoiva einai gemati */
int ST_full(STACK s)
{
	return s.top==STACK_SIZE-1;
}

/* ST_push(): Eisagei to x sti stoiva s
 *	epistrefei TRUE: se periptwsi epitixias
 *		       FALSE: se periptwsi apotixias */
int ST_push(STACK *s,elem x)
{
	if (ST_full(*s))
		return FALSE;
	else
	{
		s->top++;
		s->array[s->top]=x;
		return TRUE;
	}
}


/* ST_pop(): Kanei eksagwgi poy einai stin korifi tis listas
 *	epistrefei TRUE: se periptwsi epitixias
 *		       FALSE: se periptwsi apotixias */
int ST_pop(STACK *s,elem *x)
{
	if (ST_empty(*s))
		return FALSE;
	else
	{
		*x=s->array[s->top];
		s->top--;
		return TRUE;
	}
}
