#include <iostream>
#include <string>

class Passenger {
public:
    std::string name;
    Passenger(std::string n) : name{std::move(n)} {}
    Passenger(const Passenger&) = delete;
};

// Entities are passed by reference, never by value: no copy/move is needed.
void announce(const Passenger& p) { std::cout << p.name << '\n'; }

int main() {
    Passenger alice{"Alice"};
    announce(alice);   // prints: Alice
}
