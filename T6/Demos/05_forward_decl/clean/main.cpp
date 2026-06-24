#include <iostream>

class Observer;                

class Subject {
    Observer* obs;              
public:
    explicit Subject(Observer* o) : obs(o) {}
    void notify();
};

void Subject::notify() {
    obs->update();             
}

int main() {
    Subject s(nullptr);
    s.notify();
    return 0;
}

// Q5.1. Forward declaration
//
// With only a forward declaration (class Observer;), the Observer* obs member compiles fine. The code is shown above.
// What about the call obs->update()?
//   a) it compiles and runs
//   b) compiler error: member access into an incomplete type Observer
//   c) a linker error
//   d) a runtime null-pointer crash
