#include "startUart.h"
#include "Board.h"

uint8_t startUART(UART_Handle *uart)
{
    UART_Params uartParams;
    /* Call driver init functions */
    UART_init();
    /* Create a UART with data processing off. */
    UART_Params_init(&uartParams);
    uartParams.writeDataMode = UART_DATA_BINARY;
    uartParams.readDataMode = UART_DATA_BINARY;
    uartParams.readEcho = UART_ECHO_OFF;
    uartParams.baudRate = 115200;
    uartParams.readReturnMode = UART_RETURN_NEWLINE;
    uartParams.readMode = UART_MODE_BLOCKING;

    *uart = UART_open(Board_UART0, &uartParams);

    if (uart == NULL) {
        /* UART_open() failed so return 1*/
        return 1;
    }
    return 0;
}
