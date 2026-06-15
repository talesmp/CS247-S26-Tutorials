// Answer: deleting a Dog via Animal* runs only ~Animal() -- ~Dog() is skipped, so Dog's resources leak (silent).

#include <iostream>

class Animal {
public:
    // Not virtual: resolved by the static type (Animal*), so this always wins.
    void makeSound() const { std::cout << "Generic sound\n"; }
    // Not virtual: deleting through Animal* runs only ~Animal.
    ~Animal() { std::cout << "Animal destroyed\n"; }
};

class Dog : public Animal {
public:
    void makeSound() const { std::cout << "Woof!\n"; }   // hides, doesn't override
    ~Dog() { std::cout << "Dog destroyed\n"; }            // never runs below
};

int main() {
    Animal* a = new Dog();
    a->makeSound();   // "Generic sound"
    delete a;         // only "Animal destroyed" -- ~Dog() skipped, any Dog state leaks.
                      // Fully silent: Animal isn't polymorphic, so no -Wall warning.
    // Fix: make makeSound and ~Animal virtual. See ../solution.
}
