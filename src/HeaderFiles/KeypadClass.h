#pragma once

class Keypad final{
    private:
        short int rowsPins[4] = {2,3,4,5};
        short int collumnPins[4] = {6,7,8,9};

        char kaypad[4][4] = {
            {'1','2','3','0'},
            {'6','5','4','='},
            {'9','8','7','+'},
            {'\b','/','*','-'}
        };

    public:
    
    Keypad() {};
    ~Keypad(){}
    Keypad(const Keypad& other) = delete;
    Keypad& operator = (const Keypad& other) = delete;

    void setup(){
        pinMode(2, OUTPUT);      // for each row
        pinMode(3, OUTPUT);
        pinMode(4, OUTPUT);
        pinMode(5, OUTPUT);
        pinMode(6, INPUT_PULLUP);   //for each column
        pinMode(7, INPUT_PULLUP);
        pinMode(8, INPUT_PULLUP); 
        pinMode(9, INPUT_PULLUP);
        
        for (short int i = 0;i < 4 ;i++){       //default state;
            digitalWrite(rowsPins[i],HIGH);
        }
    }

    char ButtonPressed(){ // may need DelayPadding
        
        for (short int row = 0;row < 4;row++){
            digitalWrite(rowsPins[row],LOW);
            for (short int collumn = 0;collumn < 4;collumn++){
                if (digitalRead(collumnPins[collumn]) == LOW){
                    digitalWrite(rowsPins[row],HIGH);
                    return kaypad[row][collumn];
                }
            }
            
            digitalWrite(rowsPins[row],HIGH);
        }
    
        return '\0';
    }
};