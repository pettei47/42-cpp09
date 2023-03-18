#include "RPN.hpp"

std::string	RPN::ops = "+-*/";

RPN::RPN(char *arg) {
	_valid = _validateArgs(arg);
	if (_valid) {
		_arg = arg;
		_index = 0;
	}
}

RPN::~RPN() {}

bool RPN::_validateArgs(char *arg) {
	int numCount = 0;
	for (int i = 0; arg[i]; i++) {
		if (arg[i] == ' ')
			continue;
		if(!std::isdigit(arg[i]) && ops.find(arg[i]) == std::string::npos)
			return false;
		if (std::isdigit(arg[i]))
			numCount++;
	}
	if (numCount == 0)
		return false;
	return true;
}

int RPN::_getNumFromArg() {
	return _arg[_index] - '0';
}

std::string RPN::_getOperatorFromArg() {
	std::string o(1, _arg[_index]);
	return o;
}

void	RPN::_setNum() {
	_st.push_back(_getNumFromArg());
}

bool	RPN::_calc() {
	std::string o = _getOperatorFromArg();
	long r = _st.back();
	_st.pop_back();
	if (_st.size() == 0) {
		std::cout << "Error: cannot calculate (not RPN)" << std::endl;
		return false;
	}
	long l = _st.back();
	if (l < INT_MIN || INT_MAX < l) {
		std::cout << "Error: cannot calculate (over INT_MAX/MIN)" << std::endl;
		return false;
	}
	_st.pop_back();
	switch (ops.find(o)) {
		case 0:
			_st.push_back(l + r);
			break;
		case 1:
			_st.push_back(l - r);
			break;
		case 2:
			_st.push_back(l * r);
			break;
		case 3:
			if(r != 0) {
				_st.push_back(l / r);
				break;
			}
		default:
			std::cout << "Error: cannot calculate (Zero devided)" << std::endl;
			return false;
	}
	return true;
}

void	RPN::calcRPN() {
	for (; _arg[_index]; _index++) {
		if (_arg[_index] == ' ')
			continue;
		else if (std::isdigit(_arg[_index]))
			_setNum();
		else if (ops.find(_arg[_index]) != std::string::npos) {
			if (!(_valid = _calc()))
				return ;
		}
	}
	if (_st.size() != 1) {
		std::cout << "Error: cannot calculate (not RPN)" << std::endl;
		_valid = false;
	}
}

long	RPN::get_st() {
	return _st.back();
}

bool	RPN::get_valid() {
	return _valid;
}
