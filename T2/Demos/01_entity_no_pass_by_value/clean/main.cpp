// Topic: Entity Objects
// Will this compile, and if so, what does it print?
#include <iostream>
#include <string>

class Passenger {
public:
    std::string name;
    Passenger(std::string n) : name{std::move(n)} {}
    Passenger(const Passenger&) = delete;
};

void announce(Passenger p) { std::cout << p.name << '\n'; }

int main() {
    Passenger alice{"Alice"};
    announce(std::move(alice));
}
