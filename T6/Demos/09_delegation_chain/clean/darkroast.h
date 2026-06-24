#ifndef DARKROAST_H
#define DARKROAST_H
#include "beverage.h"
class DarkRoast : public Beverage {              // ConcreteComponent (base of the chain)
public:
    DarkRoast() { description = "Dark Roast Coffee"; }
    double cost() const override { return 0.99; }   // base price, no delegation
};
#endif // DARKROAST_H
