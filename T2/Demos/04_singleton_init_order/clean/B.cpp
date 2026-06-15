#include "egg.h"

struct Initializer {
    Initializer() { Egg::instance()->setVal(100); }
};

static Initializer init;
