#ifndef ADT1_H
#define ADT1_H

#include <string>

class B {
    std::string name_;
public:
    explicit B(std::string name);
    std::string greet() const;
};

#endif // ADT1_H
