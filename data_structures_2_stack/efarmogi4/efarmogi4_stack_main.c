#include <stdio.h>
#include "efarmogi4_stack.h"

main()
{
	char c;
	STACK st;
	double x;
	double y1,y2;
	
	printf("Dwse ti metathematiki parastasi: ");
	c=getchar();
	ST_init(&st);
	while (c!='\n')
	{
		if (c>='0' && c<='9')  //psifio
		{
			x=c-'0';
			ST_push(&st,x);
		}
		else //telestis
		{
			ST_pop(&st,&y1);
			ST_pop(&st,&y2);
			
			switch(c)
			{
				case '+':
					x=y1+y2;
					break;
				case '-':
					x=y2-y1;
					break;
				case '*':
					x=y1*y2;
					break;
				case '/':
					x=y2/y1;
			}
			
			ST_push(&st,x);
		}
		
		c=getchar();
	}

	
	/* Ektypwsi tou apotelesmatos */
	
	ST_pop(&st,&x);
	printf("To apotelesma einai: %.3f",x);

}

