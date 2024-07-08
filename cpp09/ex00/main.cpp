#include "BitcoinExchange.hpp"

int main(int argc, char* argv[]) {
  if (argc != 2) {
    std::cerr << "run like this : \n./btc <input-file>" << std::endl;
    return 1;
  }

  try {
    std::map<time_t, float> database =
        BitcoinExchange::read_database("data.csv");
    BitcoinExchange::process_input(argv[1], database);
  } catch (const std::exception& e) {
    std::cerr << e.what() << std::endl;
    return 1;
  }

  return 0;
}
