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
            throw;
        }
    } catch (Derived&) {
        std::cout << "outer\n";
    }
    return 0;
}
