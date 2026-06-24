#include <iostream>
#include <string>

class Animal {
public:
    virtual ~Animal() = default;
    virtual std::string makeSound() const { return "...generic animal sound..."; }
};

class Dog : public Animal {
public:
    std::string makeSound() const override { return "Woof"; }
};

void wakeUp(Animal a) {                  // takes the supertype BY VALUE
    std::cout << a.makeSound() << '\n';
}

int main() {
    Dog d;
    wakeUp(d);
    return 0;
}

// Q2.1. Object slicing
//
// wakeUp(Animal) takes its parameter BY VALUE and is passed a Dog. The code above compiles and runs.
// What does it print?
//   a) Woof
//   b) ...generic animal sound...
//   c) a compiler error
//   d) nothing
