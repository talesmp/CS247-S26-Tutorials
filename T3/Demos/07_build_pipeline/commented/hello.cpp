// Answer (Q6.1): Yes, `-c` compiles+assembles only; library symbols are resolved later,
// at link -- `-c` stops before linking. nm hello.o shows U std::cout => an unresolved
// "need" wire the linker fills in from libstdc++. So compiling a single file never
// complains about missing definitions; that's the linker's job.

#include <iostream>

#define GREETING "Hello, CS247"   // a valued macro 

int main() {
    std::cout << GREETING << "\n";
    return 0;
}

