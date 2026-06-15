// Topic: Tooling
// Q12.1: gdb stops at the marked line and print found shows 0x0. Where is the bug?
//   a) The marked line: dereferencing a pointer is inherently unsafe
//   b) Upstream: the caller never checked that `findFirst` returned `nullptr`
//   c) Inside gdb
//   d) In the Standard Library
// Q13.1: clean/buggy.cpp allocates and never frees. Suppose the earlier crash is fixed so
// the program prints its answer and exits 0, and all your tests pass. Is it definitely
// free of memory bugs?
//   a) Yes, for it ran fine and exited 0
//   b) Only on Linux
//   c) Only if you forgot `-Wall`
//   d) No, for `data` is leaked (`new[]` with no `delete[]`) => it never crashes
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
    std::cout << "found value: " << *found << "\n";  // <-- crashes here

    return 0;
}

