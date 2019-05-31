#ifndef __COMMAND_HPP__
#define __COMMAND_HPP__
#include "base.hpp"
#include "base_factory.hpp"
#include "scifactory.hpp"
#include "doublefactory.hpp"
#include "precisionfactory.hpp"
#include "scirand.hpp"
#include "precisionrand.hpp"
#include "doublerand.hpp"
#include "sciop.hpp"
#include "precisionop.hpp"
#include "doubleop.hpp"
#include "Op.hpp"
#include "Rand.hpp"
#include "Add.hpp"
#include "Sub.hpp"
#include "Mult.hpp"
#include "Div.hpp"
#include "Pow.hpp"

class Command {
    protected:
        Base* root;
    
    public:
        Command() { this->root = nullptr; }
        double execute() { return root->evaluate(); }
        std::string stringify() { return root->stringify(); }
        Base* get_root() { return root; }
};

class InitialCommand : public Command {
	public:
		InitialCommand(Base* bass){ root = bass; };
		double execute() {  return root->evaluate(); }
        	std::string stringify() { return root->stringify(); }
		Base* get_root() { return root; }
};

class AddCommand : public Command {
	public:
		AddCommand(Command* c, Base* bass){ root = new Add(c->get_root(), bass);};
		double execute() {  return root->evaluate(); }
        	std::string stringify() { return root->stringify(); }
		Base* get_root() { return root; }
};

class SubCommand : public Command {
	public:
		SubCommand(Command* c, Base* bass){root = new Sub(c->get_root(), bass);};
		double execute() {  return root->evaluate(); }
      	  	std::string stringify() { return root->stringify(); }
		Base* get_root() { return root; }
};

class MultCommand : public Command {
	public:
		MultCommand(Command* c, Base* bass){root = new Mult(c->get_root(), bass);};
		double execute() {  return root->evaluate(); }
        	std::string stringify() { return root->stringify(); }
		Base* get_root() { return root; }
};

class DivCommand : public Command {
	public:
		DivCommand(Command* c, Base* bass){root = new Div(c->get_root(), bass);};
		double execute() {  return root->evaluate(); }
        	std::string stringify() { return root->stringify(); }
		Base* get_root() { return root; }
};

class PowCommand : public Command {
	public:
		PowCommand(Command* c, Base* bass){root = new Pow(c->get_root(), bass);};
		double execute() {  return root->evaluate(); }
        	std::string stringify() { return root->stringify(); }
		Base* get_root() { return root; }
};
#endif
