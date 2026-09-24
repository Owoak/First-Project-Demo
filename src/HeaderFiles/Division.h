#include "ActionBaseClass.h"

class Division final : public BaseAction{
    public:
        Division():BaseAction(){}
        nPair returnResult(const nPair & FirstNumber,const nPair & SecondNumber)override{//needs precision tweaks
        if (!FirstNumber.second and !SecondNumber.second){
            if ((FirstNumber.first).toInt() % (SecondNumber.first).toInt() == 0){
                int result = (FirstNumber.first).toInt() / (SecondNumber.first).toInt();
                return nPair(String(result),false);
            }else{
                double result = (FirstNumber.first).toDouble() / (SecondNumber.first).toDouble();
                return nPair(String(result),true);
            }
        }
        else{
            double result = (FirstNumber.first).toDouble() / (SecondNumber.first).toDouble();
            return nPair(String(result),true);
        }
    }

    


};