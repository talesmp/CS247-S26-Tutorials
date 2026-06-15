// Answer (Q10.1): `end of main` only — neither destructor runs.
// A and B co-own each other: each use count drops 2→1 at scope end, never 0, so neither is destroyed. 
// A reference cycle, and both leak. Make one back-edge a weak_ptr to break it.

// shared_ptr reference cycle: a leak that isn't shared_ptr's fault. 
// A and B own each other, so each use count is 2; at end of main the locals drop each 2->1, never 0. 
// They keep each other alive with no outside reference -- neither dtor runs, both leak. 
// Output: only "end of main".

#include <iostream>
#include <memory>

struct B;
struct A { std::shared_ptr<B> b; ~A() { std::cout << "~A\n"; } };
struct B { std::shared_ptr<A> a; ~B() { std::cout << "~B\n"; } };   // owning back-edge -> cycle

int main() {
    auto a = std::make_shared<A>();
    auto b = std::make_shared<B>();
    a->b = b;
    b->a = a;
    std::cout << "end of main\n";
    return 0;
}
// Output (no ~A, no ~B -> both leaked):
//   end of main
//
// THE FIX (solution/): break the cycle by making ONE direction non-owning.
// Change B's back-pointer to a weak_ptr: B observes A without co-owning it.
// Then A's count is 1, drops to 0 at scope end -> ~A runs, which releases a->b
// -> ~B runs. Output: end of main / ~A / ~B.
