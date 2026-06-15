// Topic: unique_ptr ownership
// Q9.1: unique_ptr ownership The whole of clean/main.cpp is shown. What happens?
//   a) prints `10`
//   b) prints `10`, but `p` is now null
//   c) compiler error — `unique_ptr`'s copy constructor is deleted
//   d) runtime crash (double free)

#include <iostream>
#include <memory>

int main() {
    auto p = std::make_unique<int>(10);
    auto q = p;
    std::cout << *q << '\n';
    return 0;
}
