// Topic: Member Initialization List (MIL)
// What is the value of `result_` after `Tricky t(5)`?
#include <iostream>

class Tricky {
    int result_;
    int base_;
public:
    Tricky(int b) : base_{b}, result_{base_ * 2} {}
    int result() const { return result_; }
    int base() const { return base_; }
};

int main() {
    Tricky t(5);
    std::cout << "result_ = " << t.result() << "\n";
    std::cout << "base_   = " << t.base() << "\n";
}
