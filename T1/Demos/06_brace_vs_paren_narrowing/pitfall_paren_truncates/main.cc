#include <iostream>

class Rational {
    int num_, denom_;
public:
    Rational(int num, int denom = 1) : num_{num}, denom_{denom} {}
    int num() const { return num_; }
    int denom() const { return denom_; }
};

int main() {
    // Parens allow the narrowing: 2.3 silently truncates to 2 -> m = 2/1. Compiles clean at -Wall -Wextra; only -Wconversion warns.
    Rational m(2.3);
    std::cout << m.num() << "/" << m.denom() << "\n";   // prints 2/1
}
