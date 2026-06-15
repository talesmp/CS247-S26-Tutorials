// Topic: Constant Member Functions
// Can a `const` method modify a member variable?
#include <iostream>

class Rational {
    int num_, denom_;
    mutable int accessCount_ = 0;
public:
    Rational(int num, int denom) : num_{num}, denom_{denom} {}
    int getnum() const {
        accessCount_++;
        return num_;
    }
    int accesses() const { return accessCount_; }
};

int main() {
    const Rational r{3, 4};
    std::cout << r.getnum() << "\n";
    std::cout << r.getnum() << "\n";
    std::cout << "accessed " << r.accesses() << " times\n";
}
