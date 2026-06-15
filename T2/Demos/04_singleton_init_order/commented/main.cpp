#include "egg.h"

// Runs after all static init: prints 42 or 100 depending on who won the race.
int main() {
    std::cout << Egg::instance()->val() << '\n';
}
