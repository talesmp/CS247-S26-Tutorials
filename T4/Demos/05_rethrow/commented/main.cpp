// Answer (Q5.1): `inner`, then the program terminates (uncaught `Base`). 
// `throw e;` throws a copy of static type Base — slicing the Derived away. 
// The outer catch (Derived&) no longer matches, so the Base is uncaught → std::terminate. 
// A bare `throw;` would preserve the dynamic type → inner / outer.

// To forward the exception to be caught, use `throw;`, never `throw e;`. 
// Inside the handler `throw e;` throws a COPY of e's STATIC type. 
// We caught through Base&, so it slices Derived to Base; the outer catch(Derived&) no longer matches => the sliced Base escapes main -> std::terminate.
#include <iostream>

struct Base   { virtual ~Base() = default; };
struct Derived : Base {};

void f() { throw Derived(); }

int main() {
    try {
        try {
            f();                       // throws a Derived
        } catch (Base& e) {            // matches (Derived IS-A Base)
            std::cout << "inner\n";
            throw e;                   // BUG: throws a sliced copy of static type Base
        }
    } catch (Derived&) {               // no longer matches the sliced Base
        std::cout << "outer\n";
    }
}
// Prints "inner", then terminates (uncaught Base).
// Fix: a bare `throw;` keeps the dynamic type -> inner / outer (solution/).
