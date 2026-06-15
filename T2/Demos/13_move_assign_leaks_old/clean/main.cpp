// Topic: Move Assignment
// What is the value of *a.data_ at the end?
#include <iostream>
#include <utility>

class V {
public:
    int* data_;
    V(int x) : data_{new int{x}} {}
    V(V&& o) noexcept : data_{o.data_} { o.data_ = nullptr; }
    V& operator=(V&& o) noexcept {
        data_ = o.data_;
        o.data_ = nullptr;
        return *this;
    }
    ~V() { delete data_; }
};

int main() {
    V a{1};
    V b{2};
    a = std::move(b);
    std::cout << *a.data_ << '\n';
}
