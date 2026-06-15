// Topic: Raw-pointer leak
// Q7.1: Running the program, does `Resource freed` ever print?
//   a) Yes — the destructor runs as the stack unwinds
//   b) No — `delete` is skipped and the `Resource` leaks
//   c) Yes, but only under `-DNDEBUG`
//   d) It doesn't compile

#include <iostream>
#include <stdexcept>

struct Resource {
    Resource()  { std::cout << "Resource acquired\n"; }
    ~Resource() { std::cout << "Resource freed\n"; }
};

void doWork() { throw std::runtime_error("kaboom"); }

void process() {
    Resource* r = new Resource();
    doWork();
    delete r;
}

int main() {
    try {
        process();
    } catch (const std::exception& e) {
        std::cout << "caught: " << e.what() << '\n';
    }
    return 0;
}

