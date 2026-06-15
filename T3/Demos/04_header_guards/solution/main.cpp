#include "widget.h"
#include "panel.h"     // widget.h is pasted again, but the guard deletes the body
#include <iostream>

int main() {
    Panel p;
    std::cout << p.inner().label() << "\n";   // -> widget
    return 0;
}
