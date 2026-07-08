#include <iostream>
#include <string>
#include <string_view>

class Pizza {
public:
    virtual std::string name() const { return "Plain Pizza"; }
    virtual ~Pizza() = default;
};

class CheesePizza : public Pizza {
public:
    std::string name() const override { return "Cheese Pizza"; }
};

class VeggiePizza : public Pizza {
public:
    std::string name() const override { return "Veggie Pizza"; }
};

class SimplePizzaFactory {
public:
    Pizza createPizza(std::string_view type) {
        if (type == "cheese") return CheesePizza();
        if (type == "veggie") return VeggiePizza();
        return Pizza();
    }
};

int main() {
    SimplePizzaFactory factory;
    Pizza pizza = factory.createPizza("cheese");
    std::cout << "Ordered: " << pizza.name() << '\n';
}
