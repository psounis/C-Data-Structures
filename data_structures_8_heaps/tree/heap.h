/* heap.h : Dilwseis dendrou-swrou */

#define TRUE 1
#define FALSE 0
#define MAX_SIZE 31

typedef int elem;          /* typos dedomenwn dendrou*/

struct heap_tree{	       /* Dendro-Swros */
   elem data[MAX_SIZE];    /* dedomena */
   int N;                  /* plithos stoixeiwn */
};

typedef struct heap_tree HEAP; /* Sinwnimo tou swrou */

void swap (elem *x, elem *y);

void HEAP_init(HEAP *tree);
int HEAP_insert(HEAP *heap,elem x);
int HEAP_delete(HEAP *heap,elem *x);
