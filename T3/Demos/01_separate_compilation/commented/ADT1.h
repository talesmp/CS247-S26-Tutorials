#ifndef ADT1_H
#define ADT1_H

#include <string>

// ADT1.h is the INTERFACE (the public face) of the ADT1 module.
// It DECLARES class B so that other modules can refer to B without containing
// B's definition themselves.
class B {
    std::string name_;
public:
    explicit B(std::string name);
    std::string greet() const;   // declaration; the body lives in ADT1.cpp
};

#endif // ADT1_H
