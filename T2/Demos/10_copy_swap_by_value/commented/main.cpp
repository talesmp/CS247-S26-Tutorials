// Answer: it's correct & safe, but the const& param always copies; take the param BY VALUE so an rvalue moves instead.

// This version is CORRECT (exception- and self-assign safe via copy-then-swap) but suboptimal.
// The `const Widget&` parameter means the inner `Widget tmp{other}` always copies, even from an rvalue.
//   const-ref (clean/):   copy , copy
//   by-value (solution/): copy , move   <= operator=(Widget other) moves the rvalue
// One by-value function does both copy- and move-assign. 
#include <iostream>
#include <utility>

class Widget {
    int* data_;
public:
    Widget(int v) : data_{new int{v}} {}
    Widget(const Widget& o) : data_{new int{*o.data_}} { std::cout << "copy\n"; }
    Widget(Widget&& o) noexcept : data_{o.data_} { o.data_ = nullptr; std::cout << "move\n"; }
    ~Widget() { delete data_; }

    Widget& operator=(const Widget& other) {   // const ref -> always copies `other`
        Widget tmp{other};
        std::swap(data_, tmp.data_);
        return *this;
    }
};

int main() {
    Widget a{1}, b{2}, c{3};
    std::cout << "-- a = b (lvalue):\n";
    a = b;                  // copy
    std::cout << "-- a = std::move(c) (rvalue):\n";
    a = std::move(c);       // copy here too (the rvalue is NOT exploited)
}
