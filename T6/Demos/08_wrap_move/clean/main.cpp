#include <iostream>
#include <memory>
#include <string>

class Beverage {
public:
    virtual ~Beverage() = default;
    virtual std::string getDescription() const { return "Unknown Beverage"; }
    virtual double cost() const = 0;
};

class DarkRoast : public Beverage {
public:
    std::string getDescription() const override { return "Dark Roast Coffee"; }
    double cost() const override { return 0.99; }
};

class Mocha : public Beverage {                  // IS-A Beverage (inherits)
    std::unique_ptr<Beverage> beverage;          // HAS-A Beverage (owns the wrapped one)
public:
    explicit Mocha(std::unique_ptr<Beverage> b) : beverage(b) {}   // copy a unique_ptr?
    std::string getDescription() const override { return beverage->getDescription() + ", Mocha"; }
    double cost() const override { return 0.20 + beverage->cost(); }
};

int main() {
    std::unique_ptr<Beverage> b = std::make_unique<DarkRoast>();
    auto mocha = std::make_unique<Mocha>(b);
    std::cout << mocha->getDescription() << " $" << mocha->cost() << '\n';
    return 0;
}

// Q8.1. Decorator keystone
//
// A decorator (Mocha IS-A Beverage, HAS-A unique_ptr<Beverage>) copies its unique_ptr parameter into its member, as shown above. You build it.
// What happens?
//   a) it compiles and prints Dark Roast Coffee, Mocha $1.19
//   b) compiler error — a unique_ptr can't be copied (its copy constructor is deleted)
//   c) a linker error
//   d) a runtime double-free
