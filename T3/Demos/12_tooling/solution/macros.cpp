#include <iostream>

#define SQUARE(x) ((x) * (x))             // FIX: parenthesize -> ((2+3)*(2+3)) = 25
constexpr int square(int x) { return x * x; }   // better: a real, type-safe function

int main() {
    std::cout << "SQUARE(2 + 3) = " << SQUARE(2 + 3) << "   (now 25)\n";
    std::cout << "square(2 + 3) = " << square(2 + 3) << "   (type-safe function)\n";
    return 0;
}
