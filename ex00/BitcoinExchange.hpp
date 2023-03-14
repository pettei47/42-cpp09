#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP
# include <iostream>
# include <map>
#include <fstream>
#include <iostream>

class BitcoinExchange
{
private:
	static std::map<std::string, int>	dataCsv;

  std::map<std::string, int>	_input;
	BitcoinExchange(BitcoinExchange const &);
	BitcoinExchange		&operator=(BitcoinExchange const &);

public:
	BitcoinExchange();
	~BitcoinExchange();
};

#endif
