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
        
        //se hace reset de las unidades, y se agrega a la decena
        if (unseg == 10)
        {
            unseg = 0;
            //decseg = decseg + 1;
            decseg++;
        }
        //se limpia la decena, y se agrega minuto    
        if (decseg == 6)
        {
            decseg = 0;
            //unmin = unmin + 1;
            unmin++;
        }
         //se hace reset a la unidad de minuto, y se incrementa la decena 
        if (unmin == 10)
        {
            unmin = 0;
            //decmin = decmin + 1;
            decmin++;
        }
        //.....
        if (decmin == 6)
        {
            decmin = 0;
            //horas = horas + 1;
            horas++;
        }
        
        //.....
        if (horas == 10)
        {
            horas = 0;
            //dechoras = dechoras + 1;
            dechoras++;
        }
        //.....
        if (dechoras == 2)
        {
            dechoras = 0;
        }
        previousMillis1 = currentMillis;
    }
}
