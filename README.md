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

Pour les diffférents exercices il faut copier le contenue du main.cpp correspondant au commit de l'exercice et le coller dans le main.cpp du projet.

   1. Polling du bouton.
     
L'exercice du Polling avec le bouton se trouve dans le commit "Pooling du bouton" : https://github.com/L0uka973/projet_CATIE_capteur/blob/fba7df308ef7c4425ebff8b5c5e005ae7dd080c4/main.cpp

   2. Utiliser une interruption.

L'exercice avec l'interruption se trouve dans le commit "interruption" : https://github.com/L0uka973/projet_CATIE_capteur/blob/8f73846f4bf2cb6d933122575ab8f865d9f9ef60/main.cpp

   3. Ajouter un timer

L'exercice avec timer se trouve dans le commit "Timer" : https://github.com/L0uka973/projet_CATIE_capteur/blob/6733e83df5dda08faff43534e47ef319fc7d60bb/main.cpp
    
   4. Contrôle de la LED par un ticker

L'exercice avec ticker se trouve dans le commit "Ticker" : https://github.com/L0uka973/projet_CATIE_capteur/blob/369bdf9e77eedfa843995a632f8d4b59d574f63a/main.cpp
      
   5. Piloter la fréquence de clignotement

L'exercice avec le côntrole de la fréquence se trouve dans le commit "  TP FREQUENCE : Utilisation d'une variable globale qui est modifiée afin de modifier la fréquence de clignotemment de la LED" : https://github.com/L0uka973/projet_CATIE_capteur/blob/e022e2a7069a0f2eb22725b9378da28fadb15ca5/main.cpp

Pour réaliser cette exercice, nous avons utilisé une variable globale qui va décrémenter si on appuie sur le bouton. 

   6. Thread

      https://github.com/L0uka973/projet_CATIE_capteur/blob/b7a105368b8a6cfcbf0db97cad3d91482a6fdb49/main.cpp

   7. Mutex

       https://github.com/L0uka973/projet_CATIE_capteur/blob/1c440253c51e7e798cc0412a40d09223c30109de/main.cpp


# Projet

Communication avec le capteur

Pb lecture des données (lecture datasheet -> capteur en autosend)
utilisation du driver du catie pour rattraper le temps perdu
<img width="563" alt="CAPTEUR_EMB1" src="https://github.com/user-attachments/assets/ff279894-88e1-49dc-8234-7ecbac1c22e5">

<img width="581" alt="CAPTEUR_EMB2" src="https://github.com/user-attachments/assets/bfd7f79f-2d37-4b22-a5b5-c18fa8271971">

# Blinky Mbed OS example

The example project is part of the [Arm Mbed OS Official Examples](https://os.mbed.com/code/) and is the [getting started example for Mbed OS](https://os.mbed.com/docs/mbed-os/latest/quick-start/index.html). It contains an application that repeatedly blinks an LED on supported [Mbed boards](https://os.mbed.com/platforms/).

You can build the project with all supported [Mbed OS build tools](https://os.mbed.com/docs/mbed-os/latest/tools/index.html). However, this example project specifically refers to the command-line interface tools, [Arm Mbed CLI 1](https://github.com/ARMmbed/mbed-cli#installing-mbed-cli) and [Mbed CLI 2](https://github.com/ARMmbed/mbed-tools#installation).

(Note: To see a rendered example you can import into the Arm Online Compiler, please see our [import quick start](https://os.mbed.com/docs/mbed-os/latest/quick-start/online-with-the-online-compiler.html#importing-the-code).)

## Mbed OS build tools

### Mbed CLI 2
Starting with version 6.5, Mbed OS uses Mbed CLI 2. It uses Ninja as a build system, and CMake to generate the build environment and manage the build process in a compiler-independent manner. If you are working with Mbed OS version prior to 6.5 then check the section [Mbed CLI 1](#mbed-cli-1).
1. [Install Mbed CLI 2](https://os.mbed.com/docs/mbed-os/latest/build-tools/install-or-upgrade.html).
1. From the command-line, import the example: `mbed-tools import mbed-os-example-blinky`
1. Change the current directory to where the project was imported.

### Mbed CLI 1
1. [Install Mbed CLI 1](https://os.mbed.com/docs/mbed-os/latest/quick-start/offline-with-mbed-cli.html).
1. From the command-line, import the example: `mbed import mbed-os-example-blinky`
1. Change the current directory to where the project was imported.

## Application functionality

The `main()` function is the single thread in the application. It toggles the state of a digital output connected to an LED on the board.

**Note**: This example requires a target with RTOS support, i.e. one with `rtos` declared in `supported_application_profiles` in `targets/targets.json` in [mbed-os](https://github.com/ARMmbed/mbed-os). For non-RTOS targets (usually with small memory sizes), please use [mbed-os-example-blinky-baremetal](https://github.com/ARMmbed/mbed-os-example-blinky-baremetal) instead.

## Building and running

1. Connect a USB cable between the USB port on the board and the host computer.
1. Run the following command to build the example project and program the microcontroller flash memory:

    * Mbed CLI 2

    ```bash
    $ mbed-tools compile -m <TARGET> -t <TOOLCHAIN> --flash
    ```

    * Mbed CLI 1

    ```bash
    $ mbed compile -m <TARGET> -t <TOOLCHAIN> --flash
    ```

Your PC may take a few minutes to compile your code.

The binary is located at:
* **Mbed CLI 2** - `./cmake_build/<TARGET>/develop/<TOOLCHAIN>/mbed-os-example-blinky.bin`
* **Mbed CLI 1** - `./BUILD/<TARGET>/<TOOLCHAIN>/mbed-os-example-blinky.bin`

Alternatively, you can manually copy the binary to the board, which you mount on the host computer over USB.

## Expected output
The LED on your target turns on and off every 500 milliseconds.


## Troubleshooting
If you have problems, you can review the [documentation](https://os.mbed.com/docs/latest/tutorials/debugging.html) for suggestions on what could be wrong and how to fix it.

## Related Links

* [Mbed OS Stats API](https://os.mbed.com/docs/latest/apis/mbed-statistics.html).
* [Mbed OS Configuration](https://os.mbed.com/docs/latest/reference/configuration.html).
* [Mbed OS Serial Communication](https://os.mbed.com/docs/latest/tutorials/serial-communication.html).
* [Mbed OS bare metal](https://os.mbed.com/docs/mbed-os/latest/reference/mbed-os-bare-metal.html).
* [Mbed boards](https://os.mbed.com/platforms/).

### License and contributions

The software is provided under Apache-2.0 license. Contributions to this project are accepted under the same license. Please see [CONTRIBUTING.md](./CONTRIBUTING.md) for more info.

This project contains code from other projects. The original license text is included in those source files. They must comply with our license guide.
send_message


comment installer le depot git, commande et comment le deployer 
expliquer les exos 
explication le projet
différences, processus 
