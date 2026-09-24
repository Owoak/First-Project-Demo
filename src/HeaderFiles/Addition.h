#pragma once
#include "ActionBaseClass.h"

class Addition final : public BaseAction{
    public:
    nPair returnResult(const nPair & FirstNumber,const nPair & SecondNumber)override{
        nPair resulted;
        double result = (FirstNumber.first).toDouble() + (SecondNumber.first).toDouble();
        FormatDoubleResult(result,resulted);

        return resulted;
    }

    
};