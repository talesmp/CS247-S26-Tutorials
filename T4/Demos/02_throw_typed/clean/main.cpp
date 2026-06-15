// Topic: Throw a typed object
// Q2.1: What happens when you run it?
//   a) prints `caught: Denominator cannot be 0`
//   b) prints `after` only
//   c) the program calls `std::terminate` (uncaught exception)
//   d) it doesn't compile

#include <iostream>
#include <stdexcept>

int main() {
    try {
        throw "Denominator cannot be 0";
    } catch (const std::exception& e) {
        std::cout << "caught: " << e.what() << '\n';
    }
    std::cout << "after\n";
    return 0;
}

