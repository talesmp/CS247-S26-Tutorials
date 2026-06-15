// Answer (Q3.1): Compiler error: redefinition of `class Widget` -- widget.h reaches
// main.cpp along two paths, so class Widget is defined twice in one translation unit. A
// guard (#ifndef WIDGET_H …) fixes it.

// Two include paths both bring in widget.h:
#include "widget.h"   // path 1: widget.h pasted here directly
#include "panel.h"    // path 2: panel.h ALSO pastes widget.h
                      //         -> class Widget is now defined TWICE in this TU
#include <iostream>

int main() {
    Panel p;
    std::cout << p.inner().label() << "\n";
    return 0;
}
