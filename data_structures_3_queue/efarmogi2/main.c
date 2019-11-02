#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

main()
{
	int choice,i;
	elem x;
	
	QUEUE q;
	
	QU_init(&q);
	
	while(1)
	{
		system("cls");
		printf("Menu Ouras: ");
		printf("\n--------------");
		printf("\n1-Eisagwgi");
		printf("\n2-Apomakrinsi");
		printf("\n3-Ektypwsi");
		printf("\n4-Eksodos");
		printf("\nEpilogi? ");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1:
				printf("\nDwse Stoixeio: ");
				scanf("%d",&x.data);
				printf("\nDwse Proteraiotita: ");
				scanf("%d",&x.priority);
				if (QU_enqueue(&q,x))
					printf("Egine i eisagwgi!");
				else
					printf("Den egine i eiasagwgi! Gemati Oura!");
				break;
			case 2:
				if (QU_dequeue(&q,&x))
					printf("Egine i apomakrinsi tou %d", x);
				else
					printf("Den egine i apomakrinsi! Adeia Oura!");
				break;
			case 3:
				//MONO GIA EKPAIDEYTIKOUS LOGOUS!!!
				//Apagorevetai na akoumpame ti domi!!
				if (q.start!=-1)
				{
					i=q.start;
					while (1)
					{
						printf("|%3d(%d)",q.array[i].data,q.array[i].priority);
						if (i==q.finish)
							break;
						i=(i+1)%QUEUE_SIZE;
					}	
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

