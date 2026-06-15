// Answer: default + move => `return std::move(local)` blocks NRVO (a pessimizing move). `return local` would print just default.

// `return std::move(local)` is a pessimization => it disables NRVO. 
// `return local` lets the compiler build local directly in the caller's v (just "default"). 
// The std::move makes the return a cast, not a name, so NRVO can't apply and a real move runs: default, move. 
// -Wall warns (-Wpessimizing-move).
// Fix: just `return local;` (check the solution/ folder).
#include <iostream>
#include <utility>

struct Vec {
    Vec()               { std::cout << "default\n"; }
    Vec(const Vec&)     { std::cout << "copy\n"; }
    Vec(Vec&&) noexcept { std::cout << "move\n"; }
};

Vec makeVec() {
    Vec local;
    return std::move(local);   // pessimizing move: blocks NRVO -> forces a move
}

int main() {
    Vec v = makeVec();         // prints: default  then  move
    (void)v;                   // silence the unrelated -Wunused-variable
}
