// Topic: Rethrow
// Q5.1: What's the output?
//   a) `inner` then `outer`
//   b) `inner`, then the program terminates (uncaught `Base`)
//   c) `outer` only
//   d) `inner` only, then exits 0

#include <iostream>

struct Base   { virtual ~Base() = default; };
struct Derived : Base {};

void f() { throw Derived(); }

int main() {
    try {
        try {
            f();
        } catch (Base& e) {
            std::cout << "inner\n";
            throw e;
        }
    } catch (Derived&) {
        std::cout << "outer\n";
    }
    return 0;
}


