#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <string_view>
#include <stdexcept>

class MenuComponent {
public:
    virtual ~MenuComponent() = default;
    virtual void add(std::unique_ptr<MenuComponent>) { throw std::runtime_error("Operation not supported"); }
    virtual std::string_view getName() const         { throw std::runtime_error("Operation not supported"); }
    virtual double getPrice() const                  { throw std::runtime_error("Operation not supported"); }
    virtual void print() const = 0;
protected:
    MenuComponent() = default;
};

class MenuItem final : public MenuComponent {
    std::string name_;
    double price_;
public:
    MenuItem(std::string name, double price) : name_(std::move(name)), price_(price) {}
    std::string_view getName() const override { return name_; }
    double getPrice() const override          { return price_; }
    void print() const override { std::cout << "  " << getName() << ", $" << getPrice() << '\n'; }
};

class Menu : public MenuComponent {
    std::vector<std::unique_ptr<MenuComponent>> menuComponents_;
    std::string name_;
public:
    explicit Menu(std::string name) : name_(std::move(name)) {}
    void add(std::unique_ptr<MenuComponent> c) override { menuComponents_.push_back(std::move(c)); }
    std::string_view getName() const override { return name_; }
    void print() const override {
        std::cout << '\n' << getName() << "\n---------\n";
        for (const auto& c : menuComponents_) c->print();
    }
};

int main() {
    Menu lunch("Lunch");
    auto blt = std::make_unique<MenuItem>("BLT", 6.50);
    MenuItem* bltPtr = blt.get();
    lunch.add(std::move(blt));

    lunch.print();

    bltPtr->add(std::make_unique<MenuItem>("extra bacon", 1.50));
    std::cout << "added to the sandwich?\n";
}
