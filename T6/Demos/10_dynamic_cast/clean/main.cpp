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

class Mocha : public Beverage {
    std::unique_ptr<Beverage> beverage;
public:
    explicit Mocha(std::unique_ptr<Beverage> b) : beverage(std::move(b)) {}
    std::string getDescription() const override { return beverage->getDescription() + ", Mocha"; }
    double cost() const override { return 0.20 + beverage->cost(); }
};

int main() {
    std::unique_ptr<Beverage> beverage = std::make_unique<DarkRoast>();
    beverage = std::make_unique<Mocha>(std::move(beverage));     

    DarkRoast* dr = dynamic_cast<DarkRoast*>(beverage.get());    
    std::cout << (dr ? "got a DarkRoast" : "NOT a DarkRoast (nullptr)") << '\n';
    return 0;
}


// Q10.1. Decorator transparency
//
// A DarkRoast is wrapped in a Mocha, then the client does dynamic_cast<DarkRoast*>(beverage.get()), as shown above.
// What does dr end up as?
//   a) a valid DarkRoast* — the DarkRoast is in there somewhere
//   b) nullptr — the object's dynamic type is Mocha, not DarkRoast
//   c) a compiler error
//   d) it throws std::bad_cast
