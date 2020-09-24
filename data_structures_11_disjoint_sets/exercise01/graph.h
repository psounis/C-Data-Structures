/* graph.h : Dilwseis grafou (pin.geitniasis) */
#ifndef GRAPH_H
#define GRAPH_H
#include "linked_list.h"

struct graph 				/* Typos komvou listas */
{
   LIST_PTR *array;	     	/* pinakas listwn geitniasis */
   int N;				    /* Plithos komvwn */
};

typedef struct graph GRAPH;

/* Basikes Prakseis */
void GR_init(GRAPH *g, int N);
void GR_print(GRAPH g);
void GR_destroy(GRAPH g);
int GR_vertices_count(GRAPH g);
void GR_neighbors(GRAPH g, int vertex, int *length, elem **elements);

/* Deutereouses Prakseis */
void GR_init_from_file(GRAPH *g, char *filename);

#endif
