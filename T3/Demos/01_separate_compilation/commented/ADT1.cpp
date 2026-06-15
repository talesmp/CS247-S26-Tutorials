#include "ADT1.h"
#include <utility>

// The hidden IMPLEMENTATION: the method bodies live here, not in the header.
// This is the single DEFINITION of each function.
B::B(std::string name) : name_(std::move(name)) {}

std::string B::greet() const {
    return "Hi, I am " + name_;
}
