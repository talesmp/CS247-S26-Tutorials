#include <iostream>
#include "ADT1.h"   // FIX: include the INTERFACE so the compiler knows what B is.

int main() {
    B *b_obj = new B("Ada");
    std::cout << b_obj->greet() << "\n";
    delete b_obj;
    return 0;
}
