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

void CL_init(LIST_PTR *head);
int CL_empty(LIST_PTR head);
elem CL_data(LIST_PTR p);
int CL_insert_start(LIST_PTR *head,elem x);
int CL_insert_after(LIST_PTR p,elem x);
int CL_delete_start(LIST_PTR *head, elem *x);
int CL_delete_after(LIST_PTR prev, elem *x);
void CL_print(LIST_PTR head);
void CL_destroy(LIST_PTR *head);

int CL_get_i(LIST_PTR head, int n, elem *x);

