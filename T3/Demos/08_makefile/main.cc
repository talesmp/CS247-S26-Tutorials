#include <iostream>
#include "vec.h"

int main() {
    Vec a{1, 2};
    Vec b{3, 4};
    Vec c = a + b;
    std::cout << "(" << c.x << ", " << c.y << ")\n";
    return 0;
}
