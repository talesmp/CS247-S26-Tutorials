// Topic: Preprocessor macros
// Q4.1: Assume macros.cpp compiles and runs. The first line prints SQUARE(2 + 3) = …?
//   a) 10
//   b) 11
//   c) 25
#include <iostream>

#define SQUARE(x) x * x
#define HALF(x)   x / 2

int main() {
    std::cout << "SQUARE(2 + 3) = " << SQUARE(2 + 3) << " \n";
    std::cout << "HALF(4 + 2)   = " << HALF(4 + 2)   << " \n";

#ifdef DEBUG
    std::cout << "[debug] DEBUG is defined, so this line was KEPT\n";
#endif
    return 0;
}

