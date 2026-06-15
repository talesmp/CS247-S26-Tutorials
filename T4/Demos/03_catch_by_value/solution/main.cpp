#include <iostream>
#include <stdexcept>

int main() {
    try {
        throw std::runtime_error("specific: input file missing");
    } catch (const std::exception& e) {
        std::cout << e.what() << '\n';
    }
    return 0;
}
