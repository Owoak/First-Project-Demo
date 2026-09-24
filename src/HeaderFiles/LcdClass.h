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
    LcdScreen ():lcd(0x27, 16, 2){}
    ~LcdScreen(){}
    LcdScreen(const LcdScreen& other) = delete;
    LcdScreen& operator=(const LcdScreen& other) = delete;

    void setup(){
        lcd.init();
        lcd.backlight();
        // lcd.setCursor(DisplayCoordinates::FirstRow,DisplayCoordinates::StartCollumn);
        // lcd.print("Start typing...");
    }
    void printToLcd(const String & FirstNumber,const String & SecondNumber,const String & Action){
        lcd.clear();

        if (!isEmpty(FirstNumber)){
            if (FirstNumber.length() >= 16 ){
                lcd.setCursor(DisplayCoordinates::StartCollumn,DisplayCoordinates::FirstRow);
                lcd.print(FirstNumber);
                
            }else{
                short int StartAt = DisplayCoordinates::EndCollumns - FirstNumber.length() + 1;
                lcd.setCursor(StartAt ,DisplayCoordinates::FirstRow);
                lcd.print(FirstNumber);

            }
        }
        else{
            lcd.setCursor(DisplayCoordinates::EndCollumns,DisplayCoordinates::FirstRow);
            lcd.print(0);
            return;
        }

        if (!isEmpty(Action)){
            lcd.setCursor(DisplayCoordinates::StartCollumn,DisplayCoordinates::SecondRow);
            lcd.print(Action);
            
            
        }else{
            lcd.setCursor(DisplayCoordinates::StartCollumn,DisplayCoordinates::SecondRow);
            lcd.print('_');
            return;
        }

        if (!isEmpty(SecondNumber)){
            if (SecondNumber.length() >= 16 - 2 ){
                lcd.setCursor(DisplayCoordinates::StartCollumn + 2,DisplayCoordinates::SecondRow);
                lcd.print(SecondNumber);
            }
            else{
                short int StartAt = DisplayCoordinates::EndCollumns + 1 - SecondNumber.length();
                lcd.setCursor(StartAt ,DisplayCoordinates::SecondRow);
                lcd.print(SecondNumber);
            }
        }
        else{
            lcd.setCursor(DisplayCoordinates::EndCollumns,DisplayCoordinates::SecondRow);
            lcd.print(0);
            return;
        }
    }

};