#pragma once
#include "LcdClass.h"
#include "KeypadClass.h"


class Engine final{
    private:
        LcdScreen Screen;
        Keypad keypad;

        long int * FirstNumber;
        long int * SecondNumber;
        char * Action;

    public:
        Engine():Screen(),keypad(),FirstNumber(nullptr),SecondNumber(nullptr),Action(nullptr){
            
        }
        ~Engine(){
            if (FirstNumber != nullptr){
                delete FirstNumber;
            }
            if (SecondNumber != nullptr){
                delete SecondNumber;
            }
            if (Action != nullptr){
                delete Action;
            }
        }
        Engine(const Engine& other) = delete;
        Engine& operator=(const Engine& other) = delete;
       
        void setupLcd(){
            Screen.setupLcd();
        }
        void setupKeypad(){
    
        }

    private:
        void printScreen() {
            Screen.printToLcd(FirstNumber,SecondNumber,Action);
        }
};