#include <iostream>

class DisplayElement {
public:
    ~DisplayElement() { 
        std::cout << "~DisplayElement\n";   // NOT virtual
    }   
    virtual void display() const { 
        std::cout << "(base display)\n";    // polymorphic base
    }   
};

class CurrentConditionsDisplay : public DisplayElement {
public:
    ~CurrentConditionsDisplay() { 
        std::cout << "~CurrentConditionsDisplay\n"; 
    }
    void display() const override { 
        std::cout << "Current conditions\n"; 
    }
};

int main() {
    DisplayElement* d = new CurrentConditionsDisplay();
    d->display();
    delete d;                // delete through a base pointer
    return 0;
}

// Q3.1. Virtual destructor
//
// A derived object is deleted through a base pointer whose base destructor is non-virtual, as shown above.
// Which destructor lines print, and in what order?
//   a) ~CurrentConditionsDisplay then ~DisplayElement
//   b) ~DisplayElement only — the derived destructor is skipped
//   c) neither runs
//   d) a compiler error
