// Topic: Undefined reference
// Q7.1: Assume that every file is correct. You build with `g++ main.cpp -o app`. What
// happens?
//   a) Prints `7^2 = 49`
//   b) Compiler error
//   c) Prints garbage
//   d) Linker error: undefined reference to `square(int)`

#include <iostream>
#include "mathutil.h"

int main() {
    std::cout << "7^2 = " << square(7) << "\n";
    return 0;
}
