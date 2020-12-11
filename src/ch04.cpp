#include "ch04.h"

LengthUnit SuffixStringToLengthUnit(std::string suf)
{
    LengthUnit lu = eLengthUnit_ERROR;
    #define DEFINE_UNIT(unit, scale, sufx, system) if (#sufx == suf) { lu = eLengthUnit_##sufx; }
    #include "units.h"
    #undef DEFINE_UNIT
    return lu;
}
