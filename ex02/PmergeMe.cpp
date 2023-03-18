#include "PmergeMe.hpp"

PmergeMe::PmergeMe(int count, char **arg) {
	_valid = _validArgs(arg);
	_countElem = count;
}

PmergeMe::~PmergeMe() {}

bool	PmergeMe::_validArgs(char **arg) {
	for (int i = 0; arg[i]; i++) {
		int j = 0;
		for (; arg[i][j]; j++) {
			if (!std::isdigit(arg[i][j]))
				return false;
		}
		if (j == 0)
			return false;
		long num;
		std::istringstream(arg[i]) >> num;
		if (num < 1)
			return false;
		_before.push_back(num);
		_beforeDeque.push_back(num);
		_after.insert(num);
	}
	return true;
}

void	PmergeMe::_putBefore() {
	std::cout << "Before: ";
	for (int i = 0; i < _countElem; i++)
		std::cout << " " << _before[i];
	std::cout << std::endl;
}

void	PmergeMe::_putAfter() {
	std::cout << "After:  ";
	std::set<long>::iterator itr = _after.begin();
	for (; itr != _after.end(); itr++)
		std::cout << " " << *itr;
	std::cout << std::endl;
}

void	PmergeMe::_putSortTime(std::string containerName) {
	timespec start;
	timespec end;
	::clock_gettime(CLOCK_MONOTONIC_RAW, &start);
	if (containerName == "vector")
		_mergeInsertionSort(_before, 0, _before.size() - 1);
	else
		_mergeInsertionSort(_beforeDeque, 0, _before.size() - 1);
	::clock_gettime(CLOCK_MONOTONIC_RAW, &end);
	double runSec = end.tv_sec - start.tv_sec;
	double runNSec = end.tv_nsec - start.tv_nsec;
	double sortTime = (runSec * 1000000L) + (runNSec / 1000);
	std::cout << "Time to process a range of "
						<< _countElem
						<< " elements with std::" << containerName << " : "
						<< sortTime << " us"
						<< std::endl;
}

void	PmergeMe::exec() {
	_putBefore();
	_putAfter();
	_putSortTime("vector");
	_putSortTime("deque");
	// _putBefore();
}

bool	PmergeMe::get_valid() {
	return _valid;
}
