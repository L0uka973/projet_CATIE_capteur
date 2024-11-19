/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"


// Configuration des broches UART pour mbed
UnbufferedSerial uart(PA_9, PA_10, 9600); // TX, RX, baudrate
BufferedSerial pc(USBTX, USBRX);          // Interface série pour le PC

// Commandes pour le capteur HPM
const uint8_t CMD_START[] = {0x68, 0x01, 0x01, 0x96}; // Démarrer la mesure
const uint8_t CMD_READ[]  = {0x68, 0x01, 0x04, 0x93}; // Lire les résultats
const uint8_t CMD_STOP[]  = {0x68, 0x01, 0x02, 0x95}; // Arrêter la mesure
const uint8_t CMD_STOP_SEND[]  = {0x68, 0x01, 0x20, 0x77}; // Arrêter auto send

// Fonction pour envoyer une commande au capteur
void send_command(const uint8_t* command, size_t length) {
    uart.write(command, length);
}

void debug_raw_data(const uint8_t* buffer, size_t length) {
    printf("Données brutes :");
    for (size_t i = 0; i < length; i++) {
        printf(" %02X", buffer[i]);
    }
    printf("\n");
}

void flush()
{
    uint8_t temp = 0;
    while (uart.readable())
    {   
        uart.read(&temp, 1);
    }
}

bool read_sensor_data(uint16_t &pm25, uint16_t &pm10, uint16_t &pm1, uint16_t &pm4) {
    uint8_t buffer[32] = {0};
    uint8_t octet = 0;
    flush();
    for(int i = 0; i<32; i++){
            //while (uart.readable()) {
                uart.read(&octet, 1);
                //printf(" %02X\n", octet);
                buffer[i] = octet;
            //}
        }
 
        // Affiche les données brutes pour déboguer
        debug_raw_data(buffer, 32);

        // Vérification de l'en-tête
        if (buffer[0] == 0x42 && buffer[1] == 0x4D) {
            pm1 = (buffer[4] << 8) | buffer[5]; // PM1
            pm25 = (buffer[6] << 8) | buffer[7]; // PM2.5
            pm4 = (buffer[8] << 8) | buffer[9]; // PM4
            pm10 = (buffer[10] << 8) | buffer[11]; // PM10
            return true;
        }
    return false;
}

int main() {
    pc.set_baud(9600);

    //Flush
    uint8_t buff[16] = {0};
    uint8_t oc = 0;
    // Initialisation
    printf("Initialisation du capteur HPM\n");
    printf("STOP AUTO SEND\n");
    send_command(CMD_STOP_SEND, sizeof(CMD_STOP_SEND));
    for(int i = 0; i<2; i++){
                uart.read(&oc, 1);
                printf(" %02X\n", oc);
    }
    printf("START\n");
    send_command(CMD_START, sizeof(CMD_START));
     for(int i = 0; i<2; i++){
                uart.read(&oc, 1);
                printf(" %02X\n", oc);
    }
    thread_sleep_for(6000); // Attente pour stabilisation
   
    
    while (true) {
        uint16_t pm25 = 0, pm10 = 0, pm1 = 0, pm4 = 0;

        // Lecture des données
        printf("READ\n");
        send_command(CMD_READ, sizeof(CMD_READ));
         for(int i = 0; i<16; i++){
                uart.read(&oc, 1);
                //printf("%d : %02X\n", i, oc);
                buff[i] = oc;
         }
        printf("ok\n");
        for (size_t i = 0; i < 16; i++) {
        printf(" %d, %02X\n", i, buff[i]);
        }
        thread_sleep_for(2000); // Délai avant lecture
        
        if (read_sensor_data(pm25, pm10, pm1, pm4)) {
            printf("PM1: %d µg/m3\nPM2.5: %d µg/m3\nPM4: %d µg/m3\nPM10: %d µg/m3\n", pm1, pm25, pm4, pm10);
        } else {
            printf("Erreur de lecture des données du capteur\n");
        }
       
        thread_sleep_for(5000); // Attente avant la prochaine lecture
    }

    // Arrêt du capteur (si nécessaire)
    send_command(CMD_STOP, sizeof(CMD_STOP));
}


