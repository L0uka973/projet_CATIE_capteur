#include "mbed.h"

InterruptIn mypin(BUTTON1); // Déclare une entrée digitale avec interruptions,  elle va détecter les changements d'état du bouton et générer des interruptions.



DigitalOut myled(LED1); // Déclare une sortie digitale `myled` reliée à la LED `LED1` .


void flip() // Cette fonction est appelée lors des interruptions.
{
    myled = mypin;  // synchronisation de l'état de la LED avec l'état du bouton.
   
}

int main()
{
    mypin.rise(&flip); // Attache la fonction `flip` à l'interruption générée lors d'un front montant du signal (quand le bouton passe de 0 à 1).

    
    mypin.fall(&flip);    // Attache  la fonction `flip` à l'interruption générée lors du front descendant du signal (quand le bouton passe de 1 à 0).


    while (1) {    // Boucle infinie pendaqnt laquelle le programme attend les interruptions.       
       
        
        ThisThread::sleep_for(250);     // Introduit une temporisation de 250 ms.


        printf("mypin has value : %d \n\r", mypin.read()); // Affiche l'état actuel du bouton dans la console.

    }
}
