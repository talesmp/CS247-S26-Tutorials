#include <iostream>
#include <vector>
using std::vector;

// (A) is NOT buggy -- it just has a PRECONDITION: val must be present.
// requires: val occurs in v
// Used within its precondition it is correct AND the simplest/fastest (no bound
// check). This is why a precondition can enable a faster implementation.
int findA(const vector<int> &v, int val) {
    int i = 0;
    while (v[i] != val) ++i;
    return i;
}

// If you cannot guarantee presence, DEFINE the absent case. Hardening A this way
// turns it into implementation (B): returns -1 when absent.
int findASafe(const vector<int> &v, int val) {
    for (int i = 0; i < static_cast<int>(v.size()); ++i)
        if (v[i] == val) return i;
    return -1;
}

int findC(const vector<int> &v, int val) {
    for (int i = static_cast<int>(v.size()) - 1; i >= 0; --i)
        if (v[i] == val) return i;
    return static_cast<int>(v.size());
}

int main() {
    vector<int> v{10, 20, 30, 20, 10};

    // A used WITHIN its precondition (20 is present): safe and correct.
    std::cout << "findA(20)     = " << findA(v, 20) << "   (precondition respected)\n";

    // For the absent case, use a function whose spec DEFINES it:
    std::cout << "findASafe(99) = " << findASafe(v, 99) << "   (-1)\n";
    std::cout << "findC(99)     = " << findC(v, 99) << "   (size = 5)\n";
    std::cout << "no UB, no crash.\n";
    return 0;
}
