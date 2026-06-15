// Topic: Copy Constructor
// What does this print?
#include <iostream>

struct Node {
    int* data_;
    Node(int v) : data_{new int{v}} {}
    ~Node() { delete data_; }
};

int main() {
    Node a{42};
    {
        Node b = a;
    }
    std::cout << *a.data_ << '\n';
}
