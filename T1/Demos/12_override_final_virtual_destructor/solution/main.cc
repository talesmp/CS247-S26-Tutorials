#include <iostream>

class Animal {
public:
    // virtual: dispatches on the dynamic type, so a Dog behind Animal* barks.
    virtual void makeSound() const { std::cout << "Generic sound\n"; }
    // virtual dtor: delete through Animal* runs ~Dog() then ~Animal().
    virtual ~Animal() { std::cout << "Animal destroyed\n"; }
};

class Dog : public Animal {
public:
    void makeSound() const override { std::cout << "Woof!\n"; }   // override = checked
    ~Dog() override { std::cout << "Dog destroyed\n"; }
};

int main() {
    Animal* a = new Dog();
    a->makeSound();   // "Woof!"
    delete a;         // "Dog destroyed" then "Animal destroyed" -- full chain, no leak
}
