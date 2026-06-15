// Topic: Default Arguments
// How do default arguments interact with implicit conversion?
#include <iostream>
#include <stdexcept>

class Rational {
    int num_, denom_;
public:
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
    print(5);
}
