#include "BitcoinExchange.hpp"

time_t str_to_time(const std::string& date) {
  struct tm tm = {};
  if (strptime(date.c_str(), "%Y-%m-%d", &tm) == NULL) {
    throw std::runtime_error("Error: bad date format.");
  }
  return mktime(&tm);
}

// db 읽어서 map에 저장
std::map<time_t, float> BitcoinExchange::read_database(
    const std::string filename) {
  std::ifstream file(filename.c_str());
  if (!file.is_open()) {
    throw std::runtime_error("Error: could not open file.");
  }

  std::map<time_t, float> database;
  std::string line;
  std::getline(file, line);  // Skip header line
  while (std::getline(file, line)) {
    std::stringstream ss(line);
    std::string date;
    time_t time;
    float rate;
    if (std::getline(ss, date, ',') && ss >> rate) {
      time = str_to_time(date);
      database.insert(std::make_pair(time, rate));
    }
  }

  return database;
}

bool comp(const std::pair<const time_t, float>& p, const time_t date) {
  return p.first < date;
}

void BitcoinExchange::process_input(const std::string filename,
                                    const std::map<time_t, float>& database) {
  std::ifstream file(filename.c_str());
  if (!file.is_open()) {
    throw std::runtime_error("Error: could not open file.");
  }

  std::string line;
  std::getline(file, line);  // 첫줄스킵
  while (std::getline(file, line)) {
    std::stringstream ss(line);
    std::string date_str;
    std::string value_str;
    if (std::getline(ss, date_str, '|') && std::getline(ss, value_str)) {
      // Trim whitespace
      date_str.erase(date_str.find_last_not_of(" \n\r\t") +
                     1);  // find_last_not_of : 문자열의 끝에서부터 주어진
                          // 문자열이 아닌 문자를 찾음
      value_str.erase(0,
                      value_str.find_first_not_of(
                          " \n\r\t"));  // find_first_not_of : 문자열의 처음부터
                                        // 주어진 문자열이 아닌 문자를 찾음  //
                                        // erase : 문자열에서 특정 문자열을 제거
      char* end;
      float value = std::strtof(value_str.c_str(),
                                &end);  // 문자열을 부동소수점으로 변환, stdlib
      if (*end != '\0') {               // 파일 오류
        std::cout << "Error: bad input => " << line << std::endl;
        continue;
      }

      if (value < 0) {
        std::cout << "Error: not a positive number." << std::endl;
        continue;
      } else if (value > 1000) {
        std::cout << "Error: too large a number." << std::endl;
        continue;
      }

      time_t date;
      try {
        date = str_to_time(date_str);
      } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
        continue;
      }

      // 날짜 확인 및 비트코인 가격 계산
      std::map<time_t, float>::const_iterator it =
          std::lower_bound(database.begin(), database.end(), date, comp);
      if (it == database.end() || it->first != date) {
        if (it != database.begin()) {
          --it;
        } else {
          std::cout << "Error: date not found => " << date_str << std::endl;
          continue;
        }
      }

      float rate = it->second;
      float result = value * rate;
      std::cout << date_str << " => " << value << " = " << result << std::endl;
    } else {
      std::cout << "Error: bad input => " << line << std::endl;
    }
  }
}

BitcoinExchange::BitcoinExchange(){};
BitcoinExchange::~BitcoinExchange(){};
BitcoinExchange& BitcoinExchange::operator=(BitcoinExchange& copy) {
  if (this == &copy) return *this;
  return *this;
};
BitcoinExchange::BitcoinExchange(BitcoinExchange& copy) { *this = copy; };
