#include "rational.h"

// computeGCD has external linkage -> exported from this .o. date.cc exports the
// same name, so the two collide at link time.
int computeGCD(int a, int b) {
    while (b) { int t = b; b = a % b; a = t; }
    return a;
}

int reduce(int n) { return computeGCD(n, 100); }
