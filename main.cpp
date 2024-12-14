
/************** FREQUENCE *********************/
#include "mbed.h"


Ticker flipper;
DigitalOut myled(LED1);
InterruptIn mypin(BUTTON1);


int freq = 5; // Variable globale pour stocker la fréquence (initialisée à 5)


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
