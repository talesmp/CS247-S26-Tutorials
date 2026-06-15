// Topic: Separate compilation
// Q1.1: class B is declared in ADT1.h and defined in ADT1.cpp. 
// You run `g++ ADT1.cpp main.cpp -o app`. What happens?
//   a) It links and runs, printing `Hi, I am Ada`
//   b) Compiler error: `'B' was not declared
//   c) Linker error: undefined reference to `B`
//   d) It runs, then crashes
#include <iostream>

int main() {
    B *b_obj = new B("Ada");
    std::cout << b_obj->greet() << "\n";
    delete b_obj;
    return 0;
}