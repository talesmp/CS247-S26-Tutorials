// Answer (Q11.1): Undefined behavior => it reads past the end (garbage or a crash) -- No
// bound check + absent value + i walks off the end => UB. findA is correct only under its
// precondition "val is present", which is exactly how a precondition can buy a faster
// (no-bounds-check) implementation.
// Answer (Q11.2): Only B -- A is UB when absent (excluded); C returns size, not -1
// (excluded). Only B conforms. A tighter spec => a smaller "specificand set."

#include <iostream>
#include <vector>
using std::vector;

// Three implementations of "find val in v" -- each conforms to a DIFFERENT spec.

// (A) forward, returns the FIRST match; if val is absent it runs off the end.
int findA(const vector<int> &v, int val) {
    int i = 0;
    while (v[i] != val) ++i;     // val absent -> i runs past the end -> UNDEFINED
    return i;
}

// (B) forward, returns the FIRST (smallest-index) match; -1 if absent.
int findB(const vector<int> &v, int val) {
    for (int i = 0; i < static_cast<int>(v.size()); ++i)
        if (v[i] == val) return i;
    return -1;
}

// (C) backward, returns the LAST (largest-index) match; v.size() if absent.
int findC(const vector<int> &v, int val) {
    for (int i = static_cast<int>(v.size()) - 1; i >= 0; --i)
        if (v[i] == val) return i;
    return static_cast<int>(v.size());
}

int main() {
    vector<int> v{10, 20, 30, 20, 10};   // 20 and 10 each appear twice
    std::cout << "vector: 10 20 30 20 10  (size 5)\n\n";

    std::cout << "find 20 (PRESENT):\n";
    std::cout << "  A = " << findA(v, 20) << "   first match\n";    // 1
    std::cout << "  B = " << findB(v, 20) << "   smallest index\n"; // 1
    std::cout << "  C = " << findC(v, 20) << "   largest index\n";  // 3

    std::cout << "\nfind 99 (ABSENT):\n";
    std::cout << "  B = " << findB(v, 99) << "   sentinel -1\n";          // -1
    std::cout << "  C = " << findC(v, 99) << "   sentinel v.size()\n";    // 5
    std::cout << "  A = " << std::flush;                                  // flush good output first
    std::cout << findA(v, 99) << "   <- UB: garbage index or a crash\n";  // UNDEFINED
    return 0;
}
