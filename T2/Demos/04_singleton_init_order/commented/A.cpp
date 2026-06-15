#include "egg.h"

// The single instance. Its ctor(42) races against B.cpp's Initializer across TUs.
Egg Egg::instance_{42};
