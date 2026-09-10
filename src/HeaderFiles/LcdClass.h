#pragma once

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

class LcdScreen final{
private:
    enum DisplayCoordinates : short int{
        FirstRow = 0,
        SecondRow = 1,
        EndCollumns = 15,
        StartCollumn = 0 
    };
    LiquidCrystal_I2C lcd;

public:
    LcdScreen ():lcd(0x27, 16, 2){
    }
    LcdScreen(const LcdScreen& other) = delete;
    LcdScreen& operator=(const LcdScreen& other) = delete;

    void setupLcd(){
        lcd.init();
        lcd.backlight();
        // lcd.setCursor(DisplayCoordinates::FirstRow,DisplayCoordinates::StartCollumn);
        // lcd.print("Start typing...");
    }
    void printToLcd(const long int * FirstNumber,const long int * SecondNumber,const char* Action){
        if (FirstNumber != nullptr){
            String FirstString = String(*FirstNumber);
            if (FirstString.length() >= 16 ){
                lcd.setCursor(DisplayCoordinates::StartCollumn,DisplayCoordinates::FirstRow);
                lcd.print(FirstString);
                
            }else{
                short int StartAt = DisplayCoordinates::EndCollumns - FirstString.length() + 1;
                lcd.setCursor(StartAt ,DisplayCoordinates::FirstRow);
                lcd.print(FirstString);

            }
        }
        else{
            return;
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