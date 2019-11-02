#include <stdio.h>
#include "efarmogi3_stack.h"

main()
{
	STACK st;
	int x;
	
	/* Diavasma tou akeraiou arithmou */
	
	do{
		printf("Dwse enan thetiko akeraio: ");
		scanf("%d",&x);
	} while (!(x>0));

	/* Metatropi sto dyadiko */
	ST_init(&st);
	
	while(x>=1)
	{
		ST_push(&st,x%2);
		x=x/2;
	}
	
	/* Ektypwsi tou arithmou */
	
	printf("\n O dyadikos einai: ");
	while(!ST_empty(st))
	{
		ST_pop(&st,&x);
		printf("%d",x);
	}
}

