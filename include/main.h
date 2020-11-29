#ifndef MAIN_HEADER_DEFINED
#define MAIN_HEADER_DEFINED

#define FILLER_SPACE "  "
/*
#define CODE_EXIT         0x00
#define CODE_FN           0x01
#define CODE_DUPLICATE    0x02
#define CODE_WRITE_FILE   0x03
#define CODE_STRINGSTREAM 0x04
*/

#include <iostream>
#include <string>
#include <vector>

#include "fn.h"
#include "ch00.h"
#include "ch03.h"

const std::vector<std::string> userChoice = {
    "Exit",
    "Execute fn()",
    "Execute duplicate()",
    "Execute write_file()",
    "Execute Ch03 ans05_int_to_string(inp)",
    "Execute Ch03 ans06_GetReal",
    "Execute Ch03 ans08_HasHexLetters()"};

#endif /*MAIN_HEADER_DEFINED*/
