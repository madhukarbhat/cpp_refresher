#include <iostream>
#include "fn.hpp"

// ------------------------------------------------------------------------

void Ch00::show_params (int& a, int& b, int& c)
{
  std::cout << "---------" << std::endl
	    << "x = " << a << std::endl
	    << "y = " << b << std::endl
	    << "z = " << c << std::endl
	    << "---------" << std::endl;
  return;
}

// ------------------------------------------------------------------------

void Ch00::duplicate (int& a, int& b, int& c)
{
  const int multiplier = 2;
  a *= multiplier;
  b *= multiplier;
  c *= multiplier;
  return;
}

// ------------------------------------------------------------------------

void Ch00::fn ()
{
  std::cout << "Hello, World!" << std::endl;
  return;
}

// ------------------------------------------------------------------------

void Ch00::call_duplicate ()
{
  int x = 1, y = 3, z = 7;
  std::cout << "Initial Values:" << std::endl;
  show_params (x, y, z);

  duplicate (x, y, z);

  std::cout << std::endl << "After function call:" << std::endl;
  show_params (x, y, z);
  return;
}

// ------------------------------------------------------------------------

void Ch00::call_fn ()
{
  fn ();
  return;
}

// ------------------------------------------------------------------------
