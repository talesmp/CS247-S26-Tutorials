#include <iostream>
#include <utility>

class Widget {
    int* data_;
public:
    Widget(int v) : data_{new int{v}} {}
    Widget(const Widget& o) : data_{new int{*o.data_}} { std::cout << "copy\n"; }
    Widget(Widget&& o) noexcept : data_{o.data_} { o.data_ = nullptr; std::cout << "move\n"; }
    ~Widget() { delete data_; }

    // Canonical copy-and-swap: take the parameter BY VALUE. 
    // The compiler copies or moves into `other` depending on the argument's value category, so this one operator handles BOTH copy- and move-assignment.
    Widget& operator=(Widget other) {
        std::swap(data_, other.data_);
        return *this;
    }
};

int main() {
    Widget a{1}, b{2}, c{3};
    std::cout << "-- a = b (lvalue):\n";
    a = b;                  // copy  (other is copy-constructed from b)
    std::cout << "-- a = std::move(c) (rvalue):\n";
    a = std::move(c);       // move  (other is move-constructed from c)
}
