// Answer: Yes, tamper() writes denom_ = 0 directly, never running the ctor's check -> 2/0.

#include <iostream>
#include <stdexcept>

class Rational {
    friend void tamper(Rational& r);   // full access to privates, no accessors/ctor
    int num_, denom_;
public:
    Rational(int num, int denom) : num_{num}, denom_{denom} {
        if (denom == 0)                // ctor guards denom_ != 0...
            throw std::out_of_range("denominator cannot be zero");
    }
    int num() const { return num_; }
    int denom() const { return denom_; }
};

// ...but the friend writes denom_ directly, skipping that check.
void tamper(Rational& r) { r.denom_ = 0; }

int main() {
    Rational r(2, 3);                  // valid: passes the ctor check
    std::cout << "before: " << r.num() << "/" << r.denom() << "\n";   // 2/3
    tamper(r);
    std::cout << "after:  " << r.num() << "/" << r.denom() << "\n";   // 2/0 (invalid!)
    // Friendship is a deliberate hole in encapsulation. 
    // Re-checking accessors (check ./solution) are safer.
}
