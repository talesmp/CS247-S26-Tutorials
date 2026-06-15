// Topic: Move Constructor
// Why is the move constructor never called?
#include <iostream>
#include <vector>

class Big {
    std::vector<int> data_;
public:
    Big() : data_(1000) {}
    Big(const Big& o) : data_{o.data_} { std::cout << "copy\n"; }
    ~Big() {}
};

int main() {
    std::vector<Big> v;
    v.reserve(2);
    v.push_back(Big{});
    v.push_back(Big{});
}
