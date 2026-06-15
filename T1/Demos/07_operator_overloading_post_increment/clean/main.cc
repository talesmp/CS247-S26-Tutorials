// Topic: Operator Overloading
// The Post-Increment Lie: post-++ returns a reference and never snapshots the old value -- what do old and m print?
#include <iostream>
#include "rational.h"
using std::cout;
using std::endl;

const Rational& operator++(Rational& r, int) {
    r.setnum(r.getnum() + r.getdenom());
    return r;
}

int main() {
    Rational m(2, 1);
    Rational old = m++;
    cout << old << endl;
    cout << m << endl;
}
