// Answer: the user-declared ~Big() suppresses the implicit move ctor, so push_back(Big{}) falls back to copying.

// A user-declared destructor suppresses the implicit move ctor. 
// Big{} is an rvalue that should move into the vector, but `~Big(){}` exists.
// So no move ctor is generated and push_back falls back to the copy ctor (the 1000-element vector is copied). 
// Output: copy, copy. It's the act of declaring ~Big() that disables the move, even empty. 
// Fix: add a move ctor or `~Big() = default`.
#include <iostream>
#include <vector>

class Big {
    std::vector<int> data_;
public:
    Big() : data_(1000) {}
    Big(const Big& o) : data_{o.data_} { std::cout << "copy\n"; }
    ~Big() {}    // user-declared dtor -> implicit move ctor is SUPPRESSED
};

int main() {
    std::vector<Big> v;
    v.reserve(2);
    v.push_back(Big{});   // copy (no move ctor available)
    v.push_back(Big{});   // copy
}
