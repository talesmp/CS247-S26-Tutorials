#include <iostream>

class Tricky {
    // Declare base_ FIRST so it is initialised before result_ depends on it.
    int base_;
    int result_;
public:
    Tricky(int b) : base_{b}, result_{base_ * 2} {}
    int result() const { return result_; }
    int base() const { return base_; }
};

int main() {
    Tricky t(5);
    std::cout << "result_ = " << t.result() << "\n";  // 10
    std::cout << "base_   = " << t.base() << "\n";     // 5
}
