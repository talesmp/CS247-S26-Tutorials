#ifndef BEVERAGE_H
#define BEVERAGE_H
#include <string>
class Beverage {                                 // Component (the shared abstract type)
protected:
    std::string description = "Unknown Beverage";
public:
    virtual ~Beverage() = default;               // virtual dtor (§2)
    virtual std::string getDescription() const { return description; }
    virtual double cost() const = 0;             // pure virtual => abstract
};
#endif // BEVERAGE_H
