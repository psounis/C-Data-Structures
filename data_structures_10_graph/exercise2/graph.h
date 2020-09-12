/* graph.h : Dilwseis grafou (pin.geitniasis) */

#define TRUE 1
#define FALSE 0

struct graph 				/* Typos komvou listas */
{
   int **array;		     	/* pin.geitniasis */
   int N;				    /* Plithos komvwn */
};

typedef struct graph GRAPH;

/* Basikes Prakseis */
void GR_init(GRAPH *g, int N);
void GR_print(GRAPH g);
void GR_add_edge(GRAPH g, int vertex1, int vertex2, int weight);
void GR_destroy(GRAPH g);

/* Deutereouses Prakseis */
void GR_init_from_file(GRAPH *g, char *filename);
int GR_edges(GRAPH g);

