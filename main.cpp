#include "mbed.h"

InterruptIn mypin(BUTTON1); // Déclare un objet `mypin` de type `InterruptIn` lié au bouton `BUTTON1`qui permet de détecter des changements d'état (comme un appui) et de générer des interruptions.


DigitalOut myled(LED1);// Déclare un objet `myled` de type `DigitalOut` lié à la LED `LED1` pour contrôler son état (allumée ou éteinte).


using namespace std::chrono;// Permet d'utiliser les types et fonctions de la bibliothèque `chrono` pour manipuler les durées.


Timer t; // Déclare un objet `t` de type `Timer`.


void timer_on()
{
    t.start();    // Démarre le timer.

    myled = mypin;  // Modifie l'état de la LED en fonction de l'état du bouton.
   
}

void timer_off()
{
    myled = mypin;    // Modifie l'état de la LED en fonction de l'état du bouton.

    t.stop();     // Arrête le timer .

    t.reset();     // Réinitialise le timer.

}

int main()
{
    mypin.rise(&timer_on);      // Attache la fonction `timer_on` pour qu'elle soit appelée lors du front montant du signal (bouton pressé).
        // le bouton est préssé , timer débute et l'état de la led change ( allumé)
    mypin.fall(&timer_off);    // Attache la fonction `timer_off` pour qu'elle soit appelée lors du front descendant du signal (bouton relâché).
        // L'état de la led change en fonction de l'état du bouton , Le timer est arreté et réinitialisé.   

    while (1) {          
 
        ThisThread::sleep_for(250); // Ajoute une temporisation de 250 ms 
       
        
        printf("mypin has value : %d \n\r", mypin.read());  // Affiche l'état actuel du bouton (1 = non pressé, 0 = pressé).
       
        
        printf("The time taken was %llu milliseconds\n", duration_cast<milliseconds>(t.elapsed_time()).count());  // Affiche le temps écoulé depuis le démarrage du timer (en millisecondes).
       
    }
}
