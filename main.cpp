#include "SevSeg.h"

SevSeg sevseg;

int interval1 = 1000;
unsigned long previousMillis1 = 0;
int x = 0;
int unseg = 0;
int decseg = 5;
int unmin = 9;
int decmin = 0;
int horas = 0;
int dechoras = 0;

void setup()
{
    byte numDigits = 6;
    byte digitPins[] = {2, 3, 4, 5};                   // Pins para los 4 digitos
    byte segmentPins[] = {6, 7, 8, 9, 10, 11, 12, 13}; // Pins para los leds del display

    sevseg.begin(COMMON_CATHODE, numDigits, digitPins, segmentPins); // iniciar la biblioteca
}

void loop()
{
    x = unseg + decseg * 10 + unmin * 100 + decmin * 1000 + horas * 10000 + dechoras * 100000; // valor de hora de inicio
    sevseg.setNumber(x, 2);
    sevseg.refreshDisplay();
    unsigned long currentMillis = millis();

    if ((unsigned long)(currentMillis - previousMillis1) >= interval1) // reiniciar el conteo
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

        if (dechoras == 2)
        {
            dechoras = 0;
        }
        previousMillis1 = currentMillis;
    }
}