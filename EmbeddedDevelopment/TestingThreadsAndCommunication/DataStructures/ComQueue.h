#include <ti/sysbios/knl/Queue.h>
//Standard C libraries
#include <stdlib.h>
#include <unistd.h>

#define MAX_LENGTH             10 /* The size of the package to hold in the queue */
#define receiveQueue           "ReceiverQueue"
#define sendQueue              "SendQueue"

struct messageQueue{
    size_t objectID;
    char packet[MAX_LENGTH];
};

typedef struct messageQueue message_t;
