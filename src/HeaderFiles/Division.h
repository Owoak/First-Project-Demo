#include "ActionBaseClass.h"

class Division final : public BaseAction{
    public:
        Division():BaseAction(){}
        nPair returnResult(const nPair & FirstNumber,const nPair & SecondNumber)override{
            nPair resulted;
            double result = (FirstNumber.first).toDouble() / (SecondNumber.first).toDouble();
            FormatDoubleResult(result,resulted);

            return resulted;
        }

};