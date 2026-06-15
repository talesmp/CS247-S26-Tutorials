// Answer (Q3.1): `std::exception`.
// Catching std::exception by value slices the runtime_error into a base-sized slot, discarding its stored message.
// The virtual what() then returns the base's generic "std::exception". 
// Catch by const& to keep the real type. (`g++ -Wall` warns via -Wcatch-value; clang doesn't.)

// Catch by const reference, never by value. 
// Catching the base BY VALUE slices the runtime_error into a base-sized std::exceptio. 
// The virtual what() then dispatches to the base and returns the literal "std::exception".
#include <iostream>
#include <stdexcept>

int main() {
    try {
        throw std::runtime_error("specific: input file missing");
    } catch (std::exception e) {        // BY VALUE -> slices off the runtime_error part
        std::cout << e.what() << '\n';   // "std::exception", not the real message
    }
}
// `g++ -Wall` warns (-Wcatch-value); clang is silent.
// Fix: catch (const std::exception& e) (solution/).
