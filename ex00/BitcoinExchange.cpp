#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(std::map<std::string, float>	data) {
  _data = data;
}

BitcoinExchange::~BitcoinExchange() {}

bool  BitcoinExchange::_validateKey(std::string y, std::string m, std::string d) {
  int year;
  std::istringstream(y) >> year;
  int month;
  std::istringstream(m) >> month;
  int day;
  std::istringstream(d) >> day;

  if (year > 2022 || month == 0 || 12 < month || day == 0 || 31 < day)
    return false;
  if (month == 2 && day > 28 && year % 4 != 0)
    return false;
  if (month == 2 && day > 29 && year % 4 == 0)
    return false;
  if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
    return false;
  return true;
}

std::string BitcoinExchange::_setKey(std::string y, std::string m, std::string d) {
  int year;
  std::istringstream(y) >> year;
  int month;
  std::istringstream(m) >> month;
  int day;
  std::istringstream(d) >> day;

  while (1) {
    std::ostringstream sYear;
    sYear << std::setw(4) << std::setfill('0') << year;
    std::string strYear(sYear.str());
    std::ostringstream sMonth;
    sMonth << std::setw(2) << std::setfill('0') << month;
    std::string strMonth(sMonth.str());
    std::ostringstream sDay;
    sDay << std::setw(2) << std::setfill('0') << day;
    std::string strDay(sDay.str());
    std::string tmpKey = strYear + "-" + strMonth + "-" + strDay;
    if (_data.count(tmpKey) > 0)
      return tmpKey;
    // 見つからなければ1日ずつ戻る
    if (day == 1 && month == 1) {
      year--;
      month = 12;
      day = 31;
      if (year < 2009)
        return tmpKey;
    }
    else if (day == 1) {
      month--;
      if (month == 2 && year % 4 != 0)
        day = 28;
      else if (month == 2 && year % 4 == 0)
        day = 29;
      else if (month == 4 || month == 6 || month == 9 || month == 11)
        day = 30;
      else
        day = 31;
    }
    else
      day--;
  }
}

bool  BitcoinExchange::_validateValue(std::string value) {
  int dot = 0;
  for (size_t i = 0; i < value.size(); i++) {
    if (!std::isdigit(value[i]) && value[i] != '.' && dot < 2)
      return false;
    if (value[i] == '.')
      dot++;
  }
  return true;
}

void  BitcoinExchange::calcRate(std::string line) {
  if (line == "date | value")
    return;
  int spacePos = line.find(" ", 0);
  int pipePos = line.find("|", 0);
  if (spacePos != 10 || pipePos != 11 || line.size() < 13) {
    std::cerr << "Error: bad input => " << line << std::endl;
    return;
  }
  std::string year =  line.substr(0, 4);
  std::string month =  line.substr(5, 2);
  std::string day =  line.substr(8, 2);
  if (!_validateKey(year, month, day)) {
    std::cerr << "Error: bad input => " << line << std::endl;
    return;
  }
  std::string date = line.substr(0, 10);
  std::string key = _setKey(year, month, day);
  std::string strValue = line.substr(13, line.size() - 13);
  if (strValue.empty()) {
    std::cerr << "Error: bad input => " << line << std::endl;
    return;
  }
  if (!_validateValue(strValue))
  {
    std::cerr << "Error: not a positive number."
              << std::endl;
    return;
  }
  float value;
  std::istringstream(strValue) >> value;
  if (value > 1000) {
    std::cerr << "Error: too large a number."
              << std::endl;
    return;
  }
  std::cout << date << " => " << value << " = " << _data[key] * value << std::endl;
}
