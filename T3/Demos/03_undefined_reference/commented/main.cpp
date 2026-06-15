// Answer (Q7.1): Linker error: undefined reference to `square(int)` -- The code is
// flawless, but mathutil.cpp isn't on the command line, so the definition never reaches
// the linker. undefined reference is usually a build mistake, not a code bug. Fix: g++
// main.cpp mathutil.cpp -o app.

#include <iostream>
#include "mathutil.h"

// NOTE: this code is 100% CORRECT. The "bug" in this demo is the BUILD COMMAND.
// If you compile/link main.cpp WITHOUT mathutil.cpp, the linker has a "need
// square" wire with no matching "provide" -> undefined reference.

int main() {
    std::cout << "7^2 = " << square(7) << "\n";
    return 0;
}
