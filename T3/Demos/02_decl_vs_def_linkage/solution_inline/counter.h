#ifndef COUNTER_H
#define COUNTER_H

#include <iostream>

// FIX #1 (C++17, preferred). `inline` gives external linkage AND tells the
// linker that all the copies are the SAME entity, so it merges them into one
// shared variable. Header-only: no separate .cpp needed.
inline int counter = 0;

void show();

#endif // COUNTER_H
