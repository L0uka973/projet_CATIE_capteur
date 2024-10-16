/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */


#include "mbed.h"

Ticker flipper;
DigitalOut myled(LED1);


void flip()
{
    myled = !myled;
}

int main()
{
    flipper.attach(&flip, 2.0); // the address of the function to be attached (flip) and the interval (2 seconds)    
}


/*
#include "mbed.h"
InterruptIn mypin(BUTTON1); 
DigitalOut myled(LED1);

using namespace std::chrono;

Timer t;


void timer_on()
{
    t.start();
    myled = mypin;
    
}

void timer_off()
{
 
    myled = mypin;
    t.stop();
    t.reset();
 
}

int main()
{
    mypin.rise(&timer_on);  // attach the address of the flip function to the rising edge
    mypin.fall(&timer_off);

    while (1) {          // wait around, interrupts will interrupt this!
 
        ThisThread::sleep_for(250);
        printf("mypin has value : %d \n\r", mypin.read());
        printf("The time taken was %llu milliseconds\n", duration_cast<milliseconds>(t.elapsed_time()).count());
    }
}
*/

/*
#include "mbed.h"
InterruptIn mypin(BUTTON1); 
DigitalOut myled(LED1);

void flip()
{
    myled = mypin;
}


int main()
{
    mypin.rise(&flip);  // attach the address of the flip function to the rising edge
    mypin.fall(&flip);

    while (1) {          // wait around, interrupts will interrupt this!
 
        ThisThread::sleep_for(250);
        printf("mypin has value : %d \n\r", mypin.read());
    }
}
*/

/*
#include "mbed.h"
DigitalIn mypin(BUTTON1); 
DigitalOut myled(LED1);


int main()
{
    // check mypin object is initialized and connected to a pin
    if (mypin.is_connected()) {
        printf("mypin is connected and initialized! \n\r");
    }

    // Optional: set mode as PullUp/PullDown/PullNone/OpenDrain
    mypin.mode(PullNone);

    // press the button and see the console / led change
    while (1) {
        printf("mypin has value : %d \n\r", mypin.read());
        myled = mypin; // toggle led based on value of button
        ThisThread::sleep_for(250);
    }
}
*/


/*
// Blinking rate in milliseconds
#define BLINKING_RATE     500ms

// Specify different pins to test printing on UART other than the console UART.
#define TARGET_TX_PIN                                                     USBTX
#define TARGET_RX_PIN                                                     USBRX

// Create a BufferedSerial object to be used by the system I/O retarget code.
static BufferedSerial serial_port(TARGET_TX_PIN, TARGET_RX_PIN, 9600);

FileHandle *mbed::mbed_override_console(int fd)
{
    return &serial_port;
}


int main()
{
    // Initialise the digital pin LED1 as an output
#ifdef LED1
    DigitalOut led(LED1);
#else
    bool led;
#endif

    while (true) {

        // print to the console using the `serial_port` object.
    printf(
        "Hello world\n"
    );
        led = !led;
        ThisThread::sleep_for(BLINKING_RATE);
    }
}*/


