#pragma once
#include <Arduino.h>

class BaseAction {
    public:
    virtual ~BaseAction() = default;
    public:
    virtual String returnResult(long int FirstNumber,long int SecondNumber) = 0;
};