#include "PmergeMe.hpp"

int main(int argc, char **argv) {
  if (argc < 2) {
    std::cout << "Error" << std::endl;
    return 1;
  }
  PmergeMe  pm(argc - 1, &argv[1]);
  if (!pm.get_valid()) {
    std::cout << "Error" << std::endl;
    return 1;
  }
  pm.exec();
}
