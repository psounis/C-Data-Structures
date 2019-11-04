#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linked_list.h"

main() 
{
	elem student;
	LIST_PTR list;
	int choice; 
	
	LL_init(&list);
	
	while(1)
	{
		printf("MENU\n");
		printf("====\n");
		printf("1-eisagogi\n");
		printf("2-diagrafi\n");
		printf("3-ektipwsi\n");
		printf("4-mesos oros\n");
		printf("5-perasan\n");
		printf("6-eksodos\n");
		printf("Epilogi? ");
		scanf("%d", &choice);
		getchar(); 
		
		switch(choice)
		{
			case 1:
				printf("Dwse onoma: ");
				fgets(student.name, 80, stdin);
				student.name[strlen(student.name)-1]='\0';
				printf("Dwse vathmo: ");
				scanf("%d", &student.grade);
				
				LL_insert(&list, student);
				printf("H eisagogi egine\n\n");
				
				break;
			case 2:
				printf("Dwse onoma: ");
				fgets(student.name, 80, stdin);
				student.name[strlen(student.name)-1]='\0';
				
				if (LL_delete(&list,student.name))
				{
					printf("H diagrafi egine!\n\n");
				}
				else
				{
					printf("O foititis den vrethike\n\n");
				}
				
				break;
			case 3:
				
				LL_print(list);
				printf("\n\n");
				
				break;
			case 4:
				printf("O mesos oros einai: %.2lf\n\n", LL_average(list));
				break;
			case 5:
				printf("To plithos epitixontwn einai: %d\n\n", LL_pass(list));
				break;
			case 6:
				printf("Bye bye!");
				LL_destroy(&list);
				exit(0);
		}
	}
	
}
