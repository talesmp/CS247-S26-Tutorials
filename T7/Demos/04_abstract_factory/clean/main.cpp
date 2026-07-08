#include <iostream>
#include <memory>
#include <string>

class Dough  { public: virtual std::string name() const = 0; virtual ~Dough()  = default; };
class Cheese { public: virtual std::string name() const = 0; virtual ~Cheese() = default; };

class ThinCrustDough   : public Dough  { std::string name() const override { return "Thin Crust Dough"; } };
class ThickCrustDough  : public Dough  { std::string name() const override { return "Extra Thick Crust"; } };
class ReggianoCheese   : public Cheese { std::string name() const override { return "Grated Reggiano"; } };
class MozzarellaCheese : public Cheese { std::string name() const override { return "Shredded Mozzarella"; } };

class PizzaIngredientFactory {
public:
    virtual std::unique_ptr<Dough>  createDough()  const = 0;
    virtual std::unique_ptr<Cheese> createCheese() const = 0;
    virtual ~PizzaIngredientFactory() = default;
};

class NYIngredientFactory : public PizzaIngredientFactory {
    std::unique_ptr<Dough>  createDough()  const override { return std::make_unique<ThinCrustDough>(); }
    std::unique_ptr<Cheese> createCheese() const override { return std::make_unique<ReggianoCheese>(); }
};

class ChicagoIngredientFactory : public PizzaIngredientFactory {
    std::unique_ptr<Dough>  createDough()  const override { return std::make_unique<ThickCrustDough>(); }
    std::unique_ptr<Cheese> createCheese() const override { return std::make_unique<MozzarellaCheese>(); }
};

class CheesePizza {
    std::string dough, cheese;
public:
    explicit CheesePizza(const PizzaIngredientFactory& f)
        : dough(f.createDough()->name()), cheese(f.createCheese()->name()) {}
    void describe() const { std::cout << "Cheese Pizza: " << dough << " + " << cheese << '\n'; }
};

int main() {
    NYIngredientFactory      ny;
    ChicagoIngredientFactory chicago;
    CheesePizza(ny).describe();
    CheesePizza(chicago).describe();
}

