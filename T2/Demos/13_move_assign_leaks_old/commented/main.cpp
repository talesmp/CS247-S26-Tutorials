// Answer: `2`, but a's original `int{1}` is leaked (operator= overwrites data_ without freeing it; also no self-move guard).

// Move assignment must free the receiver's old resource first. 
// `a = std::move(b)` overwrites a.data_ (prints 2, correct) but never deletes a's original int{1}.
//  The only pointer to it is gone -> leak (read the missing `delete`; valgrind/ASan flag it on Linux). 
// Also no self-move guard: on `a = std::move(a)`, nulling o nulls a's own pointer -> lost.
// Fix: guard self-move, delete old, then take ownership -- or std::swap (solution/).
#include <iostream>
#include <utility>

class V {
public:
    int* data_;
    V(int x) : data_{new int{x}} {}
    V(V&& o) noexcept : data_{o.data_} { o.data_ = nullptr; }
    V& operator=(V&& o) noexcept {
        data_ = o.data_;        // overwrites a's pointer WITHOUT deleting a's int{1}
        o.data_ = nullptr;      // -> the original int{1} is leaked
        return *this;
    }
    ~V() { delete data_; }
};

int main() {
    V a{1};
    V b{2};
    a = std::move(b);           // prints 2, but a's original int{1} leaks
    std::cout << *a.data_ << '\n';
}
