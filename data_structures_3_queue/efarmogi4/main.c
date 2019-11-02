#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "stack.h"

void QU_print(QUEUE *q);
void QU_reverse(QUEUE *q);

main()
{
	int choice,elem,i;
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
		printf("\n4-Antistrofi ouras");
		printf("\n5-Eksodos");
		printf("\nEpilogi? ");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1:
				printf("\nDwse Stoixeio: ");
				scanf("%d",&elem);
				if (QU_enqueue(&q,elem))
					printf("Egine i eisagwgi!");
				else
					printf("Den egine i eiasagwgi! Gemati Oura!");
				break;
			case 2:
				if (QU_dequeue(&q,&elem))
					printf("Egine i apomakrinsi tou %d", elem);
				else
					printf("Den egine i apomakrinsi! Adeia Oura!");
				break;
			case 3:
				QU_print(&q);
				break;
			case 4:
				QU_reverse(&q);
				break;
			case 5:
				printf("Bye Bye!!");
				exit(0);
			default:
				printf("Lathos eisodos!");
		}
		printf("\n\n");
		system("pause");
	}
}

void QU_print(QUEUE *q)
{
	QUEUE temp;
	int x;
	
	/* 1. Ektypwsi twn stoixeiwn tis ouras */
	QU_init(&temp);
	
	while(!QU_empty(*q))
	{
		QU_dequeue(q,&x);
		printf("%3d|",x);
		QU_enqueue(&temp,x);
	}
	
	/* 2. Ksanagemisma tis ouras q */
	
	while (!QU_empty(temp))
	{
		QU_dequeue(&temp,&x);
		QU_enqueue(q,x);
	}
}

void QU_reverse(QUEUE *q)
{
	STACK temp;
	int x;
	
	/* 1. Adeiasma tis ouras => gemisma tis stoivas */
	
	ST_init(&temp);
	
	while (!QU_empty(*q))
	{
		QU_dequeue(q,&x);
		ST_push(&temp,x);
	}
	
	/* 2. Adeiasma tis stoivas => gemisma tis ouras */
	
	while (!ST_empty(temp))
	{
		ST_pop (&temp,&x);
		QU_enqueue(q,x);
	}
}
