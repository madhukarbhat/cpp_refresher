#include "ch05.h"

// ------------------------------------------------------------------------
// Solution to Practice Problem #5
std::vector<std::string> q5_LinesFromFile(std::string filename)
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
// Answer to question #6:

size_t InsertionIndex(std::vector<int> &v, int toInsert)
{
    for (size_t i = 0; i < v.size(); ++i) {
        if (toInsert > v[i]) {
            return i;
        }
    }
    return v.size();
}

// ------------------------------------------------------------------------

void q6_reverse_sort()
{
    std::vector<int> values;
    const int kNumValues = 10;

    std::cout << "Enter " << kNumValues << " integers below:" << std::endl;

    /* Read the values. */
    for (int i = 0; i < kNumValues; ++i)
    {
        std::cout << std::setw(2) << (i + 1) << " : ";
        int val = GetInteger();

        /* Insert the element at the correct position. */
        values.insert(values.begin() + InsertionIndex(values, val), val);
    }

    /* Print out the sorted list. */
    std::cout << std::endl << "Reverse sorted:" << std::endl;
    for (size_t i = 0; i < values.size(); ++i) {
        std::cout << values[i] << " ";
    }
    std::cout << std::endl;
    return;
}

// ------------------------------------------------------------------------
// End.