
#include <Arduino.h>
#include "HeaderFiles/Defines.h"
#include "HeaderFiles/CalculatorEngineClass.h"

Engine engine;

void setup()
{
    Serial.begin(9600);
    engine.setupLcd();
    engine.setupKeypad();
}

void loop()
{
    engine.process();
    delay(200);
    
}                  