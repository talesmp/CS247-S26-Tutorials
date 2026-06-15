// Answer (Q6.1): `ctor 0/1/2` · `dtor 1/0` · `caught: boom`.
// c throws mid-construction, so it was never fully built => its destructor is skipped (no dtor 2). 
// The finished locals b, a unwind in reverse; d never starts. 
// The trap is assuming c 's destructor runs.

// Exceptions during construction (observation demo). 
// A destructor is teardown for a FULLY BUILT object: one whose ctor threw was never built, so its dtor is skipped. 
// Every object that DID finish is destroyed in reverse order as the stack unwinds.
#include <iostream>
#include <stdexcept>

struct W {
    int id;
    W(int i) : id(i) {
        std::cout << "ctor " << id << '\n';
        if (id == 2) throw std::runtime_error("boom");   // #2 throws mid-construction
    }
    ~W() { std::cout << "dtor " << id << '\n'; }
};

int main() {
    try {
        W a(0);   // fully built
        W b(1);   // fully built
        W c(2);   // prints "ctor 2", then throws -> NEVER fully built -> no ~W
        W d(3);   // never reached
    } catch (const std::exception& e) {
        std::cout << "caught: " << e.what() << '\n';
    }
    return 0;
}
// Output:
//   ctor 0
//   ctor 1
//   ctor 2          <- c starts, throws; c's destructor is SKIPPED
//   dtor 1          <- unwinding destroys the completed locals, reverse order
//   dtor 0
//   caught: boom
