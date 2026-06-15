// Answer: compiles; the second print is 1 2 3 99 -- const_cast on a non-const object legally mutates it.

// "immutable by convention" isn't immutable by law. 
// view() hands out a const vector&; the caller const_casts it away and push_back's
// The snapshot really mutates (second print: 1 2 3 99). 
// Legal here, NOT UB, because `s` was born non-const. 
// (Born const => UB; see pitfall_const_object/.)
// Fix: return a copy, not a handle (../solution).
#include <iostream>
#include <vector>

class Snapshot {
    std::vector<int> data_;
public:
    Snapshot(std::vector<int> d) : data_{std::move(d)} {}
    const std::vector<int>& view() const { return data_; }   // leaks a handle to data_
};

void print(const Snapshot& s) {
    for (int x : s.view()) std::cout << x << ' ';
    std::cout << '\n';
}

int main() {
    Snapshot s{{1, 2, 3}};
    print(s);                                                  // 1 2 3
    const_cast<std::vector<int>&>(s.view()).push_back(99);     // legal here; mutates s
    print(s);                                                  // 1 2 3 99
}
