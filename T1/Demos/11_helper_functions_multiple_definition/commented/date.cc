#include "date.h"

// Same global name "computeGCD" as rational.cc. Each file compiles alone; the
// clash only surfaces at link time.
int computeGCD(int x, int y) {
    if (y == 0) return x;
    return computeGCD(y, x % y);
}

int daysApart(int n) { return computeGCD(n, 30); }
