// Topic: Handler order
// Q4.1: What happens when you run it?
//   a) prints `runtime handler` (the most specific match)
//   b) compiles with a warning, then prints `general handler`
//   c) prints both lines
//   d) hard compiler error (not just a warning)

#include <iostream>
#include <stdexcept>

int main() {
    try {
        throw std::runtime_error("boom");
    } catch (const std::exception& e) {
        std::cout << "general handler\n";
    } catch (const std::runtime_error& e) {
        std::cout << "runtime handler\n";
    }
    return 0;
}

