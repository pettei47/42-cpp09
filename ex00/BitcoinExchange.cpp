#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP
# include <iostream>
# include <map>

class BitcoinExchange
{
private:
	std::map<std::string, int>	_source;
  std::map<std::string, int>	_input;
	BitcoinExchange(BitcoinExchange const &);
	BitcoinExchange		&operator=(BitcoinExchange const &);

	bool	_validateArgs(char *arg);
	void	_setNum();
  void  _calc();

public:
	BitcoinExchange(char *arg);
	~BitcoinExchange();

	void	calcBitcoinExchange();
	int		get_st();
	bool	get_valid();
};

#endif
