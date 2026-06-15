#include "egg.h"

// At startup this calls instance(), which builds the Egg on the spot ("Egg ctor 42") then setVal(100). 
// The instance always exists before use, any link order.
struct Initializer {
    Initializer() { Egg::instance()->setVal(100); }
};

static Initializer init;
