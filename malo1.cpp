#include "SevSeg.h"
SevSeg sevseg; //Initiate a seven segment controller object
int interval1 = 1000;
int interval2 = 10000;
int interval3 = 60000;
unsigned long previousMillis1 = 0;
unsigned long previousMillis2 = 0;
unsigned long previousMillis3 = 0;
int x = 0;
int unseg = 5;
int decseg = 4;
int unmin = 9;
int decmin = 1;
void setup()
{
    byte numDigits = 4;
    byte digitPins[] = {2, 3, 4, 5};
    byte segmentPins[] = {6, 7, 8, 9, 10, 11, 12, 13};
    sevseg.begin(COMMON_CATHODE, numDigits, digitPins, segmentPins);
    sevseg.setBrightness(90);
}
void loop()
{
    x = unseg + decseg * 10 + unmin * 100 + decmin * 1000;
    sevseg.setNumber(x, 2);
    sevseg.refreshDisplay(); // Must run repeatedly
    unsigned long currentMillis = millis();

    if ((unsigned long)(currentMillis - previousMillis1) >= interval1)
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

        previousMillis1 = currentMillis;
    }
}