/* tree.c: Kwdikas tis vivliothikis dendrou */
#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

/* TR_init(): arxikopoiei to dendro */
void TR_init(TREE_PTR *root)
{
   *root=NULL;
}

/* TR_empty(): epistrefei TRUE/FALSE
 *          analoga me to an to dendro einai adeio */
int TR_empty(TREE_PTR root)
{
   return root == NULL;
}


/* TR_data(): epistrefei ta dedomena tou komvou
	      pou deixnei o deiktis p */
elem TR_data(TREE_PTR p)
{
   return p->data;
}


/* TR_insert_root(): Eisagei to stoixeio x
			sti riza tou dendrou */
int TR_insert_root(TREE_PTR *root,elem x)
{
	TREE_PTR newnode;
	
	if (*root!=NULL)
		return FALSE;
	
	newnode=(TREE_NODE *)malloc(sizeof(TREE_NODE));
	if (!newnode)
	{
		printf("Adynamia desmeusis mnimis");
		return FALSE;
	}
	newnode->data=x;
	newnode->left=NULL;
	newnode->right=NULL;

	*root=newnode;
	return TRUE;
}

/* TR_insert_left(): Eisagei to stoixeio x
			ws aristero paidi tou node */
int TR_insert_left(TREE_PTR node,elem x)
{
	TREE_PTR newnode;
	
	if (node->left!=NULL)
		return FALSE;
	
	newnode=(TREE_NODE *)malloc(sizeof(TREE_NODE));
	if (!newnode)
	{
		printf("Adynamia desmeusis mnimis");
		return FALSE;
	}
	newnode->data=x;
	newnode->left=NULL;
	newnode->right=NULL;

	node->left=newnode;
	return TRUE;
}

/* TR_insert_right(): Eisagei to stoixeio x
			ws deksi paidi tou node */
int TR_insert_right(TREE_PTR node,elem x)
{
	TREE_PTR newnode;
	
	if (node->right!=NULL)
		return FALSE;
	
	newnode=(TREE_NODE *)malloc(sizeof(TREE_NODE));
	if (!newnode)
	{
		printf("Adynamia desmeusis mnimis");
		return FALSE;
	}
	newnode->data=x;
	newnode->left=NULL;
	newnode->right=NULL;

	node->right=newnode;
	return TRUE;
}

/* TR_delete_root(): Diagrafei ti riza enos
	dentrou efoson den exei paidia */
int TR_delete_root(TREE_PTR *root, elem *x)
{
	if ((*root)->left!=NULL || (*root)->right!=NULL)
		return FALSE;	

	*x=(*root)->data;
	free(*root);
	*root=NULL;
	return TRUE;
}

/* TR_delete_left(): Diagrafei to aristero paidi 
	tou komvou parent (efoson den exei paidia) */
int TR_delete_left(TREE_PTR parent, elem *x)
{
	TREE_PTR current;
	
	if (parent->left==NULL)
		return FALSE;
	
	current=parent->left;
	if (current->left!=NULL || current->right!=NULL)
		return FALSE;	

	*x=current->data;
	free(current);
	parent->left=NULL;
	return TRUE;
}

/* TR_delete_right(): Diagrafei to deksi paidi 
	tou komvou node (efoson den exei paidia) */
int TR_delete_right(TREE_PTR parent, elem *x)
{
	TREE_PTR current;
	
	if (parent->right==NULL)
		return FALSE;
	
	current=parent->right;
	if (current->left!=NULL || current->right!=NULL)
		return FALSE;	

	*x=current->data;
	free(current);
	parent->right=NULL;
	return TRUE;
}


void TR_print_node(TREE_PTR v)
{
	printf("%d ",v->data);
}


/* TR_preorder(): Ektypwsi kata tin
	prodiatetagmeni diadromi	 */
void TR_preorder(TREE_PTR v)
{
	if(v!=NULL)
	{
		TR_print_node(v);
		TR_preorder(v->left);
		TR_preorder(v->right);
	}
}

/* TR_inorder(): Ektypwsi kata tin
	endodiatetagmeni diadromi	 */
void TR_inorder(TREE_PTR v)
{
	if(v!=NULL)
	{
		TR_inorder(v->left);
		TR_print_node(v);
		TR_inorder(v->right);
	}
}

/* TR_postorder(): Ektypwsi kata tin
	metadiatetagmeni diadromi	 */
void TR_postorder(TREE_PTR v)
{
	if(v!=NULL)
	{
		TR_postorder(v->left);
		TR_postorder(v->right);
		TR_print_node(v);
	}
}


