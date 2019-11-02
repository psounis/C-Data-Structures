/* stack.h : Dilwseis stoivas */



#define TRUE 1
#define FALSE 0

#define STACK_SIZE 10      /* Megethos pinaka stoivas */

struct foititis{
	char onoma[80];
	int vathmos;
};

typedef struct foititis FOITITIS;

typedef FOITITIS elem;          /* typos dedomenwn stoivas */

struct stack{
   elem array[STACK_SIZE]; /* pinakas stoixeiwn       */
   int top;                /*koryfi tis stoivas       */
};

typedef struct stack STACK; /* Sinwnimo tis stoivas   */


void ST_init(STACK *s);
int ST_empty(STACK s);
int ST_full(STACK s);
int ST_push(STACK *s, elem x);
int ST_pop(STACK *s, elem *x);
