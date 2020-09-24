/* disjoint_sets.h : Ksena Sinola */
#include "linked_list.h"

struct extended_list
{
    LIST_PTR head;
    LIST_PTR last;
};

typedef struct extended_list EXTENDED_LIST;

struct disjoint
{
   elem *repr;	     	    /* pinakas antiproswpwn */
   EXTENDED_LIST *list;     /* pinakas listwn */
   int N;				    /* Plithos stoixeiwn */
};

typedef struct disjoint DISJOINT;


/* Basikes Prakseis disjoint sets */
void DS_init(DISJOINT *d, int N);
void DS_make_set(DISJOINT *d, elem x);
int DS_union(DISJOINT *d, elem x, elem y);
elem DS_find_set(DISJOINT d, elem x);
void DS_destroy(DISJOINT *d);

/* Deutereouses Prakseis disjoint sets */
void DS_print(DISJOINT d);

