#ifndef BASE_HPP
#define BASE_HPP
#include <string>
class Base {
    public:
	Base* left;
	Base* right;
        /* Constructors */
        Base() {
	    left = 0;
	    right = 0;
        };

        /* Pure Virtual Functions */
        virtual double evaluate() = 0;
        virtual std::string stringify() = 0;
};

#endif
