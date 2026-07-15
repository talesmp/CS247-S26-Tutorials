#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <string_view>
#include <stdexcept>
#include <stack>

class MenuComponent {
public:
    virtual ~MenuComponent() = default;
    virtual void add(std::unique_ptr<MenuComponent>) { throw std::runtime_error("Operation not supported"); }
    virtual MenuComponent* getChild(std::size_t)     { throw std::runtime_error("Operation not supported"); }
    virtual std::string_view getName() const         { throw std::runtime_error("Operation not supported"); }
    virtual double getPrice() const                  { throw std::runtime_error("Operation not supported"); }
    virtual bool isVegetarian() const                { throw std::runtime_error("Operation not supported"); }
    virtual void print() const = 0;
protected:
    MenuComponent() = default;
};

class MenuItem final : public MenuComponent {
    std::string name_;
    double price_;
    bool veg_;
public:
    MenuItem(std::string name, double price, bool veg)
        : name_(std::move(name)), price_(price), veg_(veg) {}
    std::string_view getName() const override { return name_; }
    double getPrice() const override          { return price_; }
    bool isVegetarian() const override        { return veg_; }
    void print() const override { std::cout << "  " << getName() << (veg_ ? " (v)" : "") << ", $" << getPrice() << '\n'; }
};

class Menu : public MenuComponent {
    std::vector<std::unique_ptr<MenuComponent>> menuComponents_;
    std::string name_;
public:
    explicit Menu(std::string name) : name_(std::move(name)) {}
    void add(std::unique_ptr<MenuComponent> c) override { menuComponents_.push_back(std::move(c)); }
    MenuComponent* getChild(std::size_t i) override {
        if (i >= menuComponents_.size()) throw std::out_of_range("Index out of range");
        return menuComponents_[i].get();
    }
    std::string_view getName() const override { return name_; }
    void print() const override {
        std::cout << '\n' << getName() << "\n---------\n";
        for (const auto& c : menuComponents_) c->print();
    }
};

class CompositeIterator {
    std::stack<MenuComponent*> stack_;
public:
    explicit CompositeIterator(MenuComponent* root) { if (root) stack_.push(root); }
    bool hasNext() const { return !stack_.empty(); }
    MenuComponent* next() {
        MenuComponent* current = stack_.top();
        stack_.pop();
        if (auto* menu = dynamic_cast<Menu*>(current)) {
            for (int i = static_cast<int>(menu->size()) - 1; i >= 0; --i)
                stack_.push(menu->getChild(i));
        }
        return current;
    }
};

double totalVegPrice(MenuComponent& root) {
    double total = 0.0;
    CompositeIterator it(&root);
    while (it.hasNext()) {
        MenuComponent* c = it.next();
        try { if (c->isVegetarian()) total += c->getPrice(); }
        catch (const std::runtime_error&) { /* a composite -- skip */ }
    }
    return total;
}

int main() {
    auto root = std::make_unique<Menu>("All Menus");
    root->add(std::make_unique<MenuItem>("Garden Salad", 5.00, true));
    root->add(std::make_unique<MenuItem>("Steak", 20.00, false));
    auto dessert = std::make_unique<Menu>("Dessert Menu");
    dessert->add(std::make_unique<MenuItem>("Cheesecake", 6.00, true));
    dessert->add(std::make_unique<MenuItem>("Fruit Cup", 4.00, true));
    root->add(std::move(dessert));

    std::cout << "Total vegetarian price: $" << totalVegPrice(*root) << '\n';
}
