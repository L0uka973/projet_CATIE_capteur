#include "mbed.h"

DigitalIn mypin(BUTTON1);// Déclare une entrée digitale `mypin` reliée à un bouton `BUTTON1` que l'utilisateur doit appuyer.


DigitalOut myled(LED1); // Déclare une sortie digitale `myled` reliée à une LED `LED1` qui doit s'allumer et s'éteindre.


int main()
{
    
    if (mypin.is_connected()) { // Vérifie si `mypin` est correctement initialisé et connecté à un pin.
        printf("mypin is connected and initialized! \n\r"); // Affiche un message dans la console si `mypin` est connecté.
        
    }
        
    mypin.mode(PullNone);// Configure le mode d'entrée du bouton en indéterminé ( L'état de départ n'est pas forcé à 1 pull-up ou 0 pull-down) en forçant pas l'état d'entrée à 1 ou 0 
   
    while (1) {
        
        printf("mypin has value : %d \n\r", mypin.read()); // Lit l'état actuel du bouton (1 = pas pressé, 0 = pressé) et l'affiche dans la console.

        
        myled = mypin;// Affecte l'état du bouton à la LED.
        // Si le bouton est pressé (0), la LED s'éteint ; sinon, elle s'allume.

        ThisThread::sleep_for(250); // Ajoute une temporisation de 250 ms.

    }
}
