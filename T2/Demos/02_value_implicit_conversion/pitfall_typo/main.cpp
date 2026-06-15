// PITFALL: compiles, runs, prints the WRONG answer. 
// Typo `m == 5` (meant 500): 5 silently becomes Money{5} = 5 cents != 500, so it prints "no match". 
// No warning. `explicit Money(int)` would reject this line at compile time.
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
    if (m == 5)            // TYPO: meant 500 cents; 5 silently becomes Money{5}
        std::cout << "five dollars\n";
    else
        std::cout << "no match\n";
}

int main() { check(Money{500}); }   // prints: no match  (wrong!)
