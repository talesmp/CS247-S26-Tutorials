#ifndef VEC_H
#define VEC_H

struct Vec {
    int x;
    int y;
};

Vec operator+(const Vec &a, const Vec &b);

#endif // VEC_H
