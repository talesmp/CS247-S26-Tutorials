#include "counter.h"

void show() {
    // reads other.cpp's OWN private copy of counter
    std::cout << "counter = " << counter << "\n";
}
