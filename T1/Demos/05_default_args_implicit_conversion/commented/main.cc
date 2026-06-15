// Answer: print(5) silently becomes Rational(5,1) via the non-explicit ctor => compiles with no warning.

#include <iostream>
#include <stdexcept>

class Rational {
    int num_, denom_;
public:
    // denom defaults, so this ctor takes one int: Rational(5) == Rational(5,1).
    // Not explicit -> the compiler will also call it implicitly to convert int.
    Rational(int num, int denom = 1) : num_{num}, denom_{denom} {
        if (denom == 0)
            throw std::out_of_range("denominator cannot be zero");
    }
    int num() const { return num_; }
    int denom() const { return denom_; }
};

void print(Rational r) {
    std::cout << r.num() << "/" << r.denom() << "\n";
}

int main() {
    // print() wants a Rational; passing int 5 silently becomes Rational(5,1).
    // Prints "5/1" with NO warning, even -Wall -Wextra. Mark the ctor explicit to forbid it (../solution).
    print(5);
}
