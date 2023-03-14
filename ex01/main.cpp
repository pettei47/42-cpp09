#include "RPN.hpp"

bool validateArgs(int argc, char **argv) {
  if (argc != 2)
    return false;
  int i = 0;
  std::string ops("+-*/");
  while (argv[1][i])
  {
    if (i % 2 == 1 && argv[1][i] != ' ')
      return false;
    if ((i == 0 || i % 4 == 2) && !::isdigit(argv[1][i]))
      return false;
    if (i > 0 && i % 4 == 0 && ops.find(argv[1][i]) == std::string::npos)
      return false;
    i++;
  }
  if ((i - 1) % 4 != 0)
    return false;
  return true;
}

int getNumFromArg(char *arg, int i) {
  return arg[i] - '0';
}

std::string getOperatorFromArg(char *arg, int i) {
  std::string o(1, arg[i]);
  return o;
}

int main(int argc, char **argv)
{
  if (!validateArgs(argc, argv))
  {
    std::cerr << "Error" << std::endl;
    return 1;
  }
  RPN rpn(getNumFromArg(argv[1], 0));
  int i = 2;
  while (argv[1][i]) {
    if (i % 4 == 2)
      rpn.setNum(getNumFromArg(argv[1], i));
    else if (i % 4 == 0)
      rpn.calc(getOperatorFromArg(argv[1], i));
    i++;
  }
  std::cout << rpn.get_st() << std::endl;
}
