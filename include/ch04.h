#ifndef CHAPTER04_HEADER_INCLUDED__
#define CHAPTER04_HEADER_INCLUDED__

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include "fn.h"

// Solution to question 12(b)
enum LengthUnit {
    #define DEFINE_UNIT(UnitName, unit, suffix, system) eLengthUnit_##suffix, 
    #include "units.h"
    #undef DEFINE_UNIT
};

// Solution to question 12(d)
struct Length {
  double data;
  LengthUnit unit;  
};

// Solution to question 12(c)
LengthUnit SuffixStringToLengthUnit(std::string suf);

// Solution to question 12(d)
struct Length ReadLength();

#endif /* CHAPTER04_HEADER_INCLUDED__*/
