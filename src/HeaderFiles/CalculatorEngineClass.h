#pragma once

#include "LcdClass.h"
#include "KeypadClass.h"
#include "Addition.h"
#include "Subtraction.h"
#include "Multiplication.h"
#include "Division.h"




class Engine final{
    private:
        LcdScreen Screen;
        Keypad keypad;

        nPair equation[3] ;
        BaseAction * operation;

    public:
        Engine():Screen(),keypad(),equation({nPair(),nPair(),nPair(String('_'),false)}),operation(nullptr){}
        ~Engine(){clear();}
        Engine(const Engine& other) = delete;
        Engine& operator=(const Engine& other) = delete;
        
        void setupLcd(){
            Screen.setup();
            printScreen();
        }
        void setupKeypad(){
            keypad.setup();
        }

        void process(){
            bool NeedsReRendering = false;

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
                    Serial.println("digit button pressed");
                    Serial.println(equation[0].first);
                    Serial.println(equation[1].first);
                    Serial.println(equation[2].first);

                    nPair& currentNumber = findWhereToWrite();
                    if (isEmpty(currentNumber.first)){
                        currentNumber = keyPressed ;
                    }else{
                        currentNumber += String(keyPressed);
                    }
                    
                    NeedsReRendering = true;
                    break;
                }
                case '=':{
                    if (operation == nullptr){ 
                        // do nothing
                        break;
                    }
                    
                    nPair result = operation->returnResult(equation[0],equation[1]); // overflow bug has to ber fixed
                    clear();
                    equation[0] = result;
                    NeedsReRendering = true;
                    
                    break;
                }
                case '+':{
                    if (operation == nullptr){
                        operation = new Addition();
                        equation[2].first = '+';
                        NeedsReRendering = true;
                    }
                    break;
                }
                case '-':{
                    if (isEmpty(equation[0].first)){
                        equation[0].first = '-'; // needs fix (what if only - is entered)
                        NeedsReRendering = true;
                        break;
                    }
                    else if (operation == nullptr){
                        operation = new Subtraction();
                        equation[2].first = '-';
                        NeedsReRendering = true;
                        break;
                    }
                    else if (isEmpty(equation[1].first)){
                        equation[1].first = '-';
                        NeedsReRendering = true;
                        break;
                    }
                    break;
                }
                case '*':{
                    if (operation == nullptr){
                        operation = new Multiplication();
                        equation[2].first = '*';
                        NeedsReRendering = true;
                    }
                    break;
                }
                case '/':{
                    if (operation == nullptr){
                        operation = new Division();
                        equation[2] = '/';
                        NeedsReRendering = true;
                    }
                    break;
                }
                case '.':{
                    nPair& currentNumber = findWhereToWrite();
                    if (currentNumber.second == false){
                        currentNumber.first += String('.');
                        currentNumber.second = true;
                        NeedsReRendering = true;
                    }
                    
                    break;
                }
                
                // case '\b':{  //needs update
                //     String & currentNumber = findWhereToWrite();
                //     if (!isEmpty(currentNumber)){
                //         currentNumber.remove(currentNumber.length() - 1);
                //         NeedsReRendering = true;
                //     }
                //     break;
                // }
                
                case 'c':{
                    clear();
                    printScreen();
                    delay(700);
                    break;
                }
            }  
            
            if (NeedsReRendering){
                printScreen();  
            }
        }


    private:
        void clear(){
            if (operation != nullptr){
                delete operation;
                operation = nullptr;
            }
            equation[0] = nPair();
            equation[1] = nPair();
            equation[2] = nPair(String('_'),false);
        }
        nPair& findWhereToWrite(){
            if (operation == nullptr){
                return equation[0];
            }
            else{
                return equation[1] ;
            }
        }
        void printScreen() { 
            Screen.printToLcd(equation[0].first,equation[1].first,equation[2].first);
        }
};