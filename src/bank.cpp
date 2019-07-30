// STD
#include <iostream>
// ROS
// SWI prolog
#define PL_SAFE_ARG_MACROS
#include <SWI-cpp.h>

PREDICATE(hello, 1)
{ 

  std::cout << "Hello " << (char *)PL_A1 << std::endl;

  return TRUE;
};
