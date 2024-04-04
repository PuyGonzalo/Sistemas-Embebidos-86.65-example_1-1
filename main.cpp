#include "mbed.h"
#include "arm_book_lib.h"

int main()
{
    // Inicializaciones
    DigitalIn gasDetector(D2); //Poner aca que hace esto

    DigitalOut alarmLed(LED1); //Poner aca que hace esto

    gasDetector.mode(PullDown); //Poner aca que hace esto

    alarmLed = OFF; // Seteo el LED en OFF
    printf("%s\n", "Hola! Somos Gonzalo y Gustavo!!");

    while (true) { // Loop infinito en donde leo constantemente la entrada digital definida como gasDetector
        if ( gasDetector == ON ) { // Si detecto que esta presionado el pulsador (se activo el detector de gas)
            alarmLed = ON;         // Prendo la alarma (LED)
        }
        
        if ( gasDetector == OFF ) { // Si detecto que esta NO presionado el pulsador (NO se activo el detector de gas)
            alarmLed = OFF;
        }
    }
}