// Answer (Q4.1): compiles with a warning, then prints `general handler`.
// First match wins, and runtime_error IS-A exception, so the base clause (listed first) catches it. 
// The second clause is unreachable dead code. 
// The compiler warns (-Wexceptions) but still builds. List derived-before-base.

// Handler order: list derived types before their bases. 
// Handlers are tried top-to-bottom, first match wins. 
// runtime_error IS-A exception, so the base handler first swallows everything and the runtime_error clause is dead code.
#include <iostream>
#include <stdexcept>

int main() {
    try {
        throw std::runtime_error("boom");
    } catch (const std::exception& e) {        // base FIRST -> catches everything
        std::cout << "general handler\n";
    } catch (const std::runtime_error& e) {    // dead code: unreachable
        std::cout << "runtime handler\n";
    }
}
// Prints "general handler"; compiler warns (-Wexceptions).
// Fix: specific-first, catch(...) last (solution/).
