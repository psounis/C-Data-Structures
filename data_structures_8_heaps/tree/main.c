#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

#define SIZE 100

main()
{
	int choice,i,j;
	int data;
	int array[SIZE],N;
	HEAP heap,heapsort_heap;
	
	HEAP_init(&heap);
	
	while(1)
	{
		system("cls");
		printf("Menu Heap: ");
		printf("\n--------------");
		printf("\n1-Eisagwgi");
		printf("\n2-Diagrafi");
		printf("\n3-Ektypwsi");
		printf("\n4-HeapSort!");
		printf("\n5-Eksodos");		
		printf("\nEpilogi? ");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1:
				printf("\nDwse Stoixeio: ");
				scanf("%d",&data);
				if (HEAP_insert(&heap,data))
					printf("Egine i eisagwgi!");
				else
					printf("Den egine i eisagwgi! O swros gemise!");
				break;
			case 2:
				if (HEAP_delete(&heap,&data))
					printf("Egine i apomakrinsi tou %d", data);
				else
					printf("Den egine i diagrafi. O swros einai adeios!");
				break;
			case 3:
				for (i=0; i<heap.N; i++)
				{
					printf("%d ", heap.data[i]);
				}
				break;
			case 4:
				printf("Dwse megethos pinaka: ");
				scanf("%d",&N);
				printf("Dwse ta stoixeia tou pinaka: ");
				for (i=0; i<N; i++)
				{
					printf("array[%d]=",i);
					//scanf("%d",&array[i]);
					array[i]=rand()%500;
				}
				
				HEAP_init(&heapsort_heap);
				for (i=0; i<N; i++)
					HEAP_insert(&heapsort_heap,array[i]);
				
				printf("\nSORTED: ");
				for (i=0; i<N; i++)
				{
					HEAP_delete(&heapsort_heap,&data);
					printf("%d ",data);
				}
				
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

