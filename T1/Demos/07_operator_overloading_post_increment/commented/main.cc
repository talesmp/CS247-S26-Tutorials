// Answer: both 3/1 (the old value was never saved).

#include <iostream>
#include "rational.h"
using std::cout;
using std::endl;

// Post-increment's contract: snapshot old value, increment, return the OLD value BY VALUE. 
// This breaks both: it increments first (no snapshot) and returns a reference to r.
const Rational& operator++(Rational& r, int) {
    r.setnum(r.getnum() + r.getdenom());   // 2/1 -> 3/1
    return r;                              // reference to the already-bumped r
}

int main() {
    Rational m(2, 1);
    Rational old = m++;    // copies from r AFTER the bump -> old = 3/1
    cout << old << endl;   // 3/1  (WRONG -- should be 2/1)
    cout << m << endl;     // 3/1
    // Compiles, runs, silently wrong. See ../solution.
}
