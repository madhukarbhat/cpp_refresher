#ifndef CHAPTER04_HEADER_INCLUDED__
#define CHAPTER04_HEADER_INCLUDED__

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include "fn.h"

// Answer to Q12 (a) to (g)
enum LengthUnit {
    #define DEFINE_UNIT(UnitName, unit, suffix, system) eLengthUnit_##suffix, 
    #include "units.h"
    #undef DEFINE_UNIT
};

LengthUnit SuffixStringToLengthUnit(std::string suf);

#endif /* CHAPTER04_HEADER_INCLUDED__*/
