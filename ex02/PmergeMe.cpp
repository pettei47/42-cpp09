#include "PmergeMe.hpp"

PmergeMe::PmergeMe(int count, char **arg) {
  _valid = _validArgs(arg);
  _countElem = count;
}

PmergeMe::~PmergeMe() {}

bool  PmergeMe::_validArgs(char **arg) {
  int i = 0;
  while (arg[i]) {
    int j = 0;
    while (arg[i][j]) {
      if (!std::isdigit(arg[i][j]))
        return false;
      j++;
    }
    long num = std::strtol(arg[i],NULL, 10);
    if (num < 1)
      return false;
    _before.push_back(num);
    _beforeList.push_back(num);
    _after.insert(num);
    i++;
  }
  return true;
}

void  PmergeMe::_putBefore() {
  std::cout << "Before: ";
  for (int i = 0; i < _countElem; i++)
    std::cout << " " << _before[i];
  std::cout << std::endl;
}

void  PmergeMe::_putAfter() {
  std::cout << "After:  ";
  std::set<long>::iterator itr = _after.begin();
  for (; itr != _after.end(); itr++)
    std::cout << " " << *itr;
  std::cout << std::endl;
}

void  PmergeMe::_sortAsVector() {
  timespec start;
  timespec end;
  ::clock_gettime(CLOCK_MONOTONIC_RAW, &start);
  std::sort(_before.begin(), _before.end());
  ::clock_gettime(CLOCK_MONOTONIC_RAW, &end);
  double runSec = end.tv_sec - start.tv_sec;
  double runNSec = end.tv_nsec - start.tv_nsec;
  _vecTime = (runSec * 1000000L) + (runNSec / 1000);
  std::cout << "Time to process a range of "
            << _countElem
            << " elements with std::vector : "
            << _vecTime << " us"
            << std::endl;
}

void  PmergeMe::_sortAsList() {
  timespec start;
  timespec end;
  ::clock_gettime(CLOCK_MONOTONIC_RAW, &start);
  _beforeList.sort();
  ::clock_gettime(CLOCK_MONOTONIC_RAW, &end);
  double runSec = end.tv_sec - start.tv_sec;
  double runNSec = (end.tv_nsec - start.tv_nsec);
  _listTime = (runSec * 1000000L) + (runNSec / 1000);
  std::cout << "Time to process a range of "
          << _countElem
          << " elements with std::list : "
          << _listTime << " us"
          << std::endl;
}

void  PmergeMe::exec() {
  _putBefore();
  _putAfter();
  _sortAsVector();
  _sortAsList();
}

bool  PmergeMe::get_valid() {
  return _valid;
}
