#include "main.h"

// ------------------------------------------------------------------------

int main(int argc, char *argv[])
{
    int command = 99;
    if (argc == 2)
    {
        std::string input(argv[1]);
        std::stringstream(input) >> command;
    }
    else
    {
        command = show_menu_return_choice();
    }

    for (;;)
    {
        switch (command)
        {
        case 0:
        {
            std::cout << "Bye!" << std::endl;
            break;
        }
        case 1:
        {
            Ch00 ch00;
            ch00.call_fn();
            break;
        }
        case 2:
        {
            Ch00 ch00;
            ch00.call_duplicate();
            break;
        }
        case 3:
        {
            Ch03 ch03;
            ch03.write_file("tmp/ch03.txt");
            break;
        }
        case 4:
        {
            Ch03 ch03;
            int inp = 123123;
            std::cout << "[Info] Converting "
                      << inp << " to string using stringstream: "
                      << std::endl;

            if (typeid(inp) == typeid(int))
            {
                std::cout << "[Info] Type: integer" << std::endl;
            }

            auto outp = ch03.ans05_int_to_string(inp);
            std::cout << outp << std::endl;

            if (typeid(outp) == typeid(std::string))
            {
                std::cout << "[Info] Type: std::string" << std::endl;
            }

            break;
        }
        case 5:
        {
            Ch03 ch03;
            double ret = ch03.ans06_GetReal();
            if (ret != 0.0)
            {
                std::cout << "You Entered: " << ret << std::endl;
            }
            else
            {
                std::cout << "[Error] Unable to recognise the number, "
                          << "unless you entered  0.0"
                          << std::endl;
            }
            break;
        }
        case 6:
        {
            Ch03 ch03;
            ch03.ans08_HasHexLetters();
            break;
        }
        case 7:
        {
            Ch03 ch03;
            ch03.ans09_DrawTriangle();
            break;
        }
        case 8:
        {
            Ch03 ch03;
            std::ifstream infile;
            ch03.ans10_OpenFile(infile);
            break;
        }
        case 9:
        {
            Length l = ReadLength();
            std::cout << "Length: " << l.data << " " << l.unit << std::endl;
            break;
        }
        case 10:
        {
            Length l = ReadLength();
            std::string unitSystem = GetUnitType(l);
            std::cout << "Unit System : " << unitSystem << std::endl;
            break;
        }
        case 11:
        {
            Length l = ReadLength();
            PrintLength(l);
            break;
        }
        case 12:
        {
            Length l = ReadLength();
            std::cout << "[Output] " << ConvertToMeters(l) << " m" << std::endl;
            break;
        }
        case 13:
        {
            std::cout << "[Input] Enter filename: ";
            std::vector<std::string> fc = q5_LinesFromFile(GetLine());
            std::cout << "[Status] Completed reading, printing output:" << std::endl;
            long count = 0;
            for (std::string ln : fc) {
                std::cout << "[" << std::setw(3) << count << "] " << ln << std::endl;
                ++count;
            }
            std::cout << "[Status] End" << std::endl;
            break;
        }
        case 14:
        {
            q6_reverse_sort();
            break;
        }
        default:
        {
            std::cout << command << " : Not a recognized option, try again."
                      << std::endl;
        }
        }

        if (command != 0)
        {
            command = show_menu_return_choice();
        }
        else
        {
            break;
        }
    }
    return 0;
}

// ------------------------------------------------------------------------
