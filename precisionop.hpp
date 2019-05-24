#ifndef PRECISIONOP_H
#define PRECISIONOP_H
#include "base_factory.hpp"
#include "Op.hpp"
#include <sstream>
#include <iomanip>


class PrecisionOp : public Op
{
    protected:
        double num;
    public:
        PrecisionOp() { num = 0; };
        PrecisionOp(double n) { num = n; };
        double evaluate() {};
        string stringify() {
            ostringstream obj;
            obj << std::fixed << std::setprecision(9);
            obj << num;
            string i = obj.str();
            return i;
        };      
};

#endif
