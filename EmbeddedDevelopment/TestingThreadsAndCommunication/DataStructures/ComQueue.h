#include <ti/sysbios/knl/Queue.h>
//Standard C libraries
#include <stdlib.h>
#include <unistd.h>

#define MAX_LENGTH             30 /* The size of the package to hold in the queue */

struct messageQueue{
    size_t objectID;
    char packet[MAX_LENGTH];
};

typedef struct messageQueue message_t;

//do_message *txLL = NULL;
//do_message *rxLL = NULL;

