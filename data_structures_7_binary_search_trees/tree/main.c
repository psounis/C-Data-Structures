#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

main()
{
	int choice,i;
	int data;
	TREE_PTR root;
	
	TR_init(&root);
	TR_insert_BST(&root,10);
	TR_insert_BST(&root,6);
	TR_insert_BST(&root,14);
	TR_insert_BST(&root,5);
	TR_insert_BST(&root,7);
	TR_insert_BST(&root,19);
	TR_insert_BST(&root,2);
	TR_insert_BST(&root,8);
	TR_insert_BST(&root,3);
	
	while(1)
	{
		system("cls");
		printf("Menu DDA: ");
		printf("\n--------------");
		printf("\n1-Eisagwgi");
		printf("\n2-Diagrafi");
		printf("\n3-Ektypwsi");
		printf("\n4-Eksodos");
		printf("\nEpilogi? ");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1:
				printf("\nDwse Stoixeio: ");
				scanf("%d",&data);
				if (TR_insert_BST(&root,data))
					printf("Egine i eisagwgi!");
				else
					printf("Den egine i eisagwgi! To stoixeio yparxei idi!");
				break;
			case 2:
				printf("\nDwse Stoixeio: ");
				scanf("%d",&data);
				if (TR_delete_BST(&root,data))
					printf("Egine i apomakrinsi tou %d", data);
				else
					printf("Den egine i diagrafi. To stoixeio den yparxei!");
				break;
			case 3:
				printf("\n INORDER: ");
				TR_inorder(root);
				printf("\n PREORDER: ");
				TR_preorder(root);
				printf("\n POSTORDER: ");
				TR_postorder(root);
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

