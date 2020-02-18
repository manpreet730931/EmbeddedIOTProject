#include <ti/drivers/UART.h>
#include <ti/sysbios/BIOS.h>
#include <stdint.h>

//Definition of functions for LED management
void *ledTask(void *arg);

//Perform UART Write operations
void *uartWriteTask(UArg *arg);

//Peform UART Read operations
void *uartReadTask(UArg *arg);

//RF Tx task
void *txTask(UArg *arg);

//RF Rx Task
void *rxTask(UArg *arg);
