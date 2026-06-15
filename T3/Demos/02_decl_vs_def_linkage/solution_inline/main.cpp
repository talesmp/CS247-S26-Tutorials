#include "counter.h"

int main() {
    counter = 5;
    show();          // -> counter = 5   (ONE shared variable)
    return 0;
}
