// Topic: Value Objects
// What does this print?
#include <iostream>

class Money {
    int cents_;
public:
    Money(int c) : cents_{c} {}
    friend bool operator==(const Money& a, const Money& b) {
        return a.cents_ == b.cents_;
    }
};

void check(const Money& m) {
    if (m == 500)
        std::cout << "five dollars\n";
    else
        std::cout << "no match\n";
}

int main() { check(Money{500}); }
