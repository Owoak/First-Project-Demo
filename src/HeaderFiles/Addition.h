#pragma once
#include "ActionBaseClass.h"

class Addition final : public BaseAction{
    public:
    String returnResult(long int FirstNumber,long int SecondNumber)override{
        long int result = FirstNumber + SecondNumber;

        return String(result);
    }

    
};