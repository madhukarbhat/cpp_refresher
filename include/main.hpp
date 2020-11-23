#ifndef MAIN_HPP_DEFINED
#define MAIN_HPP_DEFINED

#define FILLER_SPACE "  "
#define CODE_EXIT        0x00
#define CODE_FN          0x01
#define CODE_DUPLICATE   0x02
#define CODE_BLAH        0x0A


#include <iostream>
#include <string>
#include <sstream>

#include "fn.hpp"

int show_menu_return_choice ();
void call_fn ();
void call_duplicate ();


#endif /*MAIN_HPP_DEFINED*/
