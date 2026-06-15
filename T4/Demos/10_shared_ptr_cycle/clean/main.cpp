// Topic: shared_ptr cycle
// Q10.1: The whole of clean/main.cpp (~A prints ~A, ~B prints ~B), shown. 
// What does it print?
//   a) `end of main` · `~A` · `~B`
//   b) `end of main` · `~B` · `~A`
//   c) `end of main` only — neither destructor runs
//   d) `~A` · `~B` · `end of main`

#include <iostream>
#include <memory>

struct B;
struct A { std::shared_ptr<B> b; ~A() { std::cout << "~A\n"; } };
struct B { std::shared_ptr<A> a; ~B() { std::cout << "~B\n"; } };

int main() {
    auto a = std::make_shared<A>();
    auto b = std::make_shared<B>();
    a->b = b;
    b->a = a;
    std::cout << "end of main\n";
    return 0;
}

