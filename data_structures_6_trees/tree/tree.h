/* tree.h : Dilwseis dendrou */

#define TRUE 1
#define FALSE 0

typedef int elem;          /* typos dedomenwn dendrou*/

struct node{		 /* Typos komvou listas */
   elem data; 		 /* dedomena */
   struct node *left;      /* aristero paidi */
   struct node *right;     /* deksi paidi */
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

