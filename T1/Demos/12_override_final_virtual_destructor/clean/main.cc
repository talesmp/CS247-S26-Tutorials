// Topic: override and final
// What does missing virtual on the destructor actually cost you?
#include <iostream>

class Animal {
public:
    void makeSound() const { std::cout << "Generic sound\n"; }
    ~Animal() { std::cout << "Animal destroyed\n"; }
};

class Dog : public Animal {
public:
    void makeSound() const { std::cout << "Woof!\n"; }
    ~Dog() { std::cout << "Dog destroyed\n"; }
};

int main() {
    Animal* a = new Dog();
    a->makeSound();
    delete a;
}
