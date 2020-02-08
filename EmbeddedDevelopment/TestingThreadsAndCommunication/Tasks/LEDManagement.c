
#include <stdint.h>
#include <stddef.h>

/* Driver Header files */
#include <ti/drivers/GPIO.h>
#include <ti/drivers/UART.h>
#include <unistd.h>

/* Example/Board Header files */
#include "Board.h"
#include "taskDefinitions.h"

void *ledTask(void *args)
{

    GPIO_init();

    GPIO_setConfig(Board_GPIO_LED0, GPIO_CFG_OUT_STD | GPIO_CFG_OUT_LOW);
    /* Turn on user LED */
    GPIO_write(Board_GPIO_LED0, Board_GPIO_LED_ON);
    bool state = false;
    while(1)
    {
        GPIO_write(Board_GPIO_LED0,state);

        if(state)
        {
            state = false;
        }
        else
        {
            state = true;
        }
        sleep(1);
    }

}
