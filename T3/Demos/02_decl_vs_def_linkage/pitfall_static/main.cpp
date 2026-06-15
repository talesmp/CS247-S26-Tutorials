#include "counter.h"

int main() {
    counter = 5;                                            // sets main.cpp's copy
    std::cout << "main's counter   = " << counter << "\n";  // -> 5
    show();                                                 // -> counter = 0  (!!)
    // The two `counter`s are DIFFERENT variables. The build succeeded; the
    // program is silently wrong. THIS is why `static` is not for sharing.
    return 0;
}
