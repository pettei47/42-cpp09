#include "RPN.hpp"

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cout << "Error: invalid arguments" << std::endl;
		return 1;
	}
	RPN rpn(argv[1]);
	if (!rpn.get_valid()) {
		std::cout << "Error: invalid arguments" << std::endl;
		return 1;
	}
	rpn.calcRPN();
	if (!rpn.get_valid())
		return 1;
	std::cout << rpn.get_st() << std::endl;
}
