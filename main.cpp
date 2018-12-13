#include "SevSeg.h"

SevSeg sev;
SevSeg sevseg;

unsigned long antesMillis1 = 0;
int intervalo1 = 1000;
int x = 0;
int y = 0;
int unseg = 0;
int decseg = 0;
int unmin = 0;
int decmin = 0;
int horas = 0;
int dechoras = 0;
 
void setup()
{
    byte numeroDigitos = 5;
    byte digitosPins[] = {51, 5, 4, 3, 2};// Pins para los 4 digitos del display para los minutos y segundos
    byte segmentosPins[] = {6, 7, 8, 9, 10, 11, 12, 13}; // Pins para los leds del display

    byte numeroDigitos2 = 2;
    byte digitosPins2[] = {23, 22};// Pins para los 2 digitos del display para las horas
    byte segmentosPins2[] = {24, 25, 26, 27, 28, 29, 30, 31}; // Pins para los leds del display

    sevseg.begin(COMMON_CATHODE, numeroDigitos2, digitosPins2, segmentosPins2); // iniciar
    sev.begin(COMMON_CATHODE, numeroDigitos, digitosPins, segmentosPins);       // iniciar
}

void loop()
{
    x = unseg + decseg * 10 + unmin * 100 + decmin * 1000 + 10000; // valor de hora de inicio
    y = horas + dechoras * 10;
    sev.setNumber(x, 2);
    sevseg.setNumber(y, 0);
    sev.refreshDisplay();
    sevseg.refreshDisplay();
    unsigned long actualMillis = millis();

    if ((unsigned long)(actualMillis - antesMillis1) >= intervalo1) // reiniciar el conteo
    {
        unseg = unseg + 1;

        if (unseg == 10)
        {
            unseg = 0;
            decseg = decseg + 1;
        }

        if (decseg == 6)
        {
            decseg = 0;
            unmin = unmin + 1;
        }

        if (unmin == 10)
        {
            unmin = 0;
            decmin = decmin + 1;
        }

        if (decmin == 6)
        {
            decmin = 0;
            horas = horas + 1;
        }

        if (horas == 10)
        {
            horas = 0;
            dechoras = dechoras + 1;
        }

        if (dechoras == 3)
        {
            dechoras = 0;
        }

        if (dechoras == 2 & horas == 4)
        {
            unseg = 0;
            decseg = 0;
            unmin = 0;
            decmin = 0;
            horas = 0;
            dechoras = 0;
        }
        antesMillis1 = actualMillis;
    }
}
