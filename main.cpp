/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"

// Blinking rate in milliseconds
#define BLINKING_RATE     1000ms

// Specify different pins to test printing on UART other than the console UART.
#define TARGET_TX_PIN                                                     USBTX
#define TARGET_RX_PIN                                                     USBRX

// Create a BufferedSerial object to be used by the system I/O retarget code.
static BufferedSerial serial_port(TARGET_TX_PIN, TARGET_RX_PIN, 9600);

// Déclaration des threads
Thread thread_ping(osPriorityNormal, 1024, nullptr, nullptr);
Thread thread_pong(osPriorityNormal, 1024, nullptr, nullptr);
Mutex mutex;

void ping()
{   
    for(int i = 0; i < 100; i++){
        mutex.lock();
        printf("ping\n");
        mutex.unlock();
    }
    
}

void pong()
{
    for(int i = 0; i < 100; i++){
        mutex.lock();
        printf("pong\n");
        mutex.unlock();
    }
}

int main() {
    

    // Lancement des threads
    thread_ping.start(ping);
    thread_pong.start(pong);



 // Initialise the digital pin LED1 as an output
#ifdef LED1
    DigitalOut led(LED1);
#else
    bool led;
#endif

    while (true) {
        // print to the console using the `serial_port` object.
    //printf( "Alive!\n" );
        led = !led;
        ThisThread::sleep_for(BLINKING_RATE);
    }
    return 0;
}


