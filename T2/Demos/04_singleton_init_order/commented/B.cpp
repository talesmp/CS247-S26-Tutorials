#include "egg.h"

// A static in another TU that touches the singleton at startup. 
// If it runs before A.cpp constructs instance_, it mutates a not-yet-built object.
struct Initializer {
    Initializer() { Egg::instance()->setVal(100); }
};

static Initializer init;
