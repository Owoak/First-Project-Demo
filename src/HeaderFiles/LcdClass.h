#pragma once

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#include <Arduino.h>

class LcdScreen final{
    private:
    enum DisplayCoordinates : short int{
        FirstRow = 0,
        SecondRow = 1,
        EndCollumns = 15,
        StartCollumn = 0 
    };

    LiquidCrystal_I2C lcd;

    long  int * FirstNumber;
    long  int * SecondNumber;
    char *  Action;

    public:
    LcdScreen ():lcd(0x27, 16, 2),FirstNumber(nullptr),SecondNumber(nullptr),Action(nullptr){

    }
    ~LcdScreen(){
        if (FirstNumber != nullptr){
            delete FirstNumber;
        }
        if (SecondNumber != nullptr){
            delete FirstNumber;
        }
        if (Action != nullptr){
            delete FirstNumber;
        }
    }

    LcdScreen(const LcdScreen& other) = delete;
    LcdScreen& operator=(const LcdScreen& other) = delete;

    long int *& getFirstNumber(){return FirstNumber;}
    long int *& getSecondNumber(){return SecondNumber;}
    char*& getAction(){return Action;}
    
    void setupLcd(){
        lcd.init();
        lcd.backlight();
        // lcd.setCursor(DisplayCoordinates::FirstRow,DisplayCoordinates::StartCollumn);
        // lcd.print("Start typing...");
    }
    void printToLcd(){// have to finish ******
        String FirstString = String(*FirstNumber);
        if (FirstString.length() >= 16 ){
            lcd.setCursor(DisplayCoordinates::StartCollumn,DisplayCoordinates::FirstRow);
            lcd.print(FirstString);
            
        }else{
            short int StartAt = DisplayCoordinates::EndCollumns - FirstString.length() + 1;
            lcd.setCursor(StartAt ,DisplayCoordinates::FirstRow);
            lcd.print(FirstString);

        }

        if (Action != nullptr){
            lcd.setCursor(DisplayCoordinates::StartCollumn,DisplayCoordinates::SecondRow);
            lcd.print(*Action);
            
        }else{
            return;
        }

        if (SecondNumber!= nullptr){
            String SecondString = String(*SecondNumber);
            if (SecondString.length() >= 16 - 2 ){
                lcd.setCursor(DisplayCoordinates::StartCollumn + 2,DisplayCoordinates::SecondRow);
                lcd.print(SecondString);
            }
            else{
                short int StartAt = DisplayCoordinates::EndCollumns + 1 - SecondString.length();
                lcd.setCursor(StartAt ,DisplayCoordinates::SecondRow);
                lcd.print(SecondString);
            }
        }
    }

};