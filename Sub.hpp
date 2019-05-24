#ifndef SUB_HPP
#define SUB_HPP
#include "base.hpp"
#include <string>
using namespace std;
class Sub: public Base
{
  private:
	Base* L1;
	Base* L2;
  public:
	Sub(Base*, Base*);
	double evaluate();
	string stringify();
};
#endif
