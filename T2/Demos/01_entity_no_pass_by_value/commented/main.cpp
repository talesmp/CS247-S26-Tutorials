// Answer: No, deleting the copy ctor also suppresses the move ctor, so announce(Passenger) by value has neither -> compile error.

// Copying a Passenger makes no sense, so the copy ctor is delete'd => which also suppresses the implicit move ctor. 
// announce takes its arg by value (needs copy or move); both are gone, so the call won't compile.
// That's "never pass an entity by value", enforced by the compiler.
#include <iostream>
#include <string>

class Passenger {
public:
    std::string name;
    Passenger(std::string n) : name{std::move(n)} {}
    Passenger(const Passenger&) = delete;   // copy forbidden -> move also suppressed
};

void announce(Passenger p) { std::cout << p.name << '\n'; }  // by value: needs copy/move

int main() {
    Passenger alice{"Alice"};
    announce(std::move(alice));   // ERROR: no move ctor, copy ctor deleted
    // Fix: take const Passenger& (../solution).
}
