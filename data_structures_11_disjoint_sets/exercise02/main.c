#include <stdio.h>
#include "disjoint_sets.h"

int main()
{
	DISJOINT d;
    int i, n=10;

    DS_init(&d, 10);

    DS_print(d);

    for (i=n-1; i>=1; i--)
    {
        DS_union(&d, i, i-1);
        DS_print(d);
        printf("\n");
    }

    DS_destroy(&d);

	return 0;
}
