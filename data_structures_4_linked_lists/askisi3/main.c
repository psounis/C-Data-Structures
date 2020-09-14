#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "queue.h"

main()
{
	QUEUE q;
	elem x;
	int i;

	srand(time(NULL));
	QU_init(&q);

	for (i=0; i<400; i++)
    {
        if (rand()%2)
        {
            printf("enqueue.. ");
            x = rand()%100;
            QU_enqueue(&q, x);
        }
        else
        {
            printf("dequeue .. ");
            QU_dequeue(&q, &x);
        }
        QU_print(q);
        printf("\n");
    }

	QU_destroy(q);
}
