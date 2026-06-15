#include <iostream>
#include <utility>
#include <vector>

class Big {
    std::vector<int> data_;
public:
    Big() : data_(1000) {}
    Big(const Big& o) : data_{o.data_} { std::cout << "copy\n"; }
    Big(Big&& o) noexcept : data_{std::move(o.data_)} { std::cout << "move\n"; }  // restore moves
    ~Big() = default;   // defaulted dtor doesn't suppress, and the move ctor is explicit anyway
};

int main() {
    std::vector<Big> v;
    v.reserve(2);
    v.push_back(Big{});   // move
    v.push_back(Big{});   // move
}
