
#include <Arduino.h>
#include "HeaderFiles/CalculatorEngineClass.h"

Engine engine;

void setup()
{
    engine.setupLcd();
    engine.setupKeypad();
    engine.printScreen();
}

void loop()
{
}
                       
