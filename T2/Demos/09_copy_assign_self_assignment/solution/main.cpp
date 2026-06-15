#include <iostream>

struct Buffer {
    int* data_;
    Buffer(int v) : data_{new int{v}} {}
    Buffer(const Buffer& o) : data_{new int{*o.data_}} {}
    ~Buffer() { delete data_; }

    Buffer& operator=(const Buffer& o) {
        if (this == &o) return *this;   // self-assignment guard
        delete data_;
        data_ = new int{*o.data_};
        return *this;
    }
};

int main() {
    Buffer a{10};
    a = a;                              // now a no-op; a is untouched
    std::cout << *a.data_ << '\n';      // prints 10
}
