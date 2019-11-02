#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

main()
{
	int choice,elem,i;
	STACK st;
	
	ST_init(&st);
	
	while(1)
	{
		system("cls");
		printf("Menu Stoivas: ");
		printf("\n--------------");
		printf("\n1-Othisi");
		printf("\n2-Eksagogi");
		printf("\n3-Ektypwsi");
		printf("\n4-Eksodos");
		printf("\nEpilogi? ");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1:
				printf("\nDwse Stoixeio: ");
				scanf("%d",&elem);
				if (ST_push(&st,elem))
					printf("Egine i othisi!");
				else
					printf("Den egine i othisi! Gemati Stoiva!");
				break;
			case 2:
				if (ST_pop(&st,&elem))
					printf("Egine i eksagogi tou %d", elem);
				else
					printf("Den egine i eksagogi! Adeia Stoiva!");
				break;
			case 3:
				//MONO GIA EKPAIDEYTIKOUS LOGOUS!!!
				//Apagorevetai na akoumpame ti domi!!
				printf("\n\nH stoiva exei %d stoixeia: \n", st.top+1);
				for (i=0; i<=st.top; i++)
				{
					printf("|%3d",st.array[i]);
				}
				break;
			case 4:
				printf("Bye Bye!!");
				exit(0);
			default:
				printf("Lathos eisodos!");
		}
		printf("\n\n");
		system("pause");
	}
}

