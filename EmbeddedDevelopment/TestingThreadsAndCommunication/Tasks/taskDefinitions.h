#include <ti/drivers/UART.h>

//Definition of functions for LED management
void *ledTask(void *arg);

//Perform UART Write operations
void *uartWriteTask(void *arg);

//Peform UART Read operations
void *uartReadTask(void *arg);

//RF Tx task
void *txTask(void *arg);

//RF Rx Task
void *rxTask(void *arg);
