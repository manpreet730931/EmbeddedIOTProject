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

void *uartReadTask(UArg *arg)
{
    //Cast the argument into something that is
    //known
    mqd_t tQm = NULL;
    UART_Handle uart = (UART_Handle)arg;
    char messageReceived[MAX_LENGTH];
    tQm = mq_open(sendQueue, O_WRONLY);
    bool state = false;
    while(1)
    {
        UART_read(uart, messageReceived, sizeof(messageReceived));
        mq_send(tQm, (char *)&messageReceived, MAX_LENGTH, 0);
        GPIO_write(Board_GPIO_LED1, state);
        if(state)
        {
            state = false;
        }
        else
        {
            state = true;
        }
    }
}
