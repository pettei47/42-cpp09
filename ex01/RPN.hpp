#ifndef RPN_HPP
# define RPN_HPP
# include <iostream>
# include <list>

class RPN
{
private:
	static std::string	ops;
	std::list<long>	_st;
	bool						_valid;
	char						*_arg;
	int							_index;
	RPN(RPN const &);
	RPN		&operator=(RPN const &);

	bool	_validateArgs(char *arg);
	int	_getNumFromArg();
	std::string _getOperatorFromArg();
	void	_setNum();
	bool	_calc();

public:
	RPN(char *arg);
	~RPN();

	void	calcRPN();
	long	get_st();
	bool	get_valid();
};

#endif
