// Topic: Streaming Operators (<< and >>)
// What does returning void from operator<< break?
#include <iostream>
#include "rational.h"
using std::cout;
using std::endl;

void operator<<(std::ostream& out, const Rational& r) {
    out << r.getnum() << '/' << r.getdenom();
}

int main() {
    Rational r(2, 7), s(1, 3);
    cout << r << " + " << s << endl;
}
