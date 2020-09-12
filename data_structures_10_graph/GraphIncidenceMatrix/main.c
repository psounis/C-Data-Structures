#include <stdio.h>
#include "graph.h"

int main()
{
	GRAPH g;
	int i,j;

	GR_init_from_file(&g, "graph2.graph");

	GR_print(g);

	GR_destroy(g);

	return 0;
}
