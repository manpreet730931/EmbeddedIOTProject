#include <stdint.h>
#include <stddef.h>

/* Driver Header files */
#include <ti/drivers/GPIO.h>
#include <ti/drivers/UART.h>

/* Structures needed to manage the queue parameters */
#include <DataStructures/ComQueue.h>

/* Example/Board Header files */
#include "Board.h"
#include "taskDefinitions.h"
#include <mqueue.h>

void *uartReadTask(void *arg)
{
    //Cast the argument into something that is
    //known
    mqd_t mq = NULL;

    UART_Handle uart = (UART_Handle)arg;
    char messageReceived[MAX_LENGTH];

    while(1)
    {
        UART_read(uart, messageReceived, sizeof(messageReceived));

        if(mq==NULL)
        {
            mq = mq_open(sendQueue, O_WRONLY);
        }
        mq_send(mq, (char *)&messageReceived, MAX_LENGTH, 0);

        usleep(5000);
    }
}
