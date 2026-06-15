#include <iostream>

struct Box {
    int* data_;
    Box(int v) : data_{new int{v}} {}
    Box(const Box& o) : data_{new int{*o.data_}} {}
    ~Box() { delete data_; }
    bool operator==(const Box& o) const {
        return *data_ == *o.data_;        // compare the pointed-to VALUES
    }
};

int main() {
    Box a{5};
    Box b = a;
    std::cout << (a == b ? "equal\n" : "different\n");   // prints "equal"
}
