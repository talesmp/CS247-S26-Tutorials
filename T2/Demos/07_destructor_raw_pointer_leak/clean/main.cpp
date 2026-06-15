// Topic: Destructor
// How many C destructors run by the time main returns?
#include <iostream>

class C {
public:
    C()  { std::cout << "C ctor\n"; }
    ~C() { std::cout << "C dtor\n"; }
};

class Holder {
    C* p_;
public:
    Holder() : p_{new C()} {}
};

int main() {
    { Holder h; }
}
