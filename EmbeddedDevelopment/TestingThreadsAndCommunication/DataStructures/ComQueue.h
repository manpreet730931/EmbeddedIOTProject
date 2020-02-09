#include <ti/sysbios/knl/Queue.h>
//Standard C libraries
#include <stdlib.h>
#include <unistd.h>

#define MAX_LENGTH             30 /* The size of the package to hold in the queue */

typedef struct comQueue{
    Queue_Elem elem;
    char packet[MAX_LENGTH];
}comQueue;


Queue_Handle rxQueue;
Queue_Handle txQueue;


