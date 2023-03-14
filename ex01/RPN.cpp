#include "RPN.hpp"

RPN::RPN(char *arg) {
  _valid = _validateArgs(arg);
  if (_valid) {
    _arg = arg;
    _index = 0;
    _st.push_back(_getNumFromArg());
    _index = 2;
  }
}

RPN::~RPN() {}

bool RPN::_validateArgs(char *arg)
{
  int i = 0;
  std::string ops("+-*/");
  while (arg[i])
  {
    if (i % 2 == 1 && arg[i] != ' ')
      return false;
    if ((i == 0 || i % 4 == 2) && !::isdigit(arg[i]))
      return false;
    if (i > 0 && i % 4 == 0 && ops.find(arg[i]) == std::string::npos)
      return false;
    i++;
  }
  if ((i - 1) % 4 != 0)
    return false;
  return true;
}


int RPN::_getNumFromArg()
{
  return _arg[_index] - '0';
}

std::string RPN::_getOperatorFromArg()
{
  std::string o(1, _arg[_index]);
  return o;
}

void  RPN::_setNum() {
  _st.push_back(_getNumFromArg());
}

void  RPN::_calc() {
  std::string o = _getOperatorFromArg();
  int l = _st.back();
  _st.pop_back();
  int r = _st.back();
  _st.pop_back();
  std::string ops = "+-*/";
  switch (ops.find(o)) {
    case 0:
      _st.push_back(r + l);
      break;
    case 1:
      _st.push_back(r - l);
      break;
    case 2:
      _st.push_back(r * l);
      break;
    case 3:
      _st.push_back(r / l);
      break;
    default:
      std::cerr << "Error calc"<< o << std::endl;
  }
}

void	RPN::calcRPN() {
  while (_arg[_index]) {
    if (_index % 4 == 2)
      _setNum();
    else if (_index % 4 == 0)
      _calc();
    _index++;
  }
}

int RPN::get_st() {
  return _st.back();
}

bool  RPN::get_valid() {
  return _valid;
}
