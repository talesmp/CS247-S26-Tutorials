#include <iostream>

#define SQUARE(x) x * x

int main() {
    std::cout << "SQUARE(2 + 3) = " << SQUARE(2 + 3) << "   (expected 25)\n";

#ifdef VERBOSE
    std::cout << "[verbose] this line was kept because VERBOSE is defined\n";
#endif
    return 0;
}
