#include <iostream>

class Rational {
    int num_, denom_;
    int accessCount_ = 0;   // NOTE: `mutable` removed
public:
    Rational(int num, int denom) : num_{num}, denom_{denom} {}
    int getnum() const {
        accessCount_++;     // ERROR: cannot modify a non-mutable member in a const method
        return num_;
    }
    int accesses() const { return accessCount_; }
};

int main() {
    const Rational r{3, 4};
    std::cout << r.getnum() << "\n";
}
