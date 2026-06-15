#include <iostream>
#include <memory>

class C {
public:
    C()  { std::cout << "C ctor\n"; }
    ~C() { std::cout << "C dtor\n"; }
};

class Holder {
    std::unique_ptr<C> p_;       // self-cleaning: deletes the C on destruction
public:
    Holder() : p_{std::make_unique<C>()} {}
};

int main() {
    { Holder h; }                // prints "C ctor" AND "C dtor"
}
