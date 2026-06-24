#ifndef WHIP_H
#define WHIP_H
#include <memory>
#include "condimentdecorator.h"
class Whip : public CondimentDecorator {         // ConcreteDecorator
public:
    explicit Whip(std::unique_ptr<Beverage> b) : CondimentDecorator(std::move(b)) {}
    std::string getDescription() const override {
        return beverage->getDescription() + ", Whip";
    }
    double cost() const override {
        return 0.10 + beverage->cost();
    }
};
#endif // WHIP_H
