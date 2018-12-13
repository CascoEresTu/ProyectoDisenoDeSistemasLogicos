#include <SevSeg.h>

int primero = 0;
int segundo = 0;

SevSeg sevseg; //Initiate a seven segment controller object

int interval = 1000;
// Tracks the time since last event fired
unsigned long previousMillis = 0;

void setup()
{
    byte numDigits = 4;
    byte digitPins[] = {2, 3, 4, 5};
    byte segmentPins[] = {6, 7, 8, 9, 10, 11, 12, 13};

    sevseg.begin(COMMON_CATHODE, numDigits, digitPins, segmentPins);
    sevseg.setBrightness(90);

    Serial.begin(9600);
}

void loop()
{
    unsigned long currentMillis = millis();

    // How much time has passed, accounting for rollover with subtraction!
    if ((unsigned long)(currentMillis - previousMillis) >= interval)
    {
        // Use the snapshot to set track time until next event
        previousMillis = currentMillis;
    }
    int digits[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int digits1[] = {0, 1, 2, 3};
    //sevseg.refreshDisplay(); // Must run repeatedly
}

void numero(int x, int primero, int segundo){

    while (true){
        if (segundo == 9){
            segundo == 0;
        }

        for (segundo < 6; primero++;){

            if (primero == 5){
                primero = 0;
            }
            for (primero < 10; primero++;){
                x = 2000 + 400 + segundo * 10 + primero;

                // sevseg.setNumber(temp);
                //   sevseg.refreshDisplay(); // Must run repeatedly
            }
        };
    }
}