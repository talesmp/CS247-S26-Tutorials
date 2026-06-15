// Answer (Q2.1): main's counter = 5; counter = 0 -- static at file scope = internal
// linkage. Every.cpp gets its own private counter. main sets its copy to 5; show() reads
// other.cpp 's copy (still 0). Builds clean, silently wrong.
// Answer (Q2.2): Only version 1 (non-`const`) -- Namespace-scope const defaults to
// internal linkage (6 private copies, no clash). Plain int has external linkage => 6
// definitions => "multiple definition." Exactly why sharing a global needs extern /
// inline, but a constant usually doesn't.

#ifndef COUNTER_H
#define COUNTER_H

#include <iostream>

// BROKEN. This line is a DEFINITION of a global with external linkage.
// Every .cpp that #includes this header gets its OWN definition of `counter`,
// so the LINKER ends up with the symbol defined more than once.
int counter = 0;

void show();   // declaration only; defined in other.cpp

#endif // COUNTER_H
