#include <iostream>

struct Vec {
    Vec()               { std::cout << "default\n"; }
    Vec(const Vec&)     { std::cout << "copy\n"; }
    Vec(Vec&&) noexcept { std::cout << "move\n"; }
};

Vec makeVec() {
    Vec local;
    return local;        // NRVO: local is built directly in the caller's v
}

int main() {
    Vec v = makeVec();   // prints: default   (no copy, no move)
    (void)v;
}
