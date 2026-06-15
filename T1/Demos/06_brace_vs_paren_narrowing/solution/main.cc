#include <iostream>

class Rational {
    int num_, denom_;
public:
    Rational(int num, int denom = 1) : num_{num}, denom_{denom} {}
    int num() const { return num_; }
    int denom() const { return denom_; }
};

int main() {
    Rational m{2};                         // exact int, no narrowing -> 2/1
    Rational n{static_cast<int>(2.3)};     // intentional truncation, made LOUD -> 2/1
    std::cout << m.num() << "/" << m.denom() << "\n";
    std::cout << n.num() << "/" << n.denom() << "\n";
}
