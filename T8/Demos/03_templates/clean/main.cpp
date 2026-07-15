#include "array.h"
#include <iostream>

int main() {
    int data[] = {1, 2, 3, 4};
    Array<int> a(4, data);
    std::cout << "sum = " << a.sum() << '\n';
}
