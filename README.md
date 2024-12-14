![](./resources/official_armmbed_example_badge.png)

Les prochaines étapes se basent sur l'hypothèse que l'utilisateur a déjà l'environnement mbed installé.

# Téléchargement du dépot git
   * Activer l'environnement virtuel pour ne pas oublier
```bash
   $ source <env_name>/bin/activate
```
   * Clonage du répertoire git
```bash
   $ git clone https://github.com/L0uka973/projet_CATIE_capteur
```
Pour éviter d'utiliser la connection de l'enseirb, avoir un dossier mbed-os.zip et le coller dans le repertoire `projet_CATIE_capteur\`
   * Se rendre dans le repertoire cloné `projet_CATIE_capteur\` 
```bash
   $ cd projet_CATIE_capteur
```
   * Pour gagner du temps avec la connection de l'enseirb 
```bash
   $ unzip mbed-os.zip
```
   * Pour supprimer un répertoire qui n'a pas pu être enlevé du dépot git
```bash
   $ rm -d mbed_zest-core-fmlr-72
```
   * Installation des dépendances des différents fichiers .lib
```bash
   $ mbed deploy
```
   * Pour être sur que le répertoire actuel est le répertoire racine du projet Mbed
```bash
   $ mbed config root .
```
```bash
   $ mbed target ZEST_CORE_FMLR-72
   $ mbed toolchain GCC_ARM
```
   * Pour compiler
```bash
   $ mbed compile
```
   * Pour flash la carte
```bash
   $ sixtron_flash
```
# Exercices

Pour les diffférents exercices il faut copier le contenue du main.cpp correspondant au commit de l'exercice et le coller dans le main.cpp du projet. Ensuite compiler et flasher la carte. 

   1. Polling du bouton.
     
L'exercice du Polling avec le bouton se trouve dans le commit "Exercice Pooling" : https://github.com/L0uka973/projet_CATIE_capteur/blob/06e16333adaaded940b8914ebc46d489e602cffd/main.cpp

Description: Ce code permet de controler l'état d'une LED avec un bouton. L'état du bouton est lu en continue,  si le bouton est pressé ( état 1) la LED s'allume (état 1), si le bouton passe à l'état 0 la LED s'éteint (état 0).

   2. Utiliser une interruption.

L'exercice avec l'interruption se trouve dans le commit "Exercice Interruption" : https://github.com/L0uka973/projet_CATIE_capteur/blob/1362bbc01f03b877a04ee7c510ee52cf1d0cb4b6/main.cpp

Description : Le code utilise des interruptions pour synchroniser l’état d’un bouton avec une LED.

   3. Ajouter un timer

L'exercice avec timer se trouve dans le commit "Exercice Timer" : https://github.com/L0uka973/projet_CATIE_capteur/blob/949c61aea82a69e3541a8188d51b0141051f4d47/main.cpp


Description : Ce code utilise des interruptions pour mesurer le temps écoulé entre l'appui et le relâchement d'un bouton, tout en synchronisant l'état d'une LED avec l'état du bouton. Il affiche l'état du bouton et le temps écoulé dans la console série.
    
   4. Contrôle de la LED par un ticker

L'exercice avec ticker se trouve dans le commit "Exercice Ticker" : https://github.com/L0uka973/projet_CATIE_capteur/blob/0bbcbb3e9e07eb59e38400573aedeeb07156de2a/main.cpp

Description : Le code fait clignoter la LED 'LED1' toutes les 2 secondes en inversant son état à chaque intervalle.
      
   5. Piloter la fréquence de clignotement

L'exercice avec le côntrole de la fréquence se trouve dans le commit "Exercice changement fréquence" : https://github.com/L0uka973/projet_CATIE_capteur/blob/c9d6f10fc5e7ba52e346195619a03a0889daaa41/main.cpp

Pour réaliser cette exercice, nous avons utilisé une variable globale qui va décrémenter si on appuie sur le bouton. 

Description : Le code utilise un bouton pour ajuster la fréquence du clignotement d'une LED, en diminuant cette fréquence à chaque pression du bouton. La LED est contrôlée par un Ticker, qui inverse son état à intervalles réguliers basés sur la fréquence actuelle. La fréquence est affichée périodiquement dans la console.

   6. Thread

L'exercice Thread se trouve dans le commit "TP thread" : https://github.com/L0uka973/projet_CATIE_capteur/blob/b7a105368b8a6cfcbf0db97cad3d91482a6fdb49/main.cpp

Description : Pour cet exercice, deux threads ping et pong sont crées pour être s'éxécuter en parallèle. De plus, en tâche de fond une LED clignotte toutes les secondes.Les deux threads, ping et pong,  affichent respectivement "ping" et "pong" 100 fois sur la console série. On a pu constater un problème , les messages se mélangent . Les deux threads s'exécutent de manière concurrente et non synchronisée donc ils peuvent accéder à la console série en même temps, ce qui entraîne ce mélange des messages.

   7. Mutex

L'exercice Mutex se trouve dans le commit "TP mutex" : https://github.com/L0uka973/projet_CATIE_capteur/blob/1c440253c51e7e798cc0412a40d09223c30109de/main.cpp

Description :Cette fois ci, un mutex est utilisé pour synchroniser l'accès au terminal (printf). Ainsi, on évite que les deux messages des threads s'entrelacent. 

# Projet
## Communication avec le capteur
La carte capteur que nous avons en notre possession est la carte "Zest_Sensor_Dust". Pour communiquer avec le capteur, nous devons comprendre la datasheet. 
Le module embarque le capteur de la marque Honeywell "HPMA115C0" en version compact. Pour résumer les fonctionnalités de ce capteur, il permet de mesurer 4 tailles de particule (PM1, PM2.5, PM4 et PM10). Le capteur communique en UART. 

Il y a plusieurs commandes qui permettent de communiquer avec le capteur. Les principales sont : Lecture des données, Début/Arrêt de la mesure, Activation/Arrêt de l'autosend de la mesure.
Nous avons perdu beaucoup de temps à comprendre la cohérence des données reçues avec les données de la datasheet. Mais l'erreur principale que nous avons fait est de ne pas avoir arrêter l'autosend. Pendant un moment on pensait que ce mode était désactivé ce qui nous donnait des résultats illogiques.
Pour être sur de lire correctement les données il fallait envoyer les bonnes commandes : 
  1. D'abord il faut arrêter l'autosend
  2. Ensuite il faut commencer la prise de mesure
  3. On peut maintenant lire convenablement les données du capteur.

Le fichier source se trouve dans le commit "uart DUST fonctionnel" : https://github.com/L0uka973/projet_CATIE_capteur/blob/1410516eaa2958ca7fc057429813a2961958aed0/main.cpp
## LoRa
Nous avons perdu beaucoup de temps sur la communication avec le capteur alors pour le rattraper nous avons utiliser les drivers du CATIE pour la suite du projet.

La première étape était d'envoyer une donnée brute sur l'interface LoRaWAN et d'afficher cette donnée sur ThingsBoard. Le code source est disponible au commit "Ajout des drivers pour la carte Dust et envoie d'une donnée à l'aide de l'exemple LoRa" : https://github.com/L0uka973/projet_CATIE_capteur/blob/47189aa0c80960224c1e46f6438ac13ad5d71d83/hpma115.cpp

La dernière étape est de remplacer remplacer ces données brutes par celles du capteur. Pour cela, nous allons utiliser le driver du catie pour lire ces données. On utilise sprintf pour convertir les données en string avec les balises associées. Les balises ont pour format : < \"PMx\": >.
Concernant l'affichage sur ThingsBoard, nous avons 4 boards pour les 4 catégories. Toutes les valeurs sont affichées et des courbes permettent de retranscrire les données antérieures. Source au commit " Projet Capteur terminé avec affichage grâce à LoRa" : https://github.com/L0uka973/projet_CATIE_capteur/blob/ec6fb6374c7c07b677166a2658aac205091a0602/main.cpp

<img width="563" alt="CAPTEUR_EMB1" src="https://github.com/user-attachments/assets/ff279894-88e1-49dc-8234-7ecbac1c22e5">

<img width="581" alt="CAPTEUR_EMB2" src="https://github.com/user-attachments/assets/bfd7f79f-2d37-4b22-a5b5-c18fa8271971">

# Related Links

* [Mbed OS Stats API](https://os.mbed.com/docs/latest/apis/mbed-statistics.html).
* [Mbed OS Configuration](https://os.mbed.com/docs/latest/reference/configuration.html).
* [Mbed OS Serial Communication](https://os.mbed.com/docs/latest/tutorials/serial-communication.html).
* [Mbed OS bare metal](https://os.mbed.com/docs/mbed-os/latest/reference/mbed-os-bare-metal.html).
* [Mbed boards](https://os.mbed.com/platforms/).

### License and contributions

The software is provided under Apache-2.0 license. Contributions to this project are accepted under the same license. Please see [CONTRIBUTING.md](./CONTRIBUTING.md) for more info.

This project contains code from other projects. The original license text is included in those source files. They must comply with our license guide.
send_message


