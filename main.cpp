#include "mbed.h"


Ticker flipper; // Déclare un objet `flipper` de type `Ticker`, qui permet de configurer une fonction à appeler à intervalles réguliers.


DigitalOut myled(LED1); // Déclare un objet `myled` de type `DigitalOut` lié à la LED `LED1`, pour contrôler l'état de la LED (allumée ou éteinte).


void flip()
{
    myled = !myled;     // La fonction `flip` inverse l'état de la LED. 

}

int main()
{
    flipper.attach(&flip, 2.0);      // Attache la fonction `flip` à l'objet `flipper`. Cette fonction sera appelée toutes les 2 secondes ce qui crée un clignotement.

}
