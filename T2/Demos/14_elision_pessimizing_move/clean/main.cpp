// Topic: Copy/Move Elision
// Which constructors run when v is initialized?
#include <iostream>
#include <utility>

struct Vec {
    Vec()               { std::cout << "default\n"; }
    Vec(const Vec&)     { std::cout << "copy\n"; }
    Vec(Vec&&) noexcept { std::cout << "move\n"; }
};

Vec makeVec() {
    Vec local;
    return std::move(local);
}

int main() {
    Vec v = makeVec();
    (void)v;
}
