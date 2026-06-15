#include <iostream>

struct Node {
    int* data_;
    Node(int v) : data_{new int{v}} {}
    Node(const Node& o) : data_{new int{*o.data_}} {}   // deep copy: own int
    Node& operator=(const Node& o) {                    // Rule of Three partner
        *data_ = *o.data_;
        return *this;
    }
    ~Node() { delete data_; }
};

int main() {
    Node a{42};
    {
        Node b = a;          // b gets its OWN heap int holding 42
    }                        // ~b deletes only b's int; a is untouched
    std::cout << *a.data_ << '\n';   // prints 42; ~a cleanly deletes a's int
}
