#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

main()
{
	int elem;
	TREE_PTR root;
	
	TR_init(&root);
	
	/* Eisagwgi tou "10" */
	TR_insert_root(&root, 10);
		
	/* Eisagwgi twn epipleon stoixeiwn */
	TR_insert_left(root, 6); 
	TR_insert_right(root, 14);
	
	TR_insert_left(root->left, 5);
	TR_insert_right(root->left, 7);
	TR_insert_right(root->right, 19);
	
	TR_insert_left(root->left->left, 2);
	TR_insert_right(root->left->right, 8);

	TR_insert_right(root->left->left->left, 3);

	
	/* Ektypwsi toy dendrou */
	printf("\n PREORDER: ");
	TR_preorder(root);
	printf("\n INORDER: ");
	TR_inorder(root);
	printf("\n POSTORDER: ");
	TR_postorder(root);

}

