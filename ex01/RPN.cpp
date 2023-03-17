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
  int   counter = 0;
  bool  first = true;
  for (int i = 0; arg[i]; i++) {
    if (arg[i] == ' ')
      continue;
    else if (first && std::isdigit(arg[i]))
      first = false;
    else if (counter == 0 && std::isdigit(arg[i]))
      counter++;
    else if (counter == 1 && ops.find(arg[i]) != std::string::npos)
      counter = 0;
    else 
      return false;
  }
  if (counter != 0)
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

void  RPN::_setNum() {
  _st.push_back(_getNumFromArg());
}

bool  RPN::_calc() {
  std::string o = _getOperatorFromArg();
  int r = _st.back();
  _st.pop_back();
  int l = _st.back();
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
      return false;
  }
  return true;
}

void	RPN::calcRPN() {
  int   counter = 0;
  bool  first = true;
  for (; _arg[_index]; _index++) {
    if (_arg[_index] == ' ')
      continue;
    else if (first && std::isdigit(_arg[_index])) {
      _setNum();
      first = false;
    }
    else if (counter == 0 && std::isdigit(_arg[_index])) {
      _setNum();
      counter++;
    }
    else if (counter == 1 && ops.find(_arg[_index]) != std::string::npos) {
      if (!_calc()) {
        _valid = false;
        return ;
      }
      counter = 0;
    }
  }
}

int RPN::get_st() {
  return _st.back();
}

bool  RPN::get_valid() {
  return _valid;
}
