#include <iostream>
#include <iomanip>
#include <memory>
#include "espresso.h"
#include "darkroast.h"
#include "mocha.h"
#include "whip.h"

int main() {
    std::cout << std::fixed << std::setprecision(2);  

    auto beverage = std::make_unique<Espresso>();
    std::cout << beverage->getDescription() << " $" << beverage->cost() << "\n";

    std::unique_ptr<Beverage> beverage2 = std::make_unique<DarkRoast>();
    beverage2 = std::make_unique<Mocha>(std::move(beverage2));  
    beverage2 = std::make_unique<Mocha>(std::move(beverage2));   
    beverage2 = std::make_unique<Whip>(std::move(beverage2));    
    std::cout << beverage2->getDescription() << " $" << beverage2->cost() << "\n";

    return 0;
}

// Q9.1. Delegation chain
//
// The beverage is Whip(Mocha(Mocha(DarkRoast))) with DarkRoast 0.99, Mocha 0.20, Whip 0.10, as shown above.
// What is cost()?
//   a) $1.39
//   b) $1.49
//   c) $1.29
//   d) $0.99
//
// Q9.2. Delegation chain
//
// Use the same Whip(Mocha(Mocha(DarkRoast))) chain shown above.
// What does getDescription() print?
//   a) Whip, Mocha, Mocha, Dark Roast Coffee
//   b) Dark Roast Coffee, Mocha, Mocha, Whip
//   c) Dark Roast Coffee, Whip
//   d) Mocha, Mocha, Whip
