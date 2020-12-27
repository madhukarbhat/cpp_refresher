#include "fn.h"

// ------------------------------------------------------------------------
std::string GetLine()
{
    std::string result;
    getline(std::cin, result);
    return result;
}

// ------------------------------------------------------------------------

int show_menu_return_choice()
{
    int choice = 0;

    std::cout << std::endl
              << "--------------------------------------------------"
              << std::endl;

    std::cout << "Available options:" << std::endl;
    int i = 0;
    for (std::string choice : userChoice)
    {
        std::cout << i << " : " << choice << std::endl;
        ++i;
    }
    std::cout << "Enter choice: ";

    std::string usr_input;
    getline(std::cin, usr_input);
    std::stringstream(usr_input) >> choice;

    std::cout << std::endl
              << "--------------------------------------------------"
              << std::endl
              << "Execution results:"
              << std::endl
              << std::endl;

    return choice;
}

// ------------------------------------------------------------------------
