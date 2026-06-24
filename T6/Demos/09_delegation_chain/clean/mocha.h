#ifndef MOCHA_H
#define MOCHA_H
#include <memory>
#include "condimentdecorator.h"
class Mocha : public CondimentDecorator {        // ConcreteDecorator
public:
    explicit Mocha(std::unique_ptr<Beverage> b) : CondimentDecorator(std::move(b)) {}
    std::string getDescription() const override {
        return beverage->getDescription() + ", Mocha";   // delegate inward, then add label
    }
    double cost() const override {
        return 0.20 + beverage->cost();                   // add price, then delegate inward
    }
};
#endif // MOCHA_H
