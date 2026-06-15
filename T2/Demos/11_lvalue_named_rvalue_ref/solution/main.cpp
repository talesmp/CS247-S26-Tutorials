#include <iostream>
#include <utility>

struct Widget {
    Widget()                  { std::cout << "default\n"; }
    Widget(const Widget&)     { std::cout << "copy\n"; }
    Widget(Widget&&) noexcept { std::cout << "move\n"; }
};

void process(Widget&& w) {
    Widget local = std::move(w);   // cast the named lvalue back to an rvalue
}

int main() {
    process(Widget{});             // prints: default  then  move
}
