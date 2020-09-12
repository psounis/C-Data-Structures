/* graph.h : Dilwseis grafou (pin.geitniasis) */

#define TRUE 1
#define FALSE 0

struct graph 				/* Typos komvou listas */
{
   int **array;		     	/* pin.geitniasis */
   int N;				    /* Plithos komvwn */
   int M;				    /* Plithos akmwn */
};

typedef struct graph GRAPH;

/* Basikes Prakseis */
void GR_init(GRAPH *g, int N, int M);
void GR_print(GRAPH g);
void GR_destroy(GRAPH g);

/* Deutereouses Prakseis */
void GR_init_from_file(GRAPH *g, char *filename);

