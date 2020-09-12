/* graph.c: Kwdikas tis vivliothikis grafoy (pin.geitniasis) */
#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

/* GR_init(): arxikopoiei to grafo */
void GR_init(GRAPH *g, int N)
{
	int i,j;
	g->N = N;
	g->array = (int **)malloc(sizeof(int*)*N);
	if(!g->array)
	{
		printf("Error Allocating Memory");
		exit(0);
	}
	for (i=0; i<N; i++)
	{
		g->array[i] = (int *)malloc(sizeof(int)*N);
		if (!g->array[i])
		{
			printf("Error Allocating Memory");
			exit(0);
		}
		for (j=0; j<N; j++)
			g->array[i][j] = 0;
	}
}

/* GR_print(): ektypwnei to grafo */
void GR_print(GRAPH g)
{
	int i,j;

	printf("    ");
	for (i=0; i<g.N; i++)
		printf("%3d", i);
	printf("\n");

	printf("    ");
	for (i=0; i<g.N; i++)
		printf("---", i);
	printf("\n");

	for (i=0; i<g.N; i++)
	{
		printf("%3d|", i);
		for (j=0; j<g.N; j++)
			printf("%3d", g.array[i][j]);
		printf("\n");
	}
}

/* GR_add_edge(): prosthiki akmis */
void GR_add_edge(GRAPH g, int vertex1, int vertex2)
{
	if (vertex1<0 || vertex1>g.N || vertex2<0 || vertex2>g.N)
	{
		printf("Error: index out of bounds");
		exit(0);
	}
	if (g.array[vertex1][vertex2]==1)
		printf("Error: H akmh (%d,%d) yparxei hdh", vertex1, vertex2);
	else
	{
		g.array[vertex1][vertex2]=1;
		g.array[vertex2][vertex1]=1;
	}
}

/* GR_destroy(): katastrefei to grafo */
void GR_destroy(GRAPH g)
{
    int i;
	for (i=0; i<g.N; i++)
		free(g.array[i]);
    free(g.array);
}

/* GR_init_from_file(): arxikopoiisi apo arxeio */
void GR_init_from_file(GRAPH *g, char *filename)
{
	int i,j;
	FILE *fp;

	fp = fopen(filename, "r");
	fscanf(fp,"%d", &g->N);

	g->array = (int **)malloc(sizeof(int*)*g->N);
	if(!g->array)
	{
		printf("Error Allocating Memory");
		exit(0);
	}

	for (i=0; i<g->N; i++)
	{
		g->array[i] = (int *)malloc(sizeof(int)*g->N);
		if (!g->array[i])
		{
			printf("Error Allocating Memory");
			exit(0);
		}
		for (j=0; j<g->N; j++)
			g->array[i][j] = 0;
	}

	while(!feof(fp))
	{
		fscanf(fp,"%d %d", &i, &j);
		GR_add_edge(*g, i, j);
	}

	fclose(fp);
}
