#ifndef SCIRAND_H
#define SCIRAND_H
#include "base_factory.hpp"
#include "Rand.hpp"
#include <sstream>


class SciRand : public Rand
{
    protected:
        double num;
    public:
        SciRand() { num = rand() % 100; };
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
