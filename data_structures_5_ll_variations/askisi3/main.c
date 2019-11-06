#include <stdio.h>
#include "queue.h"

main() 
{
	QUEUE q; 
	elem x; 
	
	QU_init(&q);
	
	QU_enqueue(&q, 1);
	QU_enqueue(&q, 2);
	
	QU_dequeue(&q, &x);
	printf("%d", x);
	QU_dequeue(&q, &x);
	printf("%d", x);
	
	QU_destroy(q);
}
