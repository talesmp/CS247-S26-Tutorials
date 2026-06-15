// Answer: UB on `a = a` -- operator= deletes data_, then reads the now-freed *o.data_ (o IS a). 
// Needs a self-assignment guard (or copy-swap).

// Copy assignment must survive self-assignment (a = a). 
// The free-then-alloc order is fine for distinct objects.
// But when o IS *this, `delete data_` frees the very int the next line reads via *o.data_ -> use-after-free. 
// Only one delete, so it's easy to miss: the bug is the READ, not a double free.
// Fix: guard `if (this == &o)`, or use copy-swap (demo 10), self-assign safe.
#include <iostream>

struct Buffer {
    int* data_;
    Buffer(int v) : data_{new int{v}} {}
    Buffer(const Buffer& o) : data_{new int{*o.data_}} {}
    ~Buffer() { delete data_; }

    Buffer& operator=(const Buffer& o) {
        delete data_;                   // on a = a, frees o's int too
        data_ = new int{*o.data_};      // ...then reads freed *o.data_ -> UB
        return *this;
    }
};

int main() {
    Buffer a{10};
    a = a;                              // self-assignment triggers the UB
    std::cout << *a.data_ << '\n';
}
