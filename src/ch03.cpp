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
  double state = 0.0;

  // Read input until user enters valid data
  while (true)
  {
    std::cout << "Enter a real number: ";

    std::stringstream converter;
    converter << GetLine();

    double result;

    /* Try reading an double, continue if we succeeded. */
    if (converter >> result)
    {
      char remaining;
      if (converter >> remaining) // Something's left, input is invalid
        std::cout << "Unexpected character: " << remaining << std::endl;
      else
        return result;
    }
    else
      std::cout << "[Error] Cannot recognise the number, enter *real* number."
                << std::endl;
    std::cout << "Retry. ";
  }
  return state;
}

// Takes in integer as input and tells if its Hex representation has 
// alphabets.
bool Ch03::ans08_HasHexLetters()
{
  bool state = true;
  std::stringstream converter;
  int num;

  std::cout << "Enter an integer in decimal format: ";
  converter << GetLine();
  converter >> num;

  converter.str(std::string());
  converter.clear();
  converter << std::dec << num;
  std::cout << "Decimal    : " << converter.str() << std::endl;

  converter.str(std::string());
  converter.clear();
  converter << std::hex << num;
  std::cout << "Hexadecimal: " << converter.str() << std::endl;

  int chknum;
  if (converter >> std::dec >> chknum)
  {
    std::string remaining;
    if (converter >> remaining)
    {
      std::cout << "[Info] Hex format of your number has Hex Letters."
                << std::endl;
    }
  }
  return state;
}