#include "array.h"

template <typename T>
Array<T>::Array(int size, T* arr) : size{size}, arr{arr} {}

template <typename T>
T Array<T>::sum() const {
    T total{};
    for (int i = 0; i < size; ++i) total += arr[i];
    return total;
}
