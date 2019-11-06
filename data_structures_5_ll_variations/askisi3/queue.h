/* queue.h : Dilwseis sindedemenis listas */

#define TRUE 1
#define FALSE 0

typedef int elem;          /* typos dedomenwn listas */

struct node{			   /* Typos komvou listas */
   elem data; 			   /* dedomena */
   struct node *next;      /* epomenos */
};

typedef struct node LIST_NODE; /* Sinwnimo tou komvou listas */
typedef struct node *LIST_PTR; /* Sinwnimo tou deikti komvou */

struct queue{
	LIST_PTR start; 
	LIST_PTR end; 
};

typedef struct queue QUEUE; 

void LL_init(LIST_PTR *head);
int LL_empty(LIST_PTR head);
elem LL_data(LIST_PTR p);
int LL_insert_start(LIST_PTR *head,elem x);
int LL_insert_after(LIST_PTR p,elem x);
int LL_delete_start(LIST_PTR *head, elem *x);
int LL_delete_after(LIST_PTR prev, elem *x);
void LL_print(LIST_PTR head);
void LL_destroy(LIST_PTR *head);

void QU_init(QUEUE *q);
int QU_empty(QUEUE q);
int QU_enqueue(QUEUE *q,elem x);
int QU_dequeue(QUEUE *q,elem *x);

