#include "BitcoinExchange.hpp"

int main (int argc, char **argv)
{
  if (argc != 2)
  {
    std::cerr << "Error: could not open file." << std::endl;
    return 1;
  }
  // data.csvの読み込み
  std::ifstream dataCsv("./data.csv");
  if (dataCsv.fail())
  {
    std::cerr << "Error: could not open file." << std::endl;
    return 1;
  }
  // 引数のファイル読み込み
  std::ifstream input(argv[1]);
  if (input.fail())
  {
    std::cerr << "Error: could not open file." << std::endl;
    return 1;
  }

}
