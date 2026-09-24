#pragma once
#include "ActionBaseClass.h"

class Subtraction final : public BaseAction{
    public:
    nPair returnResult(const nPair & FirstNumber,const nPair & SecondNumber)override{
        if (!FirstNumber.second and !SecondNumber.second){
            int result = (FirstNumber.first).toInt() - (SecondNumber.first).toInt();
            return nPair(String(result),false);
        }else{
            double result = (FirstNumber.first).toDouble() - (SecondNumber.first).toDouble();
            return nPair(String(result),true);
        }
    }  
};