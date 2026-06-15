#include "rational.h"

// Anonymous namespace -> internal linkage. This computeGCD is private to
// rational.cc and is invisible to the linker outside this translation unit.
namespace {
    int computeGCD(int a, int b) {
        while (b) { int t = b; b = a % b; a = t; }
        return a;
    }
}

int reduce(int n) { return computeGCD(n, 100); }
