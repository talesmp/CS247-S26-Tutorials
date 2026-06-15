// Topic: Friends
// Can a friend function bypass the constructor's invariant check?
#include <iostream>
#include <stdexcept>

class Rational {
    friend void tamper(Rational& r);
    int num_, denom_;
public:
    Rational(int num, int denom) : num_{num}, denom_{denom} {
        if (denom == 0)
            throw std::out_of_range("denominator cannot be zero");
    }
    int num() const { return num_; }
    int denom() const { return denom_; }
};

void tamper(Rational& r) { r.denom_ = 0; }

int main() {
    Rational r(2, 3);
    std::cout << "before: " << r.num() << "/" << r.denom() << "\n";
    tamper(r);
    std::cout << "after:  " << r.num() << "/" << r.denom() << "\n";
}
