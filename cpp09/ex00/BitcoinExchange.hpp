#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <stdexcept>
#include <string>

class BitcoinExchange {
 public:
  static std::map<time_t, float> read_database(std::string filename);
  static void process_input(const std::string filename,
                            const std::map<time_t, float>& database);
  BitcoinExchange();
  ~BitcoinExchange();

 private:
  BitcoinExchange& operator=(BitcoinExchange& copy);
  BitcoinExchange(BitcoinExchange& copy);
};

#endif