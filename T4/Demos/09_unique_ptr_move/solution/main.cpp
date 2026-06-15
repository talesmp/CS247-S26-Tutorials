// Topic: unique_ptr ownership
// Q9.2: unique_ptr ownership From solution/main.cpp, shown. That line prints:
//   a) `p set`
//   b) `p null`
//   c) compiler error
//   d) undefined behavior

#include <iostream>
#include <memory>

int main() {
    auto p = std::make_unique<int>(10);
    auto q = std::move(p);
    std::cout << (p ? "p set" : "p null") << '\n';
    std::cout << (q ? "q set" : "q null") << '\n';
    std::cout << *q << '\n';
    return 0;
}
