#ifndef ARRAY_H
#define ARRAY_H

template <typename T>
class Array {
    int size;
    T* arr;
public:
    Array(int size, T* arr);
    T sum() const;
};

#endif
