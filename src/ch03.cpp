#include <iostream>
#include <fstream>
#include <string>

#include "ch03.hpp"

bool Ch03::write_file(std::string fname)
{
  bool status = false;
  std::ofstream outf(fname);
  if (!outf.is_open()) {
    std::cerr << "[Error] Unable to create file." << fname << std::endl;
    return status;
  } else {
    status = true;
  }
  outf << "Hello, ofstream file!" << std::endl;
  std::cout << "Created file: " << fname << std::endl;
  return status;
}
