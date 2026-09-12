#pragma once

#include "LcdClass.h"
#include "KeypadClass.h"



class Engine final{
    private:
        LcdScreen Screen;
        Keypad keypad;

        String equation[3];

    public:
        Engine():Screen(),keypad(),equation({"\0"}){
            
        }
        ~Engine(){}
        Engine(const Engine& other) = delete;
        Engine& operator=(const Engine& other) = delete;
        
        void setupLcd(){
            Screen.setup();
        }
        void setupKeypad(){
            keypad.setup();
        }
        void InputHandler(){
            char keyPressed = keypad.ButtonPressed();
            if (keyPressed != '\n'){
                equation[0] = String(keyPressed);
                printScreen();






            }
        }


    private:
        void printScreen() {
            Screen.printToLcd(equation[0],equation[1],equation[2]);
        }
};