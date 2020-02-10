#include <ti/sysbios/knl/Queue.h>
//Standard C libraries
#include <stdlib.h>
#include <unistd.h>

#define MAX_LENGTH             30 /* The size of the package to hold in the queue */
const char queuName[] = "ReceiverQueue";

struct messageQueue{
    size_t objectID;
    char packet[MAX_LENGTH];
};

typedef struct messageQueue message_t;


struct queueMessage{
    Queue_Elem elem;
    char packet[MAX_LENGTH];
};

typedef struct queueMessage queueMessage_t;
