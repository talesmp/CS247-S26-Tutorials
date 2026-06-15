#include <iostream>
#include "rational.h"
using std::cout;
using std::endl;

// Return the stream by reference so each << feeds the next.
std::ostream& operator<<(std::ostream& out, const Rational& r) {
    out << r.getnum() << '/' << r.getdenom();
    return out;
}

// operator>> takes a non-const Rational& because reading modifies it.
std::istream& operator>>(std::istream& in, Rational& r) {
    int num, denom;
    char slash;
    in >> num >> slash >> denom;   // "2/7"
    r = Rational(num, denom);
    return in;
}

int main() {
    Rational r(2, 7), s(1, 3);
    cout << r << " + " << s << endl;   // 2/7 + 1/3
}
