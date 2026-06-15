// Answer: Different, operator== compares the pointers (addresses), and the deep copy gave b its own; compare *data_ == *o.data_ instead.

// operator== on a pointer member compares ADDRESSES, not values. 
// Box has a correct deep copy ctor, so b gets its own int -- different address, same value.
// `data_ == o.data_` compares the pointers, which differ, so a == b prints "different" though the boxes are logically equal. 
// Silent logic bug.
// Fix: compare contents `*data_ == *o.data_` (solution/).
#include <iostream>

struct Box {
    int* data_;
    Box(int v) : data_{new int{v}} {}
    Box(const Box& o) : data_{new int{*o.data_}} {}   // deep copy -> different address
    ~Box() { delete data_; }
    bool operator==(const Box& o) const {
        return data_ == o.data_;          // compares ADDRESSES (almost never what you want)
    }
};

int main() {
    Box a{5};
    Box b = a;        // deep copy: b.data_ != a.data_, but *b.data_ == *a.data_
    std::cout << (a == b ? "equal\n" : "different\n");   // prints "different"
}
