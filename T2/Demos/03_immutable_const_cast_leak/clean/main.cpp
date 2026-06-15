// Topic: Mutable vs. Immutable Objects
// Will this compile? If so, what does the second print show?
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
    Snapshot s{{1, 2, 3}};
    print(s);
    const_cast<std::vector<int>&>(s.view()).push_back(99);
    print(s);
}
