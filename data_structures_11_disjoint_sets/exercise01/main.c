#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "disjoint_sets.h"

DISJOINT ConnectedComponents(GRAPH g);

int main()
{
    GRAPH g;
    DISJOINT d;

    GR_init_from_file(&g, "graph2.graph");
    printf("Initial Graph\n");
    GR_print(g);

    d = ConnectedComponents(g);

    printf("\nConnected components: ");
    DS_print(d);

    DS_destroy(&d);

	return 0;
}

DISJOINT ConnectedComponents(GRAPH g)
{
    DISJOINT d;
	int i, v, vertices;
	int *neighbors, neighbors_length;

    vertices = GR_vertices_count(g);
    DS_init(&d, vertices);

	for (v=0; v<vertices; v++)
    {
        GR_neighbors(g, v, &neighbors_length, &neighbors);
        for (i=0; i<neighbors_length; i++)
        {
            DS_union(&d, v, neighbors[i]);
        }
        free(neighbors);
    }

	return d;
}
