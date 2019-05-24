#ifndef SCIOP_H
#define SCIOP_H
#include "base_factory.hpp"
#include "Op.hpp"
#include <sstream>


class SciOp : public Op
{
    protected:
        double num;
    public:
        SciOp() { num = 0; };
        SciOp(double n) { num = n; };
        double evaluate() {};
        string stringify() {
            ostringstream obj;
            obj << std::scientific;
            obj << num;
            string i = obj.str();
            return i;
        };      
};

#endif
