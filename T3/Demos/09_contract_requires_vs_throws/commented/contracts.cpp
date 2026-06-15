// Answer (Q9.1): It depends on the machine -- Violating a precondition is undefined
// behavior, so literally "anything goes." Integer ÷0 traps on x86 (Linux) but the ARM CPU
// (Apple-Silicon Mac) doesn't, so it returns 0. Same source, different behavior => that
// is UB.
// Answer (Q9.2): A garbage number, and it may look plausible -- Falling off the end of a
// non- void function is UB. It returns whatever was in the register, often a believable
// wrong value. This is worse than a crash. The compiler even warns -Wreturn-type.

#include <iostream>
#include <vector>
#include <stdexcept>

// A custom exception type used by the throws-design.
struct DivideByZero : std::runtime_error {
    DivideByZero() : std::runtime_error("DivideByZero") {}
};

// THROWS design: the bad case is HANDLED -> it is IN-CONTRACT.
// throws:  DivideByZero, if denominator == 0
// returns: numerator / denominator
double quotientThrow(int numerator, int denominator) {
    if (denominator == 0) throw DivideByZero{};
    return static_cast<double>(numerator) / denominator;
}

// Best practice: the precondition is CHEAP to check, so check it and throw.
// This promotes a would-be precondition into a guaranteed throws-case.
double quotientChecked(int numerator, int denominator) {
    if (denominator == 0)
        throw std::domain_error("precondition violated: denominator == 0");
    return static_cast<double>(numerator) / denominator;
}

// PRECONDITION design: the bad case is OUT-OF-CONTRACT.
// requires: denominator != 0   <-- caller's duty. If violated, ANYTHING GOES.
int quotientPre(int numerator, int denominator) {
    return numerator / denominator;   // no check -> UB (crash) when denominator == 0
}

// Another precondition. Here violating it yields SILENT GARBAGE, not a crash.
// requires: oldElem occurs in v
int indexOf(const std::vector<int> &v, int oldElem) {
    for (int i = 0; i < static_cast<int>(v.size()); ++i)
        if (v[i] == oldElem) return i;
    // Precondition says oldElem is present, so "we never get here". If it isn't,
    // we fall off a non-void function -> UB -> garbage return.
}

int main() {
    std::cout << "=== throws-design: the bad case is handled (in-contract) ===\n";
    try {
        std::cout << "quotientThrow(10, 2) = " << quotientThrow(10, 2) << "\n";
        std::cout << "quotientThrow(10, 0) = " << quotientThrow(10, 0) << "\n";  // throws
    } catch (const DivideByZero &e) {
        std::cout << "caught " << e.what() << "  -> defined, recoverable\n";
    }

    std::cout << "\n=== check-and-throw best practice ===\n";
    try {
        std::cout << quotientChecked(10, 0) << "\n";
    } catch (const std::exception &e) {
        std::cout << "caught: " << e.what() << "\n";
    }

    std::vector<int> v{10, 20, 30};
    std::cout << "\n=== precondition respected: indexOf finds a present element ===\n";
    std::cout << "indexOf({10,20,30}, 20) = " << indexOf(v, 20) << "  (correct: 1)\n";

    std::cout << "\n=== precondition VIOLATED, flavor 1: silent garbage ===\n";
    std::cout << "indexOf({10,20,30}, 99) = " << indexOf(v, 99)
              << "  <- garbage; no crash, no error. 'anything goes.'\n";

    std::cout << "\n=== precondition VIOLATED, flavor 2: platform-dependent UB ===\n";
    std::cout << "calling quotientPre(10, 0)...\n" << std::flush;
    int q = quotientPre(10, 0);   // UB: SIGFPE crash on x86/Linux; silently 0 on Apple Silicon
    std::cout << "quotientPre(10, 0) = " << q
              << "   <- if you SEE this, your CPU didn't trap it (still UB!)\n";

    std::cout << "\n=== precondition VIOLATED, flavor 3: a reliable crash ===\n";
    std::cout << "dereferencing a null pointer...\n" << std::flush;
    int *p = nullptr;
    std::cout << *p << "\n";       // UB: segfault on every platform
    std::cout << "you will NEVER see this line\n";
    return 0;
}
