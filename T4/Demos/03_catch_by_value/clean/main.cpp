// Topic: Catch by value
// Q3.1: Assume the code below compiles and runs. It prints:
//   a) `specific: input file missing`
//   b) `std::exception`
//   c) nothing
//   d) a linker error

#include <iostream>
#include <stdexcept>

int main() {
    try {
        throw std::runtime_error("specific: input file missing");
    } catch (std::exception e) {
        std::cout << e.what() << '\n';
    }
    return 0;
}


