#include "date.h"

// Different file, different project area, SAME global symbol name "computeGCD".
int computeGCD(int x, int y) {   // a different implementation, but same signature
    if (y == 0) return x;
    return computeGCD(y, x % y);
}

int daysApart(int n) { return computeGCD(n, 30); }
