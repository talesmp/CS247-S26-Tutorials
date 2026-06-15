// Topic: Copy-Swap Idiom
// Does this operator= correctly implement copy-and-swap?
#include <iostream>
#include <utility>

class Widget {
    int* data_;
public:
    Widget(int v) : data_{new int{v}} {}
    Widget(const Widget& o) : data_{new int{*o.data_}} { std::cout << "copy\n"; }
    Widget(Widget&& o) noexcept : data_{o.data_} { o.data_ = nullptr; std::cout << "move\n"; }
    ~Widget() { delete data_; }

    Widget& operator=(const Widget& other) {
        Widget tmp{other};
        std::swap(data_, tmp.data_);
        return *this;
    }
};

int main() {
    Widget a{1}, b{2}, c{3};
    std::cout << "-- a = b (lvalue):\n";
    a = b;
    std::cout << "-- a = std::move(c) (rvalue):\n";
    a = std::move(c);
}
