#include <iostream>

// A preprocessor macro = blind TEXT substitution (no evaluation, no parentheses).
#define SQUARE(x) x * x      // SQUARE(2 + 3)  ->  2 + 3 * 2 + 3  =  11  (not 25!)

int main() {
    std::cout << "SQUARE(2 + 3) = " << SQUARE(2 + 3) << "   (expected 25)\n";

    // Conditional compilation: this line exists ONLY if VERBOSE is defined,
    // e.g. when compiled with  -DVERBOSE  on the command line.
#ifdef VERBOSE
    std::cout << "[verbose] this line was kept because VERBOSE is defined\n";
#endif
    return 0;
}
