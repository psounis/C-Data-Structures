/* graph.c: Kwdikas tis vivliothikis grafoy (pin.geitniasis) */
#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

/* GR_init(): arxikopoiei to grafo */
void GR_init(GRAPH *g, int N, int M)
{
	int i,j;
	g->N = N;
	g->M = M;
	g->array = (int **)malloc(sizeof(int*)*N);
	if(!g->array)
	{
		printf("Error Allocating Memory");
		exit(0);
	}
	for (i=0; i<N; i++)
	{
		g->array[i] = (int *)malloc(sizeof(int)*M);
		if (!g->array[i])
		{
			printf("Error Allocating Memory");
			exit(0);
		}
		for (j=0; j<M; j++)
			g->array[i][j] = 0;
	}
}

/* GR_print(): ektypwnei to grafo */
void GR_print(GRAPH g)
{
	int i,j;

	printf("    ");
	for (i=0; i<g.M; i++)
		printf("%3d", i);
	printf("\n");

	printf("    ");
	for (i=0; i<g.M; i++)
		printf("---");
	printf("\n");

	for (i=0; i<g.N; i++)
	{
		printf("%3d|", i);
		for (j=0; j<g.M; j++)
			printf("%3d", g.array[i][j]);
		printf("\n");
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
	int i,j,k;
	FILE *fp;

	fp = fopen(filename, "r");
	fscanf(fp,"%d %d", &g->N, &g->M);

	g->array = (int **)malloc(sizeof(int*)*g->N);
	if(!g->array)
	{
		printf("Error Allocating Memory");
		exit(0);
	}

	for (i=0; i<g->N; i++)
	{
		g->array[i] = (int *)malloc(sizeof(int)*g->M);
		if (!g->array[i])
		{
			printf("Error Allocating Memory");
			exit(0);
		}
		for (j=0; j<g->M; j++)
			g->array[i][j] = 0;
	}

	k=0;
	while(!feof(fp))
	{
		fscanf(fp,"%d %d", &i, &j);
		g->array[i][k] = 1;
		g->array[j][k] = 1;
		k++;
	}

	fclose(fp);
}
