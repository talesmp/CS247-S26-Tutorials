#include "vec.h"

Vec operator+(const Vec &a, const Vec &b) {
    return Vec{a.x + b.x, a.y + b.y};
}
