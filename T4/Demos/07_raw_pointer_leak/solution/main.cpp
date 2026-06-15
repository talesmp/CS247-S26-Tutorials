// Fix: a unique_ptr wraps the heap object in a stack object whose destructor frees it. 
// Unwinding always runs stack destructors, so the Resource is freed on BOTH the normal path and the throw path. 
// No delete anywhere.
#include <iostream>
#include <memory>
#include <stdexcept>

struct Resource {
    Resource()  { std::cout << "Resource acquired\n"; }
    ~Resource() { std::cout << "Resource freed\n"; }
};

void doWork() { throw std::runtime_error("kaboom"); }

void process() {
    auto r = std::make_unique<Resource>();   // owns the heap Resource
    doWork();                                // throws -> r's destructor still runs
}

int main() {
    try {
        process();
    } catch (const std::exception& e) {
        std::cout << "caught: " << e.what() << '\n';
    }
    return 0;
}
// Output (now "Resource freed" prints even though we threw):
//   Resource acquired
//   Resource freed
//   caught: kaboom
