// Answer (Q9.1): compiler error => `unique_ptr`'s copy constructor is deleted. 
// auto q = p; asks to copy a unique_ptr; a second owner is forbidden, so the copy ctor is deleted and it doesn't compile. 
// Use std::move(p). (The naive A/B assume copy works like a raw pointer.)

// Answer (Q9.2): `p null`
// std::move transfers ownership from p to q; 
// a unique_ptr is non-copyable, so the move empties the source => p is left null, q owns the int.

// unique_ptr models exclusive ownership, so it is non-copyable. `auto q = p; `asks to COPY it; 
// the copy ctor is deleted (a second owner breaks "one owner"), so it won't compile => a compile-time error, the safest kind.
#include <iostream>
#include <memory>

int main() {
    auto p = std::make_unique<int>(10);
    auto q = p;                       // ERROR: unique_ptr copy ctor is deleted
    std::cout << *q << '\n';
}
// Fix: transfer with std::move; the source p is left null (solution/).
