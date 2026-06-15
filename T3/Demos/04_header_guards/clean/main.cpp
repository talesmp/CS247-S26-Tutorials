// Topic: Header guards
// Q3.1: widget.h has no include guard, and main.cpp includes it both directly and via
// panel.h (which also includes widget.h). What's the result of `g++ main.cpp -o app`?
//   a) It runs and prints `widget`
//   b) Linker error
//   c) Compiler error: redefinition of `class Widget`

#include "widget.h"
#include "panel.h"
#include <iostream>

int main() {
    Panel p;
    std::cout << p.inner().label() << "\n";
    return 0;
}
