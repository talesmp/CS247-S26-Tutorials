// Answer (Q1.1): `i = 10`, assert is a preprocessor macro; 
// -DNDEBUG expands it to nothing, taking the hidden i++ with it, so i stays 10. 
// The debug build (no -DNDEBUG) prints i = 11. Same source, two answers — never put a side effect in an assert.

// Answer (Q1.2): A private helper was called with a negative size your own code should never produce. 
// Assertions are for programming errors (broken assumptions / bugs): they abort with no unwinding, freezing the state for a debugger. 
// The other options are recoverable environmental problems → exceptions, which unwind to a handler.

// THE BUG: an assert must never have a side effect. assert is a macro; 
// with -DNDEBUG it expands to nothing, so any work inside the parens vanishes in a release build.
#include <cassert>
#include <iostream>

int main() {
    int i = 10;
    // i++ is a side effect done by the check itself:
    //   debug    : assert live -> i becomes 11
    //   -DNDEBUG : line gone   -> i stays 10
    assert(i++ == 10);
    std::cout << "i = " << i << '\n';   // 11 debug | 10 release
    // Fix: assert(i == 10); then ++i; on its own line (solution/).
}
