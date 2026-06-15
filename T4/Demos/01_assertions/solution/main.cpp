#include <cassert>
#include <iostream>

int main() {
    int i = 10;
    assert(i == 10);
    ++i;
    std::cout << "i = " << i << '\n';
    return 0;
}
