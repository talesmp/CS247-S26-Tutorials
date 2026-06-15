// Answer (Q2.1): the program calls `std::terminate` (uncaught exception) => throw "…" throws a const char*. 
// Exception matching applies no conversions, so catch (const std::exception&) doesn't match => there's no handler, so std::terminate runs. 
// Throw a typed object derived from std::exception.

// Throw a typed object, not a bare value. 
// catch selects by TYPE and applies no conversions, so a thrown const char* is not a std::exception
// The handler never matches, the exception escapes main, and std::terminate runs.
#include <iostream>
#include <stdexcept>

int main() {
    try {
        throw "Denominator cannot be 0";   // const char*, NOT an exception object
    } catch (const std::exception& e) {     // doesn't match -> no catch
        std::cout << "caught: " << e.what() << '\n';
    }
    std::cout << "after\n";                  // never reached
}
// terminates: uncaught exception of type char const*.

// Fix: throw a typed object derived from std::exception (solution/).
