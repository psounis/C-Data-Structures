#include <stdio.h>
#include <stdlib.h>
#include "disjoint_sets.h"

/* Basikes Prakseis */
void DS_init(DISJOINT *d, int N)
{
    int i;

    d->N = N;

    d->array = (DISJOINT_PTR *)malloc(sizeof(DISJOINT_PTR)*N);
    if (!d->array)
    {
        printf("Error allocating memory!");
        exit(0);
    }

    for (i=0; i<N; i++)
        DS_make_set(d, i);

}

void DS_make_set(DISJOINT *d, elem x)
{
    d->array[x] = (DISJOINT_NODE *)malloc(sizeof(DISJOINT_NODE));
    if (!d->array[x])
    {
        printf("Error allocating memory!");
        exit(0);
    }
    d->array[x]->data = x;
    d->array[x]->height = 0;
    d->array[x]->parent = d->array[x];
}

int DS_union(DISJOINT *d, elem x, elem y)
{
    int p1, p2;

    p1 = DS_find_set(*d, x);
    p2 = DS_find_set(*d, y);

    if (p1==p2)
    {
        printf("Elements %d and %d are in the same set(%d)", x, y, p1);
        return FALSE;
    }

    if (d->array[p1]->height < d->array[p2]->height)
        d->array[p1]->parent = d->array[p2];
    else if (d->array[p1]->height > d->array[p2]->height)
        d->array[p2]->parent = d->array[p1];
    else
    {
        d->array[p2]->parent = d->array[p1];
        (d->array[p1]->height)++;
    }

    return TRUE;
}

elem DS_find_set(DISJOINT d, elem x)
{
    int p;
    if (d.array[x]->parent == d.array[x])
        return x;
    else
    {
        p = DS_find_set(d, d.array[x]->parent->data);
        d.array[x]->parent=d.array[p];
        return p;
    }
}

void DS_destroy(DISJOINT *d)
{
    int i;

    for (i=0; i<d->N; i++)
    {
        free(d->array[i]);
    }

    free(d->array);
}


/* Deutereouses Prakseis */
elem DS_find_set_print(DISJOINT d, elem x)
{
    if (d.array[x]->parent == d.array[x])
        return x;
    else
        return DS_find_set_print(d, d.array[x]->parent->data);
}

void DS_print(DISJOINT d)
{
    int i, v, cnt;
    int *MARK;

    MARK = (int *)malloc(sizeof(int)*d.N);
    if(!MARK)
    {
        printf("Error allocating memory");
        exit(0);
    }
    for (i=0; i<d.N; i++)
        MARK[i]=0;

    cnt=0;
    while(cnt<d.N)
    {
        for (i=0; i<d.N; i++)
            if (MARK[i]==0)
            {
                v=i;
                break;
            }

        printf("{ ");
        for (i=0; i<d.N; i++)
            if (DS_find_set_print(d,v)==DS_find_set_print(d,i))
            {
                MARK[i]=1;
                cnt++;
                printf("%d(%d) ", i, d.array[i]->parent->data);
            }
        printf("} ");
    }

    free(MARK);
}

