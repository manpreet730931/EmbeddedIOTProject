/*
 * Copyright (c) 2016-2019, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,

 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/*
 *  ======== main_tirtos.c ========
 */
#include <stdint.h>

/* POSIX Header files */
#include <pthread.h>

/* RTOS header files */
#include <ti/sysbios/BIOS.h>

/* Example/Board Header files */
#include <ti/drivers/Board.h>
#include <ti/drivers/GPIO.h>

/*Tasks include files*/

#include <Tasks/taskDefinitions.h>

/* Data structures defined for this development */
#include <DataStructures/ComQueue.h>


/* Stack size in bytes */
#define THREADSTACKSIZE    1024


/*
 *  ======== main ========
 */
int main(void)
{
    //Handles for the threads
    pthread_t           ledThread;
    pthread_t           thread;
    pthread_t           txThreadTask;
    pthread_t           rxThreadTask;
    //These definitions are used globally amoung the threads
    pthread_attr_t      attrs;
    struct sched_param  priParam;
    int                 retc;
    int                 detachState;

    /* Communication facilities initialization */

    rxQueue = Queue_create(NULL,NULL);
    txQueue = Queue_create(NULL,NULL);

    comQueue r;
    int i = 0;
    for(i=0;i<30;i++)
    {
        r.packet[i] = i + 48;
    }

    Queue_enqueue(rxQueue, &(r.elem));

//    comQueue *rec;
//
//    rec = Queue_dequeue(rxQueue);

    /* Call driver init functions */
    Board_init();
    GPIO_init();

    /*
     *  Thread 1
     */

    /* Initialize the attributes structure with default values */
    pthread_attr_init(&attrs);
    priParam.sched_priority = 1;

    detachState = PTHREAD_CREATE_DETACHED;
    retc = pthread_attr_setdetachstate(&attrs, detachState);
    if(retc != 0)
    {
        //Error in setting the dettached mode of the thread
        while(1);
    }
    pthread_attr_setschedparam(&attrs, &priParam);

    retc |= pthread_attr_setstacksize(&attrs,THREADSTACKSIZE);
    if(retc!=0)
    {
        //Error setting the stack size
        while(1);
    }

    retc = pthread_create(&thread, &attrs, uartTask, rxQueue);
    if (retc != 0) {
        /* pthread_create() failed */
        while (1);
    }
    /*
     * End Thread 1
     */

    /*
     * Thread 2
     */
//    priParam.sched_priority = 2;
//    pthread_attr_setschedparam(&attrs, &priParam);
//    retc = pthread_create(&ledThread,&attrs,ledTask,NULL);
//    if(retc != 0)
//    {
//        //Failed creating this thread
//        while(1);
//    }
    /*
     * End Thread 2
     */

    /*
     * TX thread
     */

//    priParam.sched_priority = 2;
//    pthread_attr_setschedparam(&attrs, &priParam);
//
//    retc = pthread_create(&txThreadTask, &attrs, txTask, NULL);
//    if(retc != 0)
//    {
//        //Failed to initialize the task
//        while(1);
//    }
    /*
     * End TX thread
     */


    /*
     * Rx thread
     */

    retc = pthread_create(&rxThreadTask, &attrs, rxTask, NULL);
    if(retc != 0)
    {
        while(1);
    }

    /*
     * End Rx Thread
     */

    BIOS_start();

    return (0);
}
