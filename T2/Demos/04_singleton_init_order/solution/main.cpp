#include "egg.h"

// Always prints 100, regardless of link order.
int main() {
    std::cout << Egg::instance()->val() << '\n';
}
