// Answer (Q4.1): 11 -- Pure text substitution => 2 + 3 * 2 + 3 = 11. And the second line
// prints => 4 + 2 / 2 = 5. No evaluation, no parentheses.

#include <iostream>

// BROKEN. The preprocessor does BLIND TEXT substitution — no evaluation,
// no understanding of operator precedence, no parentheses added for you.
#define SQUARE(x) x * x      // SQUARE(2 + 3) -> 2 + 3 * 2 + 3
#define HALF(x)   x / 2      // HALF(4 + 2)   -> 4 + 2 / 2

int main() {
    std::cout << "SQUARE(2 + 3) = " << SQUARE(2 + 3) << "   (expected 25)\n";
    std::cout << "HALF(4 + 2)   = " << HALF(4 + 2)   << "   (expected 3)\n";

    // Conditional compilation: this line only exists if DEBUG is defined.
#ifdef DEBUG
    std::cout << "[debug] DEBUG is defined, so this line was KEPT\n";
#endif
    return 0;
}
