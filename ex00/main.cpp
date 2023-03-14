#include "BitcoinExchange.hpp"

std::map<std::string, float>  convertCsvToMap(std::string path)
{
  std::ifstream dataCsv(path);
  if (dataCsv.fail())
  {
    std::cerr << "Error: could not open file." << std::endl;
    std::exit(1);
  }
  std::map<std::string, float>  ret;
  std::string line;
  while (std::getline(dataCsv, line))
  {
    if (line == "date,exchange_rate")
      continue;
    std::string key = line.substr(0, 10);
    std::string value = line.substr(11, line.size() - 11);
    std::istringstream(value) >> ret[key];
  }
  return ret;
}

void  printDataMap(std::map<std::string, float> map)
{
  for(std::map<std::string, float>::iterator itr = map.begin();
      itr != map.end(); ++itr) {
    std::cout << "key = " << itr->first
              << ", val = " << itr->second << std::endl;;
  }
}

int main (int argc, char **argv)
{
  if (argc != 2)
  {
    std::cerr << "Error: could not open file." << std::endl;
    return 1;
  }
  std::map<std::string, float> data = convertCsvToMap("./data.csv");
  // printDataMap(data);
  std::ifstream input(argv[1]);
  if (input.fail())
  {
    std::cerr << "Error: could not open file." << std::endl;
    return 1;
  }

  BitcoinExchange be(data);
  std::string line;
  while (std::getline(input, line)) {
    be.calcRate(line);
  }
}
