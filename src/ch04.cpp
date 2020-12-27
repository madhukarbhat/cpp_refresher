#include "ch04.h"

// ------------------------------------------------------------------------
// Solution to question 12(c)
LengthUnit SuffixStringToLengthUnit(std::string suf)
{
#define DEFINE_UNIT(UnitName, scale, sufx, system) if ( suf == #sufx) { return eLengthUnit_##sufx; }
#include "units.h"
#undef DEFINE_UNIT

    return eLengthUnit_ERROR;
}

// ------------------------------------------------------------------------
// Solution to question 12(d)
struct Length ReadLength()
{
    struct Length len = {0};

    // Read input until user enters valid data
    while (true)
    {
        std::cout << "Enter a length: ";

        std::stringstream converter;
        converter << GetLine();

        // Accept and validate length value
        double result;
    
        // Try reading an double, continue if we succeeded.
        if (converter >> result)
        {
            char remaining;
            if (converter >> remaining) // Something's left, input is invalid
                std::cout << "Unexpected character: " << remaining << std::endl;
            else
            {
                len.data = result;
                break;
            }
        }
        else
            std::cout << "[Error] Cannot recognise the number, enter *real* number."
                      << std::endl;
        std::cout << "Retry. ";
    }

    // Read input until user enters valid data
    while (true)
    {
        // Accept and validate length unit
        std::cout << "Enter the length unit: ";

        std::string usrInput;
        LengthUnit lu;

        std::stringstream converter;
        converter << GetLine();
        if (converter >> usrInput)
        {
            lu = SuffixStringToLengthUnit(usrInput);
            if (lu == eLengthUnit_ERROR) {
                std::cout << "Unrecognized Unit: " << usrInput << std::endl;
            }
            else
            {
                len.unit = lu;
                return len;
            }
        }
        else
            std::cout << "[Error] Cannot recognise the unit, enter a valid unit."
                      << std::endl;
        std::cout << "Retry. ";
    }
    return len;
}

// ------------------------------------------------------------------------
// Solution to question 12(e)
std::string GetUnitType (Length  len)
{
#define DEFINE_UNIT(UnitName, scale, sufx, system) if ( len.unit == eLengthUnit_##sufx ) \
    { return #system; }
#include "units.h"
#undef DEFINE_UNIT

    return "ERROR";
}


// ------------------------------------------------------------------------
// Solution to question 12(f)
void PrintLength(Length len)
{
    std::string lenSuffix;
    std::string lenUnitName;
    
#define DEFINE_UNIT(UnitName, scale, sufx, system) if ( len.unit == eLengthUnit_##sufx ) \
    { lenSuffix = #sufx; lenUnitName = #UnitName; }
#include "units.h"
#undef DEFINE_UNIT

    std::cout << "[output] " << len.data << " " << lenSuffix
              << " ( " << len.data << " " << lenUnitName << " )"
              << std::endl;
    return;
}


// ------------------------------------------------------------------------
// Solution to question 12(g)
double ConvertToMeters(Length len)
{
    switch (len.unit)
    {
#define DEFINE_UNIT(UnitName, scale, sufx, system) case eLengthUnit_##sufx: return (len.data * ( scale ));
#include "units.h"
#undef DEFINE_UNIT
    default:
    {
        std::cerr << "[Error] Cannot recognise unit." << std::endl;
    }
    }
    return -1.0;
}
// ------------------------------------------------------------------------
// End
