#include <iostream>
#include <stdexcept>

void cleanup() {
    throw std::runtime_error("oops");
}

int main() {
    try {
        cleanup();
    } catch (const std::exception& e) {
        std::cout << "caught: " << e.what() << '\n';
    }
    std::cout << "after\n";
    return 0;
}
