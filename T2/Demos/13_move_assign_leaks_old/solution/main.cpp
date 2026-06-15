#include <iostream>
#include <utility>

class V {
public:
    int* data_;
    V(int x) : data_{new int{x}} {}
    V(V&& o) noexcept : data_{o.data_} { o.data_ = nullptr; }
    V& operator=(V&& o) noexcept {
        if (this == &o) return *this;   // self-move guard
        delete data_;                   // free the receiver's old resource first
        data_ = o.data_;                // take ownership of o's resource
        o.data_ = nullptr;              // leave o safe to destroy
        return *this;
    }
    ~V() { delete data_; }
};

int main() {
    V a{1};
    V b{2};
    a = std::move(b);           // a's int{1} is deleted; a takes b's int{2}
    std::cout << *a.data_ << '\n';   // prints 2, no leak
}
