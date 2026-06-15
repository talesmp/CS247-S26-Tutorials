// Answer: Rational(1) = 1/1, so `r == 1` compares 3/4 == 1/1 -> false. No warning.

#include <iostream>
#include <stdexcept>

class Rational {
    int num_, denom_;
public:
    Rational(int n) noexcept : num_{n}, denom_{1} {}   // single-arg, NOT explicit
    Rational(int num, int denom) : num_{num}, denom_{denom} {
        if (denom == 0) throw std::out_of_range("denominator cannot be zero");
    }
    bool operator==(const Rational& rhs) const {
        return num_ * rhs.denom_ == denom_ * rhs.num_;
    }
};

int main() {
    Rational r(3, 4);
    // 1 is silently converted to Rational(1) == 1/1, so this compares 3/4 == 1/1 -> false. 
    // No warning. Mark the ctor explicit and this line stops compiling (check in the folder ./solution).
    if (r == 1) {                      // what's really happenning: r == Rational(1)
        std::cout << "equal\n";
    } else {
        std::cout << "not equal\n";    // taken
    }
}
