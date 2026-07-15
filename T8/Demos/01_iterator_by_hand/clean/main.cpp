#include <iostream>

class intArray {
    int size;
    int* arr;
public:
    intArray(int size, int* arr) : size{size}, arr{arr} {}

    class Iterator {
        int* p;
    public:
        explicit Iterator(int* p) : p{p} {}
        Iterator& operator++()                  { ++p; return *this; }
        bool operator<(const Iterator& o) const { return p < o.p; }
        int& operator*() const                  { return *p; }
    };

    Iterator begin() { return Iterator{arr}; }
    Iterator end()   { return Iterator{arr + size}; }
};

int main() {
    int data[] = {10, 20, 30};
    intArray a(3, data);
    for (int x : a) std::cout << x << ' ';
    std::cout << '\n';
}
