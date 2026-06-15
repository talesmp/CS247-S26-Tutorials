// Topic: Specificand set
// Q11.1: findA from find.cpp What happens?
//   a) Returns 0
//   b) Returns 1
//   c) Returns 5 (the size)
//   d) Undefined behavior => it reads past the end (garbage or a crash)
// Q11.2: (Conceptual) The three real implementations in find.cpp: A = first match (UB if
// absent) B = first match, else -1 C = last match, else v.size(). The spec says: "return
// an index of val; return -1 if absent." Which implementations satisfy it?
//   a) A and B
//   b) Only B
//   c) B and C
//   d) A, B and C
#include <iostream>
#include <vector>
using std::vector;

// first match, no sentinel, UB if not found
int findA(const vector<int> &v, int val) {
    int i = 0;
    while (v[i] != val) ++i;
    return i;
}

// smallest index, sentinel -1 if not found
int findB(const vector<int> &v, int val) {
    for (int i = 0; i < static_cast<int>(v.size()); ++i)
        if (v[i] == val) return i;
    return -1;
}

// largest index, sentinel v.size() if not found
int findC(const vector<int> &v, int val) {
    for (int i = static_cast<int>(v.size()) - 1; i >= 0; --i)
        if (v[i] == val) return i;
    return static_cast<int>(v.size());
}

int main() {
    vector<int> v{10, 20, 30, 20, 10};
    std::cout << "vector: 10 20 30 20 10  (size 5)\n\n";

    std::cout << "find 20 (PRESENT):\n";
    std::cout << "  A = " << findA(v, 20) << "   first match\n";
    std::cout << "  B = " << findB(v, 20) << "   smallest index\n";
    std::cout << "  C = " << findC(v, 20) << "   largest index\n";

    std::cout << "\nfind 99 (ABSENT):\n";
    std::cout << "  B = " << findB(v, 99) << "   sentinel -1\n";
    std::cout << "  C = " << findC(v, 99) << "   sentinel v.size()\n";
    std::cout << "  A = " << std::flush;
    std::cout << findA(v, 99) << "   <- UB: garbage index or a crash\n";
    return 0;
}
