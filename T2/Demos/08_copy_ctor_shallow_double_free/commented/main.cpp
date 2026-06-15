// Answer: UB -- the default shallow copy makes b.data_ alias a.data_; ~b frees it, so *a.data_ is a use-after-free and ~a then double-frees.

// The default copy ctor is a SHALLOW copy. 
// Node owns heap memory and has a real dtor, but no copy ctor, so `Node b = a;` copies the POINTER, not the int. 
// ~b deletes the shared int, leaving a.data_ dangling: `*a.data_` is a use-after-free, then ~a double-frees it. 
// Fix: deep copy (see solution/).
#include <iostream>

struct Node {
    int* data_;
    Node(int v) : data_{new int{v}} {}
    ~Node() { delete data_; }
    // No copy ctor -> compiler makes a shallow one (copies the pointer)
};

int main() {
    Node a{42};
    {
        Node b = a;          // shallow copy: b.data_ aliases a.data_
    }                        // ~b deletes the shared int -> a.data_ dangles
    std::cout << *a.data_ << '\n';   // use-after-free; ~a then double-frees
}
