#include "Op.hpp"
#include <string>
using namespace std;

	Op::Op () {
		num = 0;
	}
        Op::Op(double  n) {
		num = n;
	}
        double Op::evaluate() {
		return num;
	}
        string Op::stringify() {
		return to_string(num);
	}

