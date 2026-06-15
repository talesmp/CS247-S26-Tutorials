#include <cassert>

struct Point { int x = 0, y = 0; };   // in-class initializers: always start at 0

struct Marker {
    Point p;
    int x;
    Marker(int v) : x{v} {}
};

int main() {
    Marker m{5};
    assert(m.p.x == 0);   // now guaranteed: p.x is value-initialized to 0
}
