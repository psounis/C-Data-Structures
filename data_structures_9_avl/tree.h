/* tree.h : Dilwseis dendrou AVL */

#define TRUE 1
#define FALSE 0

#define DEPTH 100			/* Megisto Epitrepto Ipsos Dentroy */ 

typedef int elem;          	/* typos dedomenwn dendrou*/

struct node{			 	/* Typos komvou listas */
   elem data; 		 		/* dedomena */
   struct node *left;      	/* aristero paidi */
   struct node *right;     	/* deksi paidi */
   int height;				/* Ypsos toy ypodendroy */
};

typedef struct node TREE_NODE; /* Sinwnimo tou komvou dendrou */
typedef struct node *TREE_PTR; /* Sinwnimo tou deikti komvou */

void TR_init(TREE_PTR *root);
int TR_empty(TREE_PTR root);
elem TR_data(TREE_PTR p);
int TR_insert_root(TREE_PTR *root,elem x);
int TR_insert_left(TREE_PTR node,elem x);
int TR_insert_right(TREE_PTR node,elem x);
int TR_delete_root(TREE_PTR *root, elem *x);
int TR_delete_left(TREE_PTR parent, elem *x);
int TR_delete_right(TREE_PTR parent, elem *x);
void TR_preorder(TREE_PTR v);
void TR_inorder(TREE_PTR v);
void TR_postorder(TREE_PTR v);

int TR_delete_BST(TREE_PTR *root, elem x);

TREE_PTR AVL_rotate_R(TREE_PTR C);
TREE_PTR AVL_rotate_L(TREE_PTR C);
TREE_PTR AVL_rotate_LR(TREE_PTR C);
TREE_PTR AVL_rotate_RL(TREE_PTR C);

TREE_PTR TR_insert_AVL(TREE_PTR *root, elem x);
int TR_delete_AVL(TREE_PTR *root, elem x);
int TR_search_AVL(TREE_PTR root, elem x);
void TR_print_AVL(TREE_PTR root);
