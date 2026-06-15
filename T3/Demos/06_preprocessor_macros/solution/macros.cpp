#include <iostream>

// FIX (part 1): if you MUST use a macro, parenthesize every parameter AND
// the whole body, because the preprocessor only pastes text.
#define SQUARE(x) ((x) * (x))   // SQUARE(2 + 3) -> ((2 + 3) * (2 + 3)) = 25
#define HALF(x)   ((x) / 2)     // HALF(4 + 2)   -> ((4 + 2) / 2)       = 3

// FIX part 2 (the real modern-C++ answer): don't use macros for this at all.
// Real functions are type-safe and obey normal evaluation rules.
constexpr int    square(int x)    { return x * x; }
constexpr double half(double x)   { return x / 2.0; }

int main() {
    std::cout << "SQUARE(2 + 3) = " << SQUARE(2 + 3) << "   (now 25)\n";
    std::cout << "HALF(4 + 2)   = " << HALF(4 + 2)   << "   (now 3)\n";
    std::cout << "square(2 + 3) = " << square(2 + 3) << "   (type-safe function)\n";
    std::cout << "half(4 + 2)   = " << half(4 + 2)   << "   (type-safe function)\n";

#ifdef DEBUG
    std::cout << "[debug] DEBUG is defined\n";
#endif
    return 0;
}
