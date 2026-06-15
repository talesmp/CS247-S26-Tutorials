// Answer: 42 OR 100 -- static-init order across A.cpp/B.cpp is unspecified (link-order dependent).

// The static-init-order fiasco.
// instance_ is defined in A.cpp; B.cpp's static Initializer calls setVal(100) at startup. 
// Init order across TUs is unspecified (link-order dependent):
//   A first -> ctor(42), then setVal(100) -> prints 100
//   B first -> setVal(100) on a zero-init Egg, then A's ctor overwrites with 42 -> 42
// Fix: Meyers singleton (function-local static), built once on first use (solution/).
#ifndef EGG_H
#define EGG_H
#include <iostream>

class Egg {
    static Egg instance_;                                       // defined in A.cpp
    int v_;
    Egg(int v) : v_{v} { std::cout << "Egg ctor " << v << '\n'; }
public:
    Egg(const Egg&) = delete;
    static Egg* instance() { return &instance_; }
    int val() const { return v_; }
    void setVal(int v) { v_ = v; }
};

#endif
