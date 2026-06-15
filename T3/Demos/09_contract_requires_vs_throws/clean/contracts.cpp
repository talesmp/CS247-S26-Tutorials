// Topic: Contracts
// Q9.1: What happens regarding quotientPre?
//   a) Prints `0`
//   b) Always crashes
//   c) It depends on the machine
//   d) Compiler error
// Q9.2: What happens regarding indexOf? Assume it compiles (with a warning) and runs. The
// most likely result:
//   a) A garbage number, and it may look plausible
//   b) -1
//   c) It throws
//   d) Always crashes
#include <iostream>
#include <vector>
#include <stdexcept>

struct DivideByZero : std::runtime_error {
    DivideByZero() : std::runtime_error("DivideByZero") {}
};

double quotientThrow(int numerator, int denominator) {
    if (denominator == 0) throw DivideByZero{};
    return static_cast<double>(numerator) / denominator;
}

double quotientChecked(int numerator, int denominator) {
    if (denominator == 0)
        throw std::domain_error("precondition violated: denominator == 0");
    return static_cast<double>(numerator) / denominator;
}

int quotientPre(int numerator, int denominator) {  
    return numerator / denominator;
}

int indexOf(const std::vector<int> &v, int oldElem) {
    for (int i = 0; i < static_cast<int>(v.size()); ++i)
        if (v[i] == oldElem) return i;
}

int main() {
    std::cout << "=== throws-design: the bad case is handled (in-contract) ===\n";
    try {
        std::cout << "quotientThrow(10, 2) = " << quotientThrow(10, 2) << "\n";
        std::cout << "quotientThrow(10, 0) = " << quotientThrow(10, 0) << "\n";
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
    int q = quotientPre(10, 0);
    std::cout << "quotientPre(10, 0) = " << q
              << "   <- if you SEE this, your CPU didn't trap it (still UB!)\n";

    std::cout << "\n=== precondition VIOLATED, flavor 3: a reliable crash ===\n";
    std::cout << "dereferencing a null pointer...\n" << std::flush;
    int *p = nullptr;
    std::cout << *p << "\n";
    std::cout << "you will NEVER see this line\n";
    return 0;
}
