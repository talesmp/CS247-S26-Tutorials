// Answer: garbage -- members init in DECLARATION order, so result_{base_*2} runs before base_ is set (UB).

#include <iostream>

class Tricky {
    // Members init in DECLARATION order, not MIL order. Here that's result_ then base_ -- so result_{base_ * 2} runs while base_ is still garbage (UB).
    int result_;
    int base_;
public:
    Tricky(int b) : base_{b}, result_{base_ * 2} {}   // MIL order is a red herring
    int result() const { return result_; }
    int base() const { return base_; }
};

int main() {
    Tricky t(5);
    std::cout << "result_ = " << t.result() << "\n";  // NOT 10: garbage * 2 (UB)
    std::cout << "base_   = " << t.base() << "\n";     // 5
    // -Wall flags this (-Wreorder). Fix: declare base_ before result_ (../solution).
}
