#ifndef CHAPTER03_HEADER_INCLUDED__
#define CHAPTER03_HEADER_INCLUDED__

#include <string>
#include "fn.h"

class Ch03 {
public:
  bool write_file(std::string fname);
  std::string ans05_int_to_string(int in);
  double ans06_GetReal();
  bool ans08_HasHexLetters();
  void ans09_DrawTriangle();
};

#endif /* CHAPTER03_HEADER_INCLUDED__*/
