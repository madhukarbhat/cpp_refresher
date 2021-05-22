#include "fn.h"

// ------------------------------------------------------------------------
std::string GetLine()
{
    std::string result;
    getline(std::cin, result);
    return result;
}

// ------------------------------------------------------------------------

int GetInteger()
{
    while (true)
    { 
        // Read input until user enters valid data
        std::stringstream converter;
        converter << GetLine();

        /* Try reading an int, continue if we succeeded. */
        int result;
        if (converter >> result)
        {
            char remaining;
            if (converter >> remaining) // Something's left, input is invalid
                std::cout << "Unexpected character: " << remaining << std::endl;
            else
                return result;
        }
        else
            std::cout << "Please enter an integer." << std::endl;
        std::cout << "Retry: ";
    }
    return -1;   
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
