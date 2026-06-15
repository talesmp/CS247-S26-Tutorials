#include <iostream>
#include <stdexcept>

class Rational {
    int num_, denom_;   // no friend: no outside access
public:
    Rational(int num, int denom) : num_{num}, denom_{denom} {
        if (denom == 0)
            throw std::out_of_range("denominator cannot be zero");
    }
    // Only way to change denom_: a mutator that re-checks the invariant.
    void setDenom(int d) {
        if (d == 0)
            throw std::out_of_range("denominator cannot be zero");
        denom_ = d;
    }
    int num() const { return num_; }
    int denom() const { return denom_; }
};

int main() {
    Rational r(2, 3);
    std::cout << "before: " << r.num() << "/" << r.denom() << "\n";

    // r.denom_ = 0;     // ERROR: denom_ is private, no friend grants access
    // r.setDenom(0);    // would THROW: the invariant is re-checked here too

    r.setDenom(5);       // the only path through, and it stays valid
    std::cout << "after:  " << r.num() << "/" << r.denom() << "\n";   // 2/5
}
