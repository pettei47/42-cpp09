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
	std::map<std::string, float>	_data;
	BitcoinExchange(BitcoinExchange const &);
	BitcoinExchange		&operator=(BitcoinExchange const &);

	bool  _validateLine(std::string line);
  bool  _validateKey(std::string year, std::string month, std::string day);
  std::string _setKey(std::string year, std::string month, std::string day);
  bool  _validateValue(std::string value);

public:
	BitcoinExchange(std::map<std::string, float>	data);
	~BitcoinExchange();

  void  calcRate(std::string line);
};

#endif
