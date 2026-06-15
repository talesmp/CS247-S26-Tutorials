// Answer (Q7.1): No, `delete` is skipped and the `Resource` leaks -- doWork() throws → unwinding jumps past delete r;. 
// Unwinding destroys the pointer r, but a raw pointer has no destructor, so the heap Resource is stranded.
// Resource freed never prints. Option A assumes unwinding frees heap objects; it doesn't. 
// Fix: make_unique.

// The raw-pointer leak. Unwinding faithfully destroys STACK objects, but a raw pointer has no destructor. 
// When doWork() throws, control jumps to the handler and `delete r;` is never reached.
// r is popped, the heap Resource is stranded.
#include <iostream>
#include <stdexcept>

struct Resource {
    Resource()  { std::cout << "Resource acquired\n"; }
    ~Resource() { std::cout << "Resource freed\n"; }   // not seen on the throw path
};

void doWork() { throw std::runtime_error("kaboom"); }

void process() {
    Resource* r = new Resource();   // raw owning pointer
    doWork();                       // throws -> unwinding skips the delete
    delete r;                       // NEVER REACHED
}

int main() {
    try {
        process();
    } catch (const std::exception& e) {
        std::cout << "caught: " << e.what() << '\n';
    }
}
// Output omits "Resource freed" => that silence is the leak (valgrind on Linux).
// Fix: hold it in a unique_ptr (a stack object whose dtor deletes) (solution/).
