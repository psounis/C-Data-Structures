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

/* TR_insert_BST(): eisagwgi tou x
	sto DDA me riza root	 */
int max(int x, int y)
{
	if (x>y)
		return x; 
	else 
		return y;
}

int height(TREE_PTR R)
{
	if (R==NULL)
		return 0;
	else
		return R->height; 
}

TREE_PTR AVL_rotate_R(TREE_PTR C)
{
	TREE_PTR L = C->left; 
	C->left = L->right; 
	L->right = C; 
	C->height = max(height(C->left), height(C->right))+1;
	L->height = max(height(L->left), height(L->right))+1;
	return L; 
}

TREE_PTR AVL_rotate_L(TREE_PTR C)
{
   TREE_PTR R = C->right; 
   C->right = R->left; 
   R->left = C; 
   C->height = max(height(C->left), height(C->right))+1;
   R->height = max(height(R->left), height(R->right))+1;
   return R; 
}

TREE_PTR AVL_rotate_LR(TREE_PTR C)
{
   C->left = AVL_rotate_L(C->left);
 
   return AVL_rotate_R(C); 
}

TREE_PTR AVL_rotate_RL(TREE_PTR C)
{
   C->right = AVL_rotate_R(C->right);
 
   return AVL_rotate_L(C); 
}
	
TREE_PTR TR_insert_AVL(TREE_PTR *root, elem x)
{
	if (*root==NULL)
	{
		TR_insert_root(root, x);
		(*root)->height=1; 
		return *root; 
	}
	else if (x < (*root)->data)
	{
		(*root)->left=TR_insert_AVL(&((*root)->left), x);
		if (height((*root)->left)-height((*root)->right)==2)
		{
			if(x < (*root)->left->data)
				(*root)=AVL_rotate_R(*root);
			else
				(*root)=AVL_rotate_LR(*root);
		}
	}
	else if (x > (*root)->data)
	{
		(*root)->right=TR_insert_AVL(&((*root)->right), x);
		if (height((*root)->left)-height((*root)->right)==-2)
		{
			if(x > (*root)->right->data)
				(*root)=AVL_rotate_L(*root);
			else
				(*root)=AVL_rotate_RL(*root);
		}
	}
	// else x == root->x : den kanoyme tipota
	
	(*root)->height = max(height((*root)->left), height((*root)->right))+1;
	return (*root); 
}

int TR_delete_AVL(TREE_PTR *root, elem x)
{
	TREE_PTR pred[DEPTH], new_root;
	int orient[DEPTH]; //0-left, 1-right
	TREE_PTR current; 
	int i=0,j;
	
	
	if (*root==NULL) //adeio dentro
		return FALSE; 
	
	/* Vres olous tous progonous */
	/* Apo ti riza mexri ton komvo */	
	current=*root;
	while(current!=NULL)
	{
		if (x == current->data)
			break;
		else if (x < current->data)
		{
			orient[i]=0;
			pred[i++]=current;
			current=current->left;	
		}
		else // x > current->data 
		{
			orient[i]=1;
			pred[i++]=current;
			current=current->right;
		}					
	}
	
	if (current==NULL) //den vrethike
		return FALSE; 
	
	if (current->left!=NULL && current->right!=NULL)
	{
		orient[i]=1;
		pred[i++]=current;
		current=current->right;
		
		while (current->left!=NULL)
		{
			orient[i]=0;
			pred[i++]=current;
			current=current->left;
		}		
	}
	
	TR_delete_BST(root, x);
	
	for (j=i-1; j>=0; j--)
	{
		if (height(pred[j]->left)-height(pred[j]->right)==2)
		{
			if(height(pred[j]->left->left)>height(pred[j]->left->right))
				new_root=AVL_rotate_R(pred[j]);
			else
				new_root=AVL_rotate_LR(pred[j]);				
		}
		else if (height(pred[j]->left)-height(pred[j]->right)==-2)
		{
			if(height(pred[j]->right->right)>height(pred[j]->right->left))
				new_root=AVL_rotate_L(pred[j]);
			else
				new_root=AVL_rotate_RL(pred[j]);
		}
		else
			continue; 
			
		if (j==0)
			*root = new_root;
		else
			if (orient[i-1]==0)
				pred[i-1]->left=new_root;
			else
				pred[i-1]->right=new_root; 
	}
}

/* TR_delete_BST(): diagrafi tou x
	apo to DDA me riza root	 */
int TR_delete_BST(TREE_PTR *root, elem x)
{
	TREE_PTR current, parent, nextOrdered;
	int p; /* 1. deksi paidi, 2. aristero paidi tou current */
	int temp;
	
	/* 1. Anazitisi tou	komvou */
	parent=NULL;
	current=*root;
	while (current!=NULL)
	{
		if (x == current->data)
			break;
		else if (x < current->data)
		{
			parent=current;
			p=1;
			current=current->left;	
		}
		else // x > current->data 
		{
			parent=current;
			p=2;
			current=current->right;
		}			
	}
	if (current==NULL)
		return FALSE;
	
	/* 2.1 An den exei paidia */
	if (current->left==NULL && current->right==NULL)
	{
		free(current);
		
		if (parent==NULL)
			*root=NULL;
		else
			if (p==1)
				parent->left=NULL;
			else
				parent->right=NULL;
		return TRUE;
	}
	/* 2.2 Exei mono aristero paidi */
	else if (current->left!=NULL && current->right==NULL)
	{
		if (parent==NULL)
			*root=current->left;
		else
			if (p==1)
				parent->left=current->left;
			else
				parent->right=current->left;
		free(current);
		return TRUE;
	}
	/* 2.3 Exei mono deksi paidi */
	else if (current->left==NULL && current->right!=NULL)
	{
		if (parent==NULL)
			*root=current->right;
		else
			if (p==1)
				parent->left=current->right;
			else
				parent->right=current->right;
		free(current);
		return TRUE;
	}
	/* 2.4 Exei aristero kai deksi paidi */
	else
	{
		/* 2.4.1 Vriskei ton epomeno stin endodiatetagmeni */
		p=1;
		nextOrdered=current->right;
		
		while (nextOrdered->left!=NULL)
		{
			parent=nextOrdered;
			nextOrdered=nextOrdered->left;
			p=2;
		}
		
		/*2.4.2 Antallassei times me ton komvo pou diagrafetai */
		current->data=nextOrdered->data;
		
		/*2.4.3 Diagrafei ton komvo */
		if (p==1) /*2.4.3.1 O epomenos einai to deksi paidi */
		{
			current->right=nextOrdered->right;
			free(nextOrdered);	
		}
		else 
		{
			parent->left=nextOrdered->right;
			free(nextOrdered);
		}
	}
}

void TR_print_AVL(TREE_PTR root)
{
	if (root->left!=NULL)
	{
		printf("(");
		TR_print_AVL(root->left);
		printf(")");	
	}
	printf(" %d ", root->data);
	if (root->right!=NULL)
	{
		printf("(");
		TR_print_AVL(root->right);
		printf(")");		
	}
}

/* TR_search_AVL(): anazitisi tou x sto
	DDA me riza root	 */
int TR_search_AVL(TREE_PTR root, elem x)
{
	TREE_PTR current;
	
	current=root;
	
	while (current!=NULL)
	{
		if (x == current->data)
			return TRUE;
		else if (x < current->data)
			current=current->left;
		else // x > current->data 
			current=current->right;
	}
	return FALSE;
}

