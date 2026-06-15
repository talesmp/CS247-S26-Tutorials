// Topic: Default Constructor
// What is the value of m.p.x at the assert?
#include <cassert>

struct Point { int x, y; };

struct Marker {
    Point p;
    int x;
    Marker(int v) : x{v} {}
};

int main() {
    Marker m{5};
    assert(m.p.x == 0);
}
