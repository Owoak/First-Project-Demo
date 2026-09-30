#pragma once
#include "Arduino.h"

bool isEmpty(const String & string){
    if (string == "0" or string == "_"){
        return true;
    }
    return false;
}

class nPair{
    public:
        String first;
        bool second;
        nPair():first(String(0)),second(false){}
        nPair(const String& f, bool s ):first(f),second(s){}

        nPair& operator+=(const String& stringToAdd){
            first += stringToAdd;
            return *this;
        }
        nPair& operator=(char stringToAdd){
            first = stringToAdd;
            return *this;
        }
        nPair& operator+=(char stringToAdd){
            first += stringToAdd;
            return *this;
        }

};