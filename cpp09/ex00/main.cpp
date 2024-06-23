#include <fstream>
#include <iostream>
#include <stdexcept>
#include <vector>

int main(int ac, char* av[]) {
  if (ac != 2) throw std::runtime_error("no filename provided");

  const std::string filename(av[1]);
  std::ifstream ifs(filename);
  if (!ifs.is_open()) throw std::runtime_error("not valid file");
  //   std::cout << ifs << std::endl;
  vector<int, std::string> data;
  data << ifs;
}