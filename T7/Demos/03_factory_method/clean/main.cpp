#include <iostream>
#include <memory>
#include <string>
#include <string_view>

class Pizza {
public:
    virtual std::string name() const = 0;
    virtual ~Pizza() = default;
};

class NYStyleCheesePizza : public Pizza {
public:
    std::string name() const override { return "NY Style Cheese Pizza"; }
};

class PizzaStore {
public:
    std::unique_ptr<Pizza> orderPizza(std::string_view type) {
        auto pizza = createPizza(type);
        return pizza;
    }
    virtual std::unique_ptr<Pizza> createPizza(std::string_view type) = 0;
    virtual ~PizzaStore() = default;
};

class NYPizzaStore : public PizzaStore {
public:
    std::unique_ptr<NYStyleCheesePizza> createPizza(std::string_view type) override {
        if (type == "cheese") return std::make_unique<NYStyleCheesePizza>();
        return nullptr;
    }
};

int main() {
    auto store = std::make_unique<NYPizzaStore>();
    auto pizza = store->orderPizza("cheese");
    std::cout << pizza->name() << '\n';
}


