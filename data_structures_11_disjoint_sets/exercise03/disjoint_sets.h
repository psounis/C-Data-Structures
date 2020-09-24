/* disjoint_sets.h : Ksena Sinola */

#define TRUE 1
#define FALSE 0

typedef int elem;

struct disjoint_node
{
    int data;
    int height;
    struct disjoint_node *parent;
};

typedef struct disjoint_node DISJOINT_NODE;
typedef struct disjoint_node *DISJOINT_PTR;

struct disjoint
{
   DISJOINT_PTR *array;      /* pinakas antiproswpwn */
   int N;				    /* Plithos deiktwn */
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

