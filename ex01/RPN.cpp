#include "RPN.hpp"

RPN::RPN(int first) {
  _st.push(first);
}

RPN::~RPN() {}

void  RPN::setNum(int i) {
  _st.push(i);
}

void  RPN::calc(std::string o) {
  int l = _st.top();
  _st.pop();
  int r = _st.top();
  _st.pop();
  std::string ops = "+-*/";
  switch (ops.find(o)) {
    case 0:
      _st.push(r + l);
      break;
    case 1:
      _st.push(r - l);
      break;
    case 2:
      _st.push(r * l);
      break;
    case 3:
      _st.push(r / l);
      break;
    default:
      std::cerr << "Error calc"<< o << std::endl;
  }
}

int RPN::get_st() {
  return _st.top();
}
