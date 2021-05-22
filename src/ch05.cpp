#include "ch05.h"

// ------------------------------------------------------------------------
// Solution to Practice Problem #5
std::vector<std::string> LinesFromFile(std::string filename)
{
    std::vector<std::string> fcontent;
    std::ifstream in(filename);
    if (in.is_open()) {
        std::string line;
        while (std::getline(in, line)) {
            fcontent.push_back(line);
        }
        in.close();
    }

    return fcontent;
}

// ------------------------------------------------------------------------
// End.