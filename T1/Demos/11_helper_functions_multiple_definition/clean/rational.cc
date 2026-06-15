#include "rational.h"

// Free function at global scope -> externally visible symbol "computeGCD".
int computeGCD(int a, int b) {
    while (b) { int t = b; b = a % b; a = t; }
    return a;
}

int reduce(int n) { return computeGCD(n, 100); }
