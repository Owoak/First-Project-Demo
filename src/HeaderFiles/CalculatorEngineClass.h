#pragma once
#include "LcdClass.h"
#include "KeypadClass.h"


class Engine final{
    private:
        LcdScreen Screen;
        Keypad keypad;

    public:
        Engine():Screen(),keypad(){
            
        }

        void printScreen() {
            Screen.printToLcd();
        }


        void setupLcd(){
            Screen.setupLcd();
        }
        void setupKeypad(){
        

        }
};