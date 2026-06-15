#include <iostream>
#include "rational.h"
using std::cout;
using std::endl;

// Correct post-increment: return by value, snapshot before mutating.
Rational operator++(Rational& r, int) {
    Rational old = r;                      // snapshot first
    r.setnum(r.getnum() + r.getdenom());   // then increment
    return old;
}
// (Pre-increment instead returns Rational& to the modified object.)

int main() {
    Rational m(2, 1);
    Rational old = m++;
    cout << old << endl;   // 2/1  -- the value before the increment
    cout << m << endl;     // 3/1  -- the incremented value
}
