#include "ADT1.h"
#include <utility>

B::B(std::string name) : name_(std::move(name)) {}

std::string B::greet() const {
    return "Hi, I am " + name_;
}
