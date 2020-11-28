#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include "ch03.h"

// This is solution to practice problem #1 in page #44
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

// This is solution to practice problem #5 in page #44
std::string Ch03::ans05_int_to_string(int in)
{
  std::stringstream converter;
  std::string result;

  converter << in;
  if (converter >> result)
  {
    char remainder;
    if (converter >> remainder)
    {
      std::cout << "[Error] trouble while converting to string." 
                << std::endl;
      result = "";
    }
  }

  return result;
}

// Gets real number from the user. Based on GetInteger function from the 
// PDF file.
double Ch03::ans06_GetReal()
{
  double result;

  // Read input until user enters valid data
  while (true)
  {
    std::stringstream converter;
    converter << GetLine();

    /* Try reading an int, continue if we succeeded. */
    int result;
    if (converter >> result)
    {
      char remaining;
      if (converter >> remaining) // Something's left, input is invalid
        std::cout << "Unexpected character: " << remaining << std::endl;
      else
        return result;
    }
    else
      std::cout << "Please enter an integer." << std::endl;
    std::cout << "Retry: ";
  }
  return result;
}