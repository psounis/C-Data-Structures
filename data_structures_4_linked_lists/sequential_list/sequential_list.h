/* queue.h : Dilwseis sindedemenis listas */

#define TRUE 1
#define FALSE 0

#define SIZE 100

typedef int elem;          /* typos dedomenwn listas */

typedef struct list LIST;  /* Sinwnimo tis listas */ 

struct list{		       /* Akolouthiaki list */
   elem data[SIZE]; 	   /* Pinakas Dedomenwn */
   int N;                  /* plithos stoixeiwn */
};

void SL_init(LIST *l);
int SL_empty(LIST l);
elem SL_data(LIST l, int ind);
int SL_insert(LIST *l, int ind, elem x);
int SL_delete(LIST *l, int ind, elem *x);
void SL_print(LIST l);

