#include <iostream>

class Money {
    int cents_;
public:
    explicit Money(int c) : cents_{c} {}   // explicit: no silent int -> Money
    friend bool operator==(const Money& a, const Money& b) {
        return a.cents_ == b.cents_;
    }
};

void check(const Money& m) {
    if (m == Money{500})   // conversion is now spelled out by the caller
        std::cout << "five dollars\n";
    else
        std::cout << "no match\n";
}

int main() { check(Money{500}); }   // prints: five dollars
