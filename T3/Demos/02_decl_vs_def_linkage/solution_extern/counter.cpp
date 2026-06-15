#include "counter.h"

// The ONE definition (external linkage). If you forget this file, you get
// "undefined reference to counter" at link time.
int counter = 0;
