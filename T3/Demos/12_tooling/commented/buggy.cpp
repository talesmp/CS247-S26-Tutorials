// Answer (Q12.1): Upstream: the caller never checked that `findFirst` returned `nullptr`
// -- 7 isn't in {0,2,4,6,8}, so findFirst correctly returns nullptr, and main went ahead
// and dereferenced it. The crash site is where it manifests; the bug is the unchecked
// return. gdb shows where it died; bt + print walk you back to why.
// Answer (Q13.1): No, for `data` is leaked (`new[]` with no `delete[]`) => it never
// crashes -- "Runs fine" and "correct" are different claims. valgrind reports 20 bytes in
// 1 blocks are definitely lost … by main (buggy.cpp:12). The leak produces correct output
// and exit 0, so it's invisible without a tool. That's why valgrind exists. P.S.:
// valgrind runs on the Linux servers, not macOS

#include <iostream>

// Returns a pointer to the first element equal to target, or nullptr if absent.
int* findFirst(int* arr, int n, int target) {
    for (int i = 0; i < n; ++i)
        if (arr[i] == target)
            return &arr[i];
    return nullptr;                 // target not found
}

int main() {
    const int n = 5;
    int* data = new int[n];
    for (int i = 0; i < n; ++i)
        data[i] = i * 2;            // 0, 2, 4, 6, 8

    int* found = findFirst(data, n, 7);              // 7 is NOT present -> returns nullptr
    std::cout << "found value: " << *found << "\n";  // BUG 1: dereference nullptr -> CRASH

    // BUG 2: 'data' is never deleted -> memory leak (valgrind: "definitely lost")
    return 0;
}
