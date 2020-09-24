#include <stdio.h>
#include "disjoint_sets.h"

int main()
{
	DISJOINT d;

    DS_init(&d, 7);

    DS_print(d);

    printf("UNION(1,3):\n");
    DS_union(&d, 1, 3);
    DS_print(d);

    printf("UNION(2,4):\n");
    DS_union(&d, 2, 4);
    DS_print(d);

    printf("UNION(2,5):\n");
    DS_union(&d, 2, 5);
    DS_print(d);

    printf("UNION(3,5):\n");
    DS_union(&d, 3, 5);
    DS_print(d);

    DS_destroy(&d);

	return 0;
}
