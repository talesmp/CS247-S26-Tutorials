#ifndef COUNTER_H
#define COUNTER_H

#include <iostream>

// PITFALL. file-scope `static` = internal linkage: every .cpp gets its own
// private counter. Builds and links fine, then misbehaves at runtime -- the
// silent bug. static is not for sharing.
static int counter = 0;

void show();

#endif // COUNTER_H
