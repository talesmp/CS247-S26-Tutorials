#include <iostream>
#include <stdexcept>

class Rational {
    int num_, denom_;
public:
    // explicit: Rational(5) still works, but no implicit int -> Rational.
    explicit Rational(int num, int denom = 1) : num_{num}, denom_{denom} {
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
    // print(5);             // ERROR now: no implicit int -> Rational conversion
    print(Rational(5));      // auditable: the conversion is written out by hand
}
