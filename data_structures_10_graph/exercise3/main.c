#include <stdio.h>
#include "graph.h"

int main()
{
	GRAPH g;
	int i, length;
	int *elements;

	GR_init_from_file(&g, "graph1.graph");
	GR_print(g);

	GR_neighbors(g, 4, &length, &elements);

	printf("Neighbors of 4: ");
	for (i=0; i<length; i++)
        printf("%d ", elements[i]);

	free(elements);
	GR_destroy(g);

	return 0;
}
