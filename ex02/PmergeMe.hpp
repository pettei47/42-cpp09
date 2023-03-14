#ifndef PMERGEME_HPP
# define PMERGEME_HPP
# include <iostream>
# include <vector>
# include <list>
# include <set>

class PmergeMe
{
private:
  std::vector<long> _before;
	std::list<long>		_beforeList;
  std::set<long> 		_after;
	int								_countElem;
	double						_vecTime;
	double						_listTime;
	bool							_valid;
	PmergeMe(PmergeMe const &);
	PmergeMe		&operator=(PmergeMe const &);

	bool	_validArgs(char **arg);
	void	_putBefore();
	void	_putAfter();
	void	_sortAsVector();
	void	_sortAsList();

public:
	PmergeMe(int count, char **arg);
	~PmergeMe();

	void	exec();
	bool	get_valid();

};

#endif
