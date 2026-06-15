// Topic: Linkage
// Q2.1: Consider this scenario. Assume it compiles and links with no error. What is
// printed?
//   a) main's counter = 5; counter = 5
//   b) main's counter = 5; counter = 0
//   c) main's counter = 0; counter = 0
//   d) main's counter = 0; counter = 5
//   e) Garbage

// Q2.2: (Conceptual) A header with a global definition is #include d by 6 different.cpp
// files. Which version causes a linker error? int MAX = 100; const int MAX = 100;
//   a) Both
//   b) Neither
//   c) Only version 1 (non-`const`)
//   d) Only version 2

#ifndef COUNTER_H
#define COUNTER_H

#include <iostream>

static int counter = 0;

void show();

#endif
