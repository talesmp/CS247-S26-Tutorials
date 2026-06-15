#include <iostream>
#include <vector>
#include <stdexcept>

// The DISCIPLINED version. Same functions, but now the program either HANDLES
// the bad case (throws) or RESPECTS the precondition (never calls with bad input).
// It runs cleanly to the end -- no garbage, no crash.

struct DivideByZero : std::runtime_error {
    DivideByZero() : std::runtime_error("DivideByZero") {}
};

// throws:  DivideByZero, if denominator == 0     (in-contract)
double quotientThrow(int numerator, int denominator) {
    if (denominator == 0) throw DivideByZero{};
    return static_cast<double>(numerator) / denominator;
}

// requires: oldElem occurs in v   (we will honor this -> safe)
int indexOf(const std::vector<int> &v, int oldElem) {
    for (int i = 0; i < static_cast<int>(v.size()); ++i)
        if (v[i] == oldElem) return i;
    return -1;   // hardened: if you can't guarantee the precondition, define the
                 // absent case (this turns a precondition into a throws/sentinel design)
}

int main() {
    // Bad case handled via the throws-design:
    try {
        std::cout << "10 / 2 = " << quotientThrow(10, 2) << "\n";
        std::cout << "10 / 0 = " << quotientThrow(10, 0) << "\n";
    } catch (const DivideByZero &e) {
        std::cout << "caught " << e.what() << " (handled)\n";
    }

    // Precondition respected: we only ask for elements we know are present.
    std::vector<int> v{10, 20, 30};
    std::cout << "indexOf(20) = " << indexOf(v, 20) << "\n";

    // And because we HARDENED indexOf, even the absent case is now defined:
    std::cout << "indexOf(99) = " << indexOf(v, 99) << " (defined: -1)\n";

    std::cout << "reached the end cleanly: no garbage, no crash.\n";
    return 0;
}
