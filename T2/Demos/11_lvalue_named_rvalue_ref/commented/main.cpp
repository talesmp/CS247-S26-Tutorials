// Answer: the COPY ctor => w is a named rvalue reference, hence an lvalue.
// Widget local = std::move(w) would move instead.

// A NAMED rvalue reference is itself an lvalue. 
// `w` is declared Widget&&, but value category follows the expression, not the type.
// Anything with a name is an lvalue. So `Widget local = w;` copies. Output: default, copy.
// Fix: `Widget local = std::move(w);` casts back to rvalue -> move (solution/).
#include <iostream>

struct Widget {
    Widget()                  { std::cout << "default\n"; }
    Widget(const Widget&)     { std::cout << "copy\n"; }
    Widget(Widget&&) noexcept { std::cout << "move\n"; }
};

void process(Widget&& w) {
    Widget local = w;         // w is NAMED -> lvalue -> COPY ctor
}

int main() {
    process(Widget{});        // Widget{} -> "default", then process copies -> "copy"
}
