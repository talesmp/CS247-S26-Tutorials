// PITFALL: same const_cast trick, but now it's real UB. 
// The only change from clean/ is `const Snapshot s`.
// The object is born const, so writing through a const_cast is undefined (const objects may live in read-only memory). 
// May "work" on one machine, crash on another. Legality hinges on how `s` was born.
#include <iostream>
#include <vector>

class Snapshot {
    std::vector<int> data_;
public:
    Snapshot(std::vector<int> d) : data_{std::move(d)} {}
    const std::vector<int>& view() const { return data_; }
};

void print(const Snapshot& s) {
    for (int x : s.view()) std::cout << x << ' ';
    std::cout << '\n';
}

int main() {
    const Snapshot s{{1, 2, 3}};                               // <- born const
    print(s);
    const_cast<std::vector<int>&>(s.view()).push_back(99);     // UNDEFINED BEHAVIOR
    print(s);
}
