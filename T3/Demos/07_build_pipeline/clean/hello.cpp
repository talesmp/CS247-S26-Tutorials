// Topic: Build pipeline
// Q6.1: hello.cpp uses std::cout, whose definition lives in the standard library, not in
// hello.cpp. Is `g++ -c hello.cpp` successful (producing hello.o)?
//   a) No, undefined reference to `std::cout`
//   b) Yes, `-c` compiles+assembles only; library symbols are resolved later, at link
//   c) Compiler error
//   d) Needs extra flags
#include <iostream>

#define GREETING "Hello, CS247"

int main() {
    std::cout << GREETING << "\n";
    return 0;
}

