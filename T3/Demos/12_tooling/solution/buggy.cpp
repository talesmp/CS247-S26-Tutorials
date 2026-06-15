#include <iostream>

int* findFirst(int* arr, int n, int target) {
    for (int i = 0; i < n; ++i)
        if (arr[i] == target)
            return &arr[i];
    return nullptr;
}

int main() {
    const int n = 5;
    int* data = new int[n];
    for (int i = 0; i < n; ++i)
        data[i] = i * 2;

    int* found = findFirst(data, n, 7);
    if (found)                                       // FIX 1 (gdb): handle "not found"
        std::cout << "found value: " << *found << "\n";
    else
        std::cout << "7 not found\n";

    delete[] data;                                   // FIX 2 (valgrind): free the array
    return 0;
}
