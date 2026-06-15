// Topic: Singleton Design Pattern
// What is the value of Egg::instance()->val() printed at the end?
// Build with `g++ -std=c++17 clean/*.cpp -o app`  => then swap file order to flip the result
#ifndef EGG_H
#define EGG_H
#include <iostream>

class Egg {
    static Egg instance_;
    int v_;
    Egg(int v) : v_{v} { std::cout << "Egg ctor " << v << '\n'; }
public:
    Egg(const Egg&) = delete;
    static Egg* instance() { return &instance_; }
    int val() const { return v_; }
    void setVal(int v) { v_ = v; }
};

#endif
