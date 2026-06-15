#include "date.h"

// Also wrapped in an anonymous namespace -> this computeGCD is private to
// date.cc. The two definitions no longer collide; each file keeps its own.
namespace {
    int computeGCD(int x, int y) {
        if (y == 0) return x;
        return computeGCD(y, x % y);
    }
}

int daysApart(int n) { return computeGCD(n, 30); }
