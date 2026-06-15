// Answer (Q12.1): Nothing, `std::terminate` is called; the `catch` is bypassed.
// cleanup is noexcept; throwing from it skips the handler search entirely and goes straight to std::terminate. 
// The catch never runs. (The compiler even warns: clang -Wexceptions, g++ -Wterminate.) 
// Don't mark a function noexcept unless it truly won't throw.

// Answer (Q12.2): A function that throws `std::runtime_error` and is caught by `catch (const std::exception&)`.
// The first three are the classic terminate triggers. 
// The correct answer is the normal, healthy case, a derived exception caught by a base const& handler — exactly what exceptions are for.

// noexcept is a hard promise, enforced by std::terminate. 
// cleanup() is marked noexcept ("won't throw"), then throws anyway.
// The throw skips the handler machinery and goes straight to std::terminate, bypassing the surrounding catch.
#include <iostream>
#include <stdexcept>

void cleanup() noexcept {               // promises not to throw...
    throw std::runtime_error("oops");   // ...but does -> std::terminate immediately
}

int main() {
    try {
        cleanup();
    } catch (const std::exception& e) {   // NEVER runs
        std::cout << "caught: " << e.what() << '\n';
    }
    std::cout << "after\n";               // never reached
    return 0;
}
// Compiler warns (clang -Wexceptions / g++ -Wterminate); runtime terminates.
// Fix: don't mark a function noexcept unless it truly won't throw.
// Remove it and the throw propagates normally: caught: oops / after (solution/).
