// Topic: Assertions
// Q1.1: You build the release way `g++ -std=c++17 -DNDEBUG clean/main.cpp -o app` and run it. 
// It prints:
//   a) `i = 11`
//   b) `i = 10`
//   c) nothing — the assert fails and aborts
//   d) a compiler error

#include <cassert>
#include <iostream>

int main() {
    int i = 10;
    assert(i++ == 10);
    std::cout << "i = " << i << '\n';
    return 0;
}
