#ifndef DOUBLERAND_H
#define DOUBLERAND_H
#include "base_factory.hpp"
#include "Rand.hpp"
#include <sstream>


class DoubleRand : public Rand
{
    protected:
        double num;
    public:
        DoubleRand() { num = rand() % 100; };
        double evaluate() {};
        string stringify() {
            return to_string(num);
        };      
};

#endif
