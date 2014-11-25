#pragma once

#include <iostream>
#include <string>


#ifdef _DEBUG

#define PRINT_DEBUG(x) do { std::cerr << "DEBUG: " << x << std::endl;  }while(0);
#define PRINT_DEBUG_P(x,...) do { std::cerr << "DEBUG: " << x << __VA_ARGS__ << std::endl;  }while(0);

#else

#define PRINT_DEBUG(x)


#endif
