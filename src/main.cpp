
#include <Arduino.h>
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
    engine.InputHandler();
    
}
                       
