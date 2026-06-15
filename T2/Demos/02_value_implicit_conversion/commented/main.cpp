// Answer: five dollars -- non-explicit Money(int) silently turns `m == 500` into
// `m == Money{500}` (the same conversion hides typo bugs; see pitfall_typo/).

// Compiles and prints "five dollars", but the point is how.
// `m == 500` compares Money to int; Money(int) is non-explicit, so the compiler silently rewrites it as `m == Money{500}`. 
// Right here by luck; the same silent conversion fires for a typo like `m == 5` (5 cents).
//  wrong answer, no warning => (see pitfall_typo/). 
// Fix: mark the ctor explicit (../solution).
#include <iostream>

class Money {
    int cents_;
public:
    Money(int c) : cents_{c} {}   // NOT explicit -> int silently converts to Money
    friend bool operator==(const Money& a, const Money& b) {
        return a.cents_ == b.cents_;
    }
};

void check(const Money& m) {
    if (m == 500)                 // 500 silently promoted to Money{500}
        std::cout << "five dollars\n";
    else
        std::cout << "no match\n";
}

int main() { check(Money{500}); }   // five dollars
