#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP
# include <iostream>
# include <map>
#include <fstream>
#include <iostream>
#include <sstream>

class BitcoinExchange
{
private:
	typedef std::map<std::string, float>	BEdata;
	BEdata	_data;
	BitcoinExchange(BitcoinExchange const &);
	BitcoinExchange		&operator=(BitcoinExchange const &);

	bool	_validateLine(std::string line);
	bool	_validateKey(std::string year, std::string month, std::string day);
	bool	_validateValue(std::string value);

public:
	BitcoinExchange(BEdata data);
	~BitcoinExchange();

	void	calcRate(std::string line);
};

#endif
