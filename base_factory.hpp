#ifndef __BASE_FACTORY_HPP__
#define __BASE_FACTORY_HPP__
#include "Rand.hpp"
#include "Op.hpp"

class BaseFactory {
    public:
        /* Constructor */
        BaseFactory() {}

        /* Pure Virtual Production Function */
        virtual Op* createOp(double value) = 0;
        virtual Rand* createRand() = 0;
};

#endif //__BASE_FACTORY_HPP__
