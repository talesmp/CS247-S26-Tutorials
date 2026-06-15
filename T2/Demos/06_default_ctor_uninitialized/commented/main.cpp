// Answer: indeterminate (UB) => Marker's ctor never inits p, so the assert isn't guaranteed; it reliably fires on ARM Macs (junk value).

// The default ctor does NOT zero plain members. 
// Marker(int) sets x but not p, so p is default-initialized => its ints hold garbage. 
// Reading m.p.x is UB: on a ARM Mac the assert fires (junk value); elsewhere it might read 0 by luck.
// Note: `Point p{}` would value-init to 0 => the missing braces are the bug.
// Fix: in-class initializers, or init p in the list (solution/).
#include <cassert>

struct Point { int x, y; };   // no in-class init -> ints start as garbage

struct Marker {
    Point p;                  // not in the init list -> default-initialized
    int x;
    Marker(int v) : x{v} {}   // sets x, ignores p
};

int main() {
    Marker m{5};
    assert(m.p.x == 0);       // reads indeterminate memory -> UB; may abort
}
