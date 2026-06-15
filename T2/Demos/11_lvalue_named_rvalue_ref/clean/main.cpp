// Topic: lvalue vs. rvalue
// Which constructor of Widget runs on the marked line?
#include <iostream>

struct Widget {
    Widget()                  { std::cout << "default\n"; }
    Widget(const Widget&)     { std::cout << "copy\n"; }
    Widget(Widget&&) noexcept { std::cout << "move\n"; }
};

void process(Widget&& w) {
    Widget local = w;
}

int main() {
    process(Widget{});
}
