// Answer: chaining -- (cout << r) is void, so the next << has no match -> compile error.

#include <iostream>
#include "rational.h"
using std::cout;
using std::endl;

// Returns void, which breaks chaining. 
// `cout << r << " + "` parses as (cout << r) << " + "; 
// the first call yields void, and there's no operator<<(void, ...), so it won't compile.
void operator<<(std::ostream& out, const Rational& r) {
    out << r.getnum() << '/' << r.getdenom();
}

int main() {
    Rational r(2, 7), s(1, 3);
    cout << r << " + " << s << endl;   // ERROR: no operator<< for (void, ...)
    // Returning std::ostream& is required for chaining. See ../solution.
}
