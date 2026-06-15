#include <iostream>
#include <stdexcept>

int main() {
    try {
        throw std::runtime_error("boom");
    } catch (const std::runtime_error& e) {
        std::cout << "runtime handler\n";
    } catch (const std::exception& e) {
        std::cout << "general handler\n";
    }
    return 0;
}
