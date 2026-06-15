// Answer: linker error (multiple definition of computeGCD); fix with an anonymous namespace.

#include <iostream>
#include "rational.h"
#include "date.h"

// Linking main.o + rational.o + date.o fails: "multiple definition of
// computeGCD(int, int)" -- both .cc export that global symbol.
// ../solution wraps each in an anonymous namespace.
int main() {
    std::cout << reduce(40) << " " << daysApart(12) << "\n";
}
