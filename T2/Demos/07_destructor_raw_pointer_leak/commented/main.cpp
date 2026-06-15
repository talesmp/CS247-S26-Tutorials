// Answer: Zero. Holder's implicit dtor drops the raw pointer without deleting *p_, so the heap C leaks (C dtor never prints).

// The implicit dtor does NOT delete what a raw pointer points to. 
// Holder new's a C into raw p_ but declares no dtor; the generated ~Holder() just drops the address, so the heap C is never freed. 
// Output is "C ctor" with no "C dtor" => that missing line is the leak (also caught by valgrind/ASan on Linux).
// Fix: hold it in unique_ptr<C> (solution/).
#include <iostream>

class C {
public:
    C()  { std::cout << "C ctor\n"; }
    ~C() { std::cout << "C dtor\n"; }
};

class Holder {
    C* p_;                       // raw OWNING pointer -> not cleaned up for you
public:
    Holder() : p_{new C()} {}
    // implicit ~Holder() drops p_ but never deletes *p_
};

int main() {
    { Holder h; }                // prints "C ctor" only; the C leaks
}
