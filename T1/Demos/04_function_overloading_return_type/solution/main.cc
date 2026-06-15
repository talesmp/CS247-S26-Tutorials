#include <iostream>

class Rational {
    int num_ = 3, denom_ = 4;
public:
    // Two operations, two distinct names. Overloading was never the right tool.
    int    getValueAsInt()    const { return num_ / denom_; }
    double getValueAsDouble() const { return static_cast<double>(num_) / denom_; }
};

int main() {
    Rational r;
    int    i = r.getValueAsInt();
    double d = r.getValueAsDouble();
    std::cout << i << " " << d << "\n";
}
