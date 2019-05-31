#ifndef __BASE_FACTORY_HPP__
#define __BASE_FACTORY_HPP__
#include "Rand.hpp"
#include "Op.hpp"
#include "doubleop.hpp"
#include "doublerand.hpp"
class BaseFactory {
    public:
        /* Constructor */
        BaseFactory() {}

        /* Pure Virtual Production Function */
        Op* createOp(double value)  { 
            DoubleOp* temp = new DoubleOp(value); 
            return temp;
        }
        Rand* createRand() {
            return new DoubleRand();
        }
};

#endif //__BASE_FACTORY_HPP__
