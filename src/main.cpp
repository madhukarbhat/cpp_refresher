// g++ -std=c++11 fn.cpp -o fn
//
// Example: Passing parameters by reference

#include "main.hpp"

// ------------------------------------------------------------------------

int main (int argc, char* argv[])
{
  int command = 99;
  if (argc == 2) {
    std::string input (argv[1]);
    std::stringstream(input) >> command;
  } else {
    command = show_menu_return_choice();
  }

  for (;;) {
    switch (command) {
    case CODE_EXIT:
      {
	std::cout << "Bye!" << std::endl;
	break;
      }
    case CODE_FN:
      {
	Ch00 ch00;
	ch00.call_fn();
	break;
      }
    case CODE_DUPLICATE:
      {
	Ch00 ch00;
	ch00.call_duplicate();
	break;
      }
    case CODE_WRITE_FILE:
      {
	Ch03 ch03;
	ch03.write_file("tmp/ch03.txt");
	break;
      }
    case CODE_BLAH:
      {
	std::cout << command << " : command not implemented, sorry!"
		  << std::endl;
	break;
      }
    default:
      std::cout << command << " : Not a recognized option, try again."
		<< std::endl;
    }
    if (command != CODE_EXIT) {
      command = show_menu_return_choice();
    } else {
      break;
    }
  }
  return 0;
}

// ------------------------------------------------------------------------

int show_menu_return_choice ()
{
  int choice = 0;

  std::cout << std::endl
	    << "--------------------------------------------------"
	    << std::endl;
  std::cout << "Available options:" << std::endl
	    << FILLER_SPACE << CODE_EXIT        << ". Exit"                 << std::endl
	    << FILLER_SPACE << CODE_FN          << ". Execute fn()"         << std::endl
	    << FILLER_SPACE << CODE_DUPLICATE   << ". Execute duplicate()"  << std::endl
	    << FILLER_SPACE << CODE_WRITE_FILE  << ". Execute write_file()" << std::endl
	    << FILLER_SPACE << CODE_BLAH        << ". Execute blah ()"      << std::endl
	    << "Enter choice: ";

  std::string usr_input;
  getline (std::cin,usr_input);
  std::stringstream (usr_input) >> choice;

  std::cout << std::endl
	    << "--------------------------------------------------"
	    << std::endl
	    << "Execution results:"
	    << std::endl
	    << std::endl;

  return choice;
}

// ------------------------------------------------------------------------
