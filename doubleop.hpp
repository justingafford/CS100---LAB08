#ifndef DOUBLEOP_H
#define DOUBLEOP_H
#include "base_factory.hpp"
#include "Op.hpp"
#include <sstream>


class DoubleOp : public Op
{
    protected:
        double num;
    public:
        DoubleOp() { num = 0; };
        DoubleOp(double n) { num = n; };
        double evaluate() {};
        string stringify() {
            return to_string(num);
        };      
};

#endif
