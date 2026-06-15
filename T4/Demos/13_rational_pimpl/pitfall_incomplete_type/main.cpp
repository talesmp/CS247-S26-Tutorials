#include "Rational.h"

int main() {
    Rational r(1, 2);   // destroyed at end of main, in THIS TU, where Impl is incomplete
    return 0;
}
