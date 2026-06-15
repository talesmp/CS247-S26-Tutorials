// Topic: Helper Functions
// What happens when two .cc files define the same free function name?
//  build with `g++ main.cc rational.cc date.cc -o demo`
#include <iostream>
#include "rational.h"
#include "date.h"

int main() {
    std::cout << reduce(40) << " " << daysApart(12) << "\n";
}
