#pragma once
#include <Arduino.h>
#include "Defines.h"
class BaseAction {
    public:
    virtual ~BaseAction() = default;
    public:
    virtual nPair returnResult(const nPair & FirstNumber,const nPair & SecondNumber) = 0;
};

// bool isDecimal(const nPair & number){
//     for (auto it = number.first.begin();it != number.first.end();it++){
//         if (*it == '.'){
//             for (auto secondIt = it;secondIt != number.first.end();secondIt++ ){
//                 if (*secondIt != 0){
//                     return true;
//                 }
//             }
//             return false;
//         }
//     }
//     return false;
// }

// bool formatNumber(const nPair & number){

// }