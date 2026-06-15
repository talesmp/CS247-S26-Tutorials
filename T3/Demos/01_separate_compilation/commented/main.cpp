// Answer (Q1.1): Compiler error
// `'B' was not declared -- Each file compiles alone;
// main.cpp never sees ADT1.cpp, so the compiler hits B with no declaration. 
// It never reaches the linker. 
// Fix: #include "ADT1.h".

// BROKEN. Separate compilation processes this file alone, and there's no #include "ADT1.h" => so the compiler reaches B never having heard of it.
#include <iostream>

int main() {
    B *b_obj = new B("Ada");      // ERROR: B is not declared in this scope
    std::cout << b_obj->greet() << "\n";
    delete b_obj;
    return 0;
}
