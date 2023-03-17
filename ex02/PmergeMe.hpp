#ifndef PMERGEME_HPP
# define PMERGEME_HPP
# include <iostream>
#include <sstream>
# include <vector>
# include <deque>
# include <set>

class PmergeMe
{
private:
	std::vector<long> 	_before;
	std::deque<long>		_beforeDeque;
	std::multiset<long> _after;
	int									_countElem;
	double							_vecTime;
	double							_dequeTime;
	bool								_valid;
	PmergeMe(PmergeMe const &);
	PmergeMe		&operator=(PmergeMe const &);

	bool	_validArgs(char **arg);
	void	_putBefore();
	void	_putAfter();
	void	_putSortTime(std::string containerName);

	template<typename T>
	void	_insertionSort(T& container, int p, int q) {
		for (int i = p; i < q; i++) {
			int tempVal = container[i + 1];
			int j = i + 1;
			while (j > p && container[j - 1] > tempVal) {
					container[j] = container[j - 1];
					j--;
			}
			container[j] = tempVal;
		}
	}

	template<typename T>
	T	_copyOfRange(T& container, int start, int end) {
		T	ret;
		for (int i = start; i < end; i++) {
			ret.push_back(container[i]);
		}
		return ret;
	}

	template<typename T>
	void _merge(T& container, int p, int q, int r) {
		int n1 = q - p + 1;
		int n2 = r - q;
		T LA = _copyOfRange(container, p, q + 1);
		T RA = _copyOfRange(container, q + 1, r + 1);
		int RIDX = 0;
		int LIDX = 0;
		for (int i = p; i < r - p + 1; i++) {
				if (RIDX == n2) {
						container[i] = LA[LIDX];
						LIDX++;
				} else if (LIDX == n1) {
						container[i] = RA[RIDX];
						RIDX++;
				} else if (RA[RIDX] > LA[LIDX]) {
						container[i] = LA[LIDX];
						LIDX++;
				} else {
						container[i] = RA[RIDX];
						RIDX++;
				}
		}
	}

	template<typename T>
	void	_mergeInsertionSort(T& container, int p, int r) {
		if (r - p > 5) {
				int q = (p + r) / 2;
				_mergeInsertionSort(container, p, q);
				_mergeInsertionSort(container, q + 1, r);
				_merge(container, p, q, r);
		} else {
				_insertionSort(container, p, r);
		}
	}

public:
	PmergeMe(int count, char **arg);
	~PmergeMe();

	void	exec();
	bool	get_valid();

};

#endif
