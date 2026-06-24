#include <iostream>
#include <string>

class Beverage {                                  
public:
    virtual ~Beverage() = default;
    virtual std::string getDescription() const { return "Unknown Beverage"; }
    virtual double cost() const = 0;             
};

class DarkRoast : public Beverage {
public:
    double cost() const override { return 0.99; }
};

int main() {
    Beverage b;
    std::cout << b.cost() << '\n';
    return 0;
}

// Q1.1. Program to an interface
//
// You build the code above (it does Beverage b;, where Beverage's cost() is pure virtual).
// What happens?
//   a) it prints 0.99
//   b) compiler error — Beverage is an abstract class, you can't instantiate it
//   c) it prints "Unknown Beverage"
//   d) a linker error
