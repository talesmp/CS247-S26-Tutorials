// Answer: yes, if the member is `mutable` (use only for caches/counters invisible to the outside).

#include <iostream>

class Rational {
    int num_, denom_;
    mutable int accessCount_ = 0;   // mutable: a const method may change this one
public:
    Rational(int num, int denom) : num_{num}, denom_{denom} {}

    // const promises not to change the *logical* value (3/4). 
    // Bumping a counter doesn't, so it's "logically const" -- allowed only because it's mutable.
    int getnum() const {
        accessCount_++;
        return num_;
    }
    int accesses() const { return accessCount_; }
};

int main() {
    const Rational r{3, 4};   // even a const object's mutable member can change
    std::cout << r.getnum() << "\n";
    std::cout << r.getnum() << "\n";
    std::cout << "accessed " << r.accesses() << " times\n";
    // Use mutable only for members invisible outside (caches, counters).
    // Remove it and the const method won't compile -- see ../pitfall_without_mutable.
}
