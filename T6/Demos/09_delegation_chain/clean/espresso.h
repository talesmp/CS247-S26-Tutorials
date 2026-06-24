#ifndef ESPRESSO_H
#define ESPRESSO_H
#include "beverage.h"
class Espresso : public Beverage {               // ConcreteComponent
public:
    Espresso() { description = "Espresso"; }
    double cost() const override { return 1.99; }
};
#endif // ESPRESSO_H
