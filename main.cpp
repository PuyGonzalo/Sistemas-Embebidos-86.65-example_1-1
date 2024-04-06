#include "mbed.h"
#include "arm_book_lib.h"

int main()
{
    // Inicializaciones
    DigitalIn gasDetector(D2); /** @note: Inicializa el GPIO correspondiente a D2 (de la placa de) como un Digital input */

    DigitalOut alarmLed(LED1); /** @note: Inicializa el GPIO correspondiente al LED1 (de la placa de desarrollo) como un Digital output. */

    gasDetector.mode(PullDown); /**
                                * @note: Setea el pin D2 (digital input) en modo Pull Down. En este ejemplo se utiliza un switch conectado al pin D2.
                                * De esta forma, sabemos que el estado logico del pin sera LOW (0 V) y que cuando se presione el swtich se pasara a un estado HIGH (en este caso 3,3 V)
                                * Por ende, el swtich tiene que ir conectado entre VCC y el pin D2 de la placa de desarrollo.
                                */

    alarmLed = OFF; /** @note: Seteo el LED en OFF como estado inicial. */

    printf("%s\n", "Hola! Somos Gonzalo y Gustavo!!"); /** @note: Imprime por consola la linea. */

    /**
    * @note: Loop infinito en donde leo constantemente la entrada digital definida como gasDetector.
    */
    while (true) {
        if ( gasDetector == ON ) { // Si detecto que esta presionado el pulsador (se activo el detector de gas)
            alarmLed = ON;         // Prendo la alarma (LED)
        }
        
        if ( gasDetector == OFF ) { // Si detecto que NO esta presionado el pulsador (NO se activo el detector de gas)
            alarmLed = OFF;
        }

        /**
        * Esto lo puedo reescribir de la siguiente forma para que quede un codigo mas compacto y no tenga que leerse otro if:
        *
        * if ( gasDetector == ON ) {
        *    alarmLed = ON;
        * }else
        *    alarmLed = OFF;
        *
        **/
    }
}