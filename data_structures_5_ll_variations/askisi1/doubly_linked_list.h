/* double_linked_list.h : Dilwseis sindedemenis listas */

#define TRUE 1
#define FALSE 0

typedef int elem;          /* typos dedomenwn listas */

struct node{			   /* Typos komvou listas */
   elem data; 			   /* dedomena */
   struct node *next;      /* epomenos */
   struct node *prev;      /* proigoumenos */
};

typedef struct node LIST_NODE; /* Sinwnimo tou komvou listas */
typedef struct node *LIST_PTR; /* Sinwnimo tou deikti komvou */

void DLL_init(LIST_PTR *head);
int DLL_empty(LIST_PTR head);
elem DLL_data(LIST_PTR p);
int DLL_insert_start(LIST_PTR *head,elem x);
int DLL_insert_after(LIST_PTR p,elem x);
int DLL_delete_start(LIST_PTR *head, elem *x);
int DLL_delete_after(LIST_PTR previous, elem *x);
void DLL_print(LIST_PTR head);
void LL_destroy(LIST_PTR *head);

void DLL_print_reverse(LIST_PTR head);
