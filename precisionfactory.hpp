#ifndef PRECISIONFACTORY_H
#define PRECISIONFACTORY_H
#include "base_factory.hpp"
#include "precisionop.hpp"
#include "precisionrand.hpp"

class PrecisionFactory : public BaseFactory
{
 public:
     PrecisionFactory(){};
     Op* createOp(double value){
         PrecisionOp* temp = new PrecisionOp(value); 
         return temp;
     };
     Rand* createRand(){return new PrecisionRand();};

};
#endif
