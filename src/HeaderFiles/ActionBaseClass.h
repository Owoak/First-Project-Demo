#pragma once
#include <Arduino.h>
#include "Defines.h"
class BaseAction {
    public:
    virtual ~BaseAction() = default;
    public:
    virtual nPair returnResult(const nPair & FirstNumber,const nPair & SecondNumber) = 0;
};


void FormatDoubleResult(double& result,nPair& resulted){
    String s = String(result, 6);

    while (s.endsWith("0")){
        s.remove(s.length() - 1);
    }

    if (s.endsWith(".")) {
        s.remove(s.length() - 1);
        resulted = nPair(s,false);
    }else{
        resulted = nPair(s,true);
    }

    
}