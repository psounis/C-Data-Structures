/* linked_list.h : Dilwseis sindedemenis listas */

#define TRUE 1
#define FALSE 0

struct ELEM{
	char name[80];
	int grade; 
};

typedef struct ELEM elem;          /* typos dedomenwn listas */

struct node{			   /* Typos komvou listas */
   elem data; 			   /* dedomena */
   struct node *next;      /* epomenos */
};

typedef struct node LIST_NODE; /* Sinwnimo tou komvou listas */
typedef struct node *LIST_PTR; /* Sinwnimo tou deikti komvou */

void LL_init(LIST_PTR *head);
int LL_empty(LIST_PTR head);
elem LL_data(LIST_PTR p);
int LL_insert_start(LIST_PTR *head,elem x);
int LL_insert_after(LIST_PTR p,elem x);
int LL_delete_start(LIST_PTR *head, elem *x);
int LL_delete_after(LIST_PTR prev, elem *x);
void LL_print(LIST_PTR head);
void LL_destroy(LIST_PTR *head);

/* Deutereouses prakseis */
int LL_insert(LIST_PTR *head, elem x);
int LL_delete(LIST_PTR *head, char *s);
double LL_average(LIST_PTR head);
int LL_pass(LIST_PTR head);

