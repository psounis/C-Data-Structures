#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

#define N 80

main()
{
	int choice,i;
	QUEUE tameio1,tameio2;
	char *pelatis;
	
	
	QU_init(&tameio1);
	QU_init(&tameio2);
	
	while(1)
	{
		system("cls");
		printf("Menu Trapezas: ");
		printf("\n--------------");
		printf("\n1-Afiksi Pelati");
		printf("\n2-Anaxwrisi Pelati");
		printf("\n3-Eksodos");
		printf("\nEpilogi? ");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1:
				printf("\nDwse Onomatepwnimo Pelati: ");
				
				pelatis=malloc(sizeof(char)*N);
				if (!pelatis)
				{
					printf("Adynamia desmeysis mnimis");
					exit(0);
				}
				scanf("%s",pelatis);
				
				if (QU_enqueue(&tameio1,pelatis))
				{
					printf("Egine i eisagwgi tou %s sto 1o tameio: ", pelatis);
				}
				else
				{
					if (QU_enqueue(&tameio2,pelatis))
					{
						printf("Egine i eisagwgi tou %s sto 2o tameio: ", pelatis);
					}
					else
						printf("Ta tameia einai gemata. O %s apoxwrei",pelatis);
				}
				break;
			case 2:
				
				if (!QU_empty(tameio1) && !QU_empty(tameio2))
				{
					if (1+rand()%2==1)
					{
						QU_dequeue(&tameio1,&pelatis);
						printf("O pelatis %s eksipiretithike apo to tameio 1", pelatis);
					}
					else
					{
						QU_dequeue(&tameio2,&pelatis);
						printf("O pelatis %s eksipiretithike apo to tameio 2", pelatis);
					}
					free(pelatis);
				}
				else if (!QU_empty(tameio1))
				{
					QU_dequeue(&tameio1,&pelatis);
					printf("O pelatis %s eksipiretithike apo to tameio 1", pelatis);
					free(pelatis);
				}
				else if (!QU_empty(tameio2))
				{
					QU_dequeue(&tameio2,&pelatis);
					printf("O pelatis %s eksipiretithike apo to tameio 2", pelatis);
					free(pelatis);
				}
				else
				{
					printf("Ta dyo tameia einai adeia!!");
				}
				break;
			case 3:
				printf("Bye Bye!!");
				exit(0);
			default:
				printf("Lathos eisodos!");
		}
		printf("\n\n");
		system("pause");
	}
}

