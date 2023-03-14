#include "RPN.hpp"

RPN::RPN(int first) {
  _st.push_back(first);
}

RPN::~RPN() {}

void  RPN::setNum(int i) {
  _st.push_back(i);
}

void  RPN::calc(std::string o) {
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

int RPN::get_st() {
  return _st.back();
}
