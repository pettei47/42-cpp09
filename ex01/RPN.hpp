#ifndef RPN_HPP
# define RPN_HPP
# include <iostream>
# include <deque>

class RPN
{
private:
	std::deque<int>	_st;
	RPN(RPN const &);
	RPN		&operator=(RPN const &);

public:
	RPN(int first);
	~RPN();

	void	setNum(int newItem);
  void  calc(std::string newOperator);
  int get_st();

};

std::ostream	&operator<<(std::ostream &, RPN const&);

#endif
