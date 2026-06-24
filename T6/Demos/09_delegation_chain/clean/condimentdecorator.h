#ifndef CONDIMENTDECORATOR_H
#define CONDIMENTDECORATOR_H
#include <memory>
#include "beverage.h"
// The Decorator: IS-A Beverage (inherits) AND HAS-A Beverage (owns one via unique_ptr).
class CondimentDecorator : public Beverage {
protected:
    std::unique_ptr<Beverage> beverage;          // the wrapped object it owns
public:
    explicit CondimentDecorator(std::unique_ptr<Beverage> b) : beverage(std::move(b)) {}
    // unique_ptr cleans up the whole chain automatically -- no custom destructor needed.
    std::string getDescription() const override = 0;   // force each condiment to override
    double cost() const override = 0;
};
#endif // CONDIMENTDECORATOR_H
