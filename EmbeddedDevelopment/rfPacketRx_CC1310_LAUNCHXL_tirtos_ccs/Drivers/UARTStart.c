
#include <ti/drivers/UART.h>
#include "Board.h"

UART_Handle uart;
UART_Params uartParams;

void Board_InitUART()
{
    const char initMessage[] = "The Serial interface initialized\r";



    UART_init();
    UART_Params_init(&uartParams);
    uartParams.writeDataMode = UART_DATA_TEXT;
    uartParams.readDataMode = UART_DATA_TEXT;
    uartParams.readReturnMode = UART_ECHO_OFF;
    uartParams.baudRate = 115200;

    uart = UART_open(Board_UART0, &uartParams);

    if(uart == NULL)
    {
        while(1);
    }

    UART_write(uart, initMessage, sizeof(initMessage));
}




