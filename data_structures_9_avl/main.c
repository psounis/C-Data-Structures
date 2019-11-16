#include <stdio.h>
#include "tree.h"

int main() 
{
	TREE_PTR tree;
	
	TR_init(&tree);
	
	TR_insert_AVL(&tree, 2);
	TR_print_AVL(tree);
	printf("\n");
	TR_insert_AVL(&tree, 20);
	TR_print_AVL(tree);	
	printf("\n");
	TR_insert_AVL(&tree, 28);
	TR_print_AVL(tree);	
	printf("\n");
	TR_insert_AVL(&tree, 36);
	TR_print_AVL(tree);	
	printf("\n");
	TR_insert_AVL(&tree, 32);
	TR_print_AVL(tree);	
	printf("\n");
	TR_insert_AVL(&tree, 29);
	TR_print_AVL(tree);	
	printf("\n");
	TR_insert_AVL(&tree, 7);
	TR_print_AVL(tree);									
	printf("\n");
	TR_insert_AVL(&tree, 15);
	TR_print_AVL(tree);		
	printf("\n");
	TR_insert_AVL(&tree, 12);
	TR_print_AVL(tree);		
	printf("\n");
	TR_delete_AVL(&tree, 32);
	TR_print_AVL(tree);	
	printf("\n");
	TR_delete_AVL(&tree, 36);
	TR_print_AVL(tree);	
	printf("\n");
	TR_delete_AVL(&tree, 2);
	TR_print_AVL(tree);	
	printf("\n");
	TR_delete_AVL(&tree, 7);
	TR_print_AVL(tree);	
	printf("\n");
	TR_delete_AVL(&tree, 12);
	TR_print_AVL(tree);
	printf("\n");
	TR_delete_AVL(&tree, 15);
	TR_print_AVL(tree);		
	printf("\n");
	TR_delete_AVL(&tree, 28);
	TR_print_AVL(tree);
	printf("\n");
	TR_delete_AVL(&tree, 29);
	TR_print_AVL(tree);
	printf("\n");
	TR_delete_AVL(&tree, 20);
	TR_print_AVL(tree);	
			
	return 0;
}
