#include <stdio.h>
#include <stdlib.h>
#include "sequential_list.h"

main()
{
	int d;
	LIST l;
	
	SL_init(&l);
	
	/* Eisagwgi tou "1" */
	SL_insert(&l, 0, 1);
	
	printf("\n");
	SL_print(l);
	
	/* Eisagwgi tou "2" stin arxi */
	SL_insert(&l, 0, 2);
	
	printf("\n");
	SL_print(l);
	
	/* Eisagwgi tou "3" sti thesi 1 */
	SL_insert(&l, 1, 3);
	
	printf("\n");
	SL_print(l);
	
	/* Eisagwgi tou "4" sti thesi 2 */
	SL_insert(&l, 2, 4);
	
	printf("\n");
	SL_print(l);
	
	/* Eisagwgi tou "5" stin arxi */
	SL_insert(&l, 0, 5);
	
	printf("\n");
	SL_print(l);
	
	/* Eisagwgi tou "6" stin arxi */
	SL_insert(&l, 0, 6);
	
	printf("\n");
	SL_print(l);
	
	/* Eisagwgi tou "7" sto telos */
	SL_insert(&l, 6, 7);

	printf("\n");
	SL_print(l);

	/* Diagrafi tou 1ou stoixeiou */
	SL_delete(&l, 0, &d);
	
	printf("\n");
	SL_print(l);

	/* Diagrafi tou teleytaiou stoixeiou */
	SL_delete(&l, 5, &d);
	
	printf("\n");
	SL_print(l);
}

