
#include <stdint.h>
#include <stddef.h>

/* Driver Header files */
#include <ti/drivers/GPIO.h>
#include <ti/drivers/UART.h>

/**/
#include <DataStructures/ComQueue.h>

/* Example/Board Header files */
#include "Board.h"
#include "taskDefinitions.h"
#include <mqueue.h>

void *uartWriteTask(void *handle)
{
    UART_Handle uart = (UART_Handle)handle;
    const char  echoPrompt[] = "Echoing characters:\r\n";

    UART_write(uart, echoPrompt, sizeof(echoPrompt));

    /* Initialize the receiving queue to get data from the Rx */

    mqd_t rQm = NULL;
    struct mq_attr attr;

    attr.mq_flags = 0;
    attr.mq_maxmsg = 1;
    attr.mq_msgsize = MAX_LENGTH;
    attr.mq_curmsgs = 0;
    rQm = mq_open(receiveQueue, O_CREAT | O_RDONLY, 0644, &attr);

    char messageReceived[MAX_LENGTH];
    ssize_t bytes_read;
    /* Loop forever writing the received data */

    while (1)
    {
        bytes_read = mq_receive(rQm, (char *)messageReceived, MAX_LENGTH, NULL);
        if(bytes_read)
        {
            UART_write(uart,&(messageReceived) ,sizeof(messageReceived));
        }
        usleep(50);
    }
}
