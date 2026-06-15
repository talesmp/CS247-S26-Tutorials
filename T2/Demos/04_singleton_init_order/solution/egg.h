#ifndef EGG_H
#define EGG_H
#include <iostream>

// Meyers singleton: a function-local static, built exactly once on first call (thread-safe since C++11). 
// No cross-TU race, so no A.cpp definition needed.
class Egg {
    int v_;
    Egg(int v) : v_{v} { std::cout << "Egg ctor " << v << '\n'; }
public:
    Egg(const Egg&) = delete;
    static Egg* instance() {
        static Egg instance_{42};   // built on first call, deterministically
        return &instance_;
    }
    int val() const { return v_; }
    void setVal(int v) { v_ = v; }
};

#endif
