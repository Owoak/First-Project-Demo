#pragma once

#include "LcdClass.h"
#include "KeypadClass.h"
#include "Addition.h"
#include "Subtraction.h"
#include "Multiplication.h"



class Engine final{
    private:
        LcdScreen Screen;
        Keypad keypad;

        String equation[3];
        BaseAction * operation;

    public:
        Engine():Screen(),keypad(),equation(),operation(nullptr){
            
        }
        ~Engine(){clear();}
        Engine(const Engine& other) = delete;
        Engine& operator=(const Engine& other) = delete;
        
        void setupLcd(){
            Screen.setup();
        }
        void setupKeypad(){
            keypad.setup();
        }
        void process(){
            char keyPressed = keypad.ButtonPressed();
            switch (keyPressed){
                case '1':
                case '2':
                case '3':
                case '4':
                case '5':
                case '6':
                case '7':
                case '8':
                case '9':
                case '0':{
                    findWhereToWrite() += String(keyPressed);
                    printScreen();
                    break;
                }
                case '=':{
                    if (isEmpty(equation[0])){
                        equation[0] = "0";
                    }
                    if (isEmpty(equation[1])){
                        equation[1] = "0";
                    }
                    if (operation == nullptr){
                        String copy = equation[0];
                        clear();
                        equation[0] = copy;
                        printScreen();

                        break;
                    }
                    
                    String result = operation->returnResult(equation[0].toInt(),equation[1].toInt());
                    clear();
                    equation[0] = result;
                    printScreen();
                    break;
                }
                case '+':{
                    if (operation == nullptr){
                        operation = new Addition();
                        equation[2] = '+';
                        printScreen();
                    }
                    break;
                }
                case '-':{
                    if (isEmpty(equation[0])){
                        equation[0] += '-';
                        printScreen();
                        break;
                    }
                    if (operation == nullptr){
                        operation = new Subtraction();
                        equation[2] = '-';
                        printScreen();
                        break;
                    }
                    if (isEmpty(equation[1])){
                        equation[1] += '-';
                        printScreen();
                        break;
                    }
                    break;
                }
                case '*':{
                    if (operation == nullptr){
                        operation = new Multiplication();
                        equation[2] = '*';
                        printScreen();
                    }
                    break;
                }
                case '\b':{


                    break;
                }
            }    
        }


    private:
        void clear(){
            if (operation != nullptr){
                delete operation;
            }
            equation[0] = String();
            equation[1] = String();
            equation[2] = String();
        }
        String& findWhereToWrite(){
            if (operation == nullptr){
                return equation[0];
            }
            else{
                return equation[1] ;
            }
        }
        void printScreen() { 
            Screen.printToLcd(equation[0],equation[1],equation[2]);
        }
};