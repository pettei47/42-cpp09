#include "RPN.hpp"

int main(int argc, char **argv)
{
  if (argc != 2)
  {
    std::cerr << "Error" << std::endl;
    return 1;
  }
  RPN rpn(argv[1]);
  if (!rpn.get_valid())
  {
    std::cerr << "Error" << std::endl;
    return 1;
  }
  rpn.calcRPN();
  std::cout << rpn.get_st() << std::endl;
}
