/* queue.h : Dilwseis ouras */

#define TRUE 1
#define FALSE 0

#define QUEUE_SIZE 5      /* Megethos pinaka ouras */

typedef char * elem;          /* typos dedomenwn ouras */

struct queue{
   elem array[QUEUE_SIZE]; /* pinakas stoixeiwn     */
   int start;			   /* arxi tis ouras 		*/
   int finish;             /* telos tis ouras       */
};

typedef struct queue QUEUE; /* Sinwnimo tis stoivas */


void QU_init(QUEUE *s);
int QU_empty(QUEUE s);
int QU_full(QUEUE s);
int QU_enqueue(QUEUE *s, elem x);
int QU_dequeue(QUEUE *s, elem *x);
