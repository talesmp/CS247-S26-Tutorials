#include <iostream>
#include <stdexcept>

class DivideByZero : public std::runtime_error {
    int numer_;
public:
    explicit DivideByZero(int n)
        : std::runtime_error("Rational: divide by zero"), numer_(n) {}
    int numer() const noexcept { return numer_; }
};

int main() {
    try {
        throw DivideByZero(5);
    } catch (const DivideByZero& e) {
        std::cout << "caught: " << e.what()
                  << ", numerator was " << e.numer() << '\n';
    }
    std::cout << "after\n";
    return 0;
}
