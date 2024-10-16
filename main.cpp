/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

/************** FREQUENCE *********************/
#include "mbed.h"


Ticker flipper;
DigitalOut myled(LED1);
InterruptIn mypin(BUTTON1);

// Variable globale pour stocker la fréquence (initialisée à 5)
int freq = 5; 


void flip()
{
    myled = !myled;  // Inversion de l'état de la LED 
}

// Fonction appelée lorsqu'il y a un appui sur le bouton 
void frequence()
{
    // Décrémente la temps à chaque appui sur le bouton
    freq = freq - 1;

    // Modifie la temps de la fonction flip en réattachant le ticker avec la nouvelle fréquence
    flipper.attach(&flip, freq); 
}

int main()
{
    // Première attache la fonction flip pour être appelée périodiquement avec une fréquence initiale
    flipper.attach(&flip, freq);  

    // Interrutpion sur appuie du bouton pour décrementer la fréquence
    mypin.rise(&frequence);


    while (1) {
        // Affichage la variable fréquence sur la console
        printf("freq: %d \n\r", freq);
        ThisThread::sleep_for(250);
    }
}
/*******************************************/


/************** Ticker *********************/
/*
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
*/
/*******************************************/


/************** Timer *********************/
/*
#include "mbed.h"
InterruptIn mypin(BUTTON1); 
DigitalOut myled(LED1);

using namespace std::chrono;

Timer t;

void timer_on()
{
    t.start();             // Démarre le chronomètre quand le bouton est pressé
    myled = mypin;       
}

void timer_off()
{
    myled = mypin;        
    t.stop();              // Arrête le chronomètre quand le bouton est relâché
    t.reset();             // Réinitialise le chronomètre
}

int main()
{
    mypin.rise(&timer_on);  // Appelle la fonction `timer_on` lors de l'appuie du bouton 
    mypin.fall(&timer_off); // Appelle la fonction `timer_off` lors du relachement du bouton 

    while (1) {            
        ThisThread::sleep_for(250); 
        printf("mypin has value : %d \n\r", mypin.read()); // Affiche l'état du bouton
        printf("The time taken was %llu milliseconds\n", duration_cast<milliseconds>(t.elapsed_time()).count()); // Affiche le temps mesuré par le Timer 
    }
}
/*******************************************/


/************** INTERRUTPION *********************/
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
    mypin.rise(&flip);  // Interruption sur appuie du bouton pour que la LED s'allume
    mypin.fall(&flip);  // Interruption sur relachement du bouton pour que la LED s'eteigne

    while (1) {          
 
        ThisThread::sleep_for(250);
        printf("mypin has value : %d \n\r", mypin.read());
    }
}
*/
/*******************************************/



/************** POLLING *********************/
/*
#include "mbed.h"
DigitalIn mypin(BUTTON1); 
DigitalOut myled(LED1);


int main()
{
   
    while (1) {
        printf("mypin has value : %d \n\r", mypin.read()); //Affichage de l'etat du bouton
        myled = mypin; // Changement de l'etat de la LED
        ThisThread::sleep_for(250);
    }
}
*/
/*******************************************/

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


