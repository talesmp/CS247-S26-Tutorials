// Topic: Type Conversion and explicit
// What does 1 silently become without explicit?
#include <iostream>
#include <stdexcept>

class Rational {
    int num_, denom_;
public:
    Rational(int n) noexcept : num_{n}, denom_{1} {}      // single-arg, NOT explicit
    Rational(int num, int denom) : num_{num}, denom_{denom} {
        if (denom == 0) throw std::out_of_range("denominator cannot be zero");
    }
    bool operator==(const Rational& rhs) const {
        return num_ * rhs.denom_ == denom_ * rhs.num_;
    }
};

int main() {
    Rational r(3, 4);
    if (r == 1) {
        std::cout << "equal\n";
    } else {
        std::cout << "not equal\n";
    }
}
