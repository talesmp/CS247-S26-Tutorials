#include <iostream>
#include <vector>
#include <algorithm>

class Observer {
public:
    virtual ~Observer() = default;
    virtual void update() = 0;
};

class Subject {
    std::vector<Observer*> observers;           
public:
    void registerObserver(Observer* o) { observers.push_back(o); }
    void removeObserver(Observer* o) {
        observers.erase(std::remove(observers.begin(), observers.end(), o), observers.end());
    }
    void notifyObservers() { for (auto* o : observers) o->update(); }
};

class TempDisplay : public Observer {
    Subject* subject;
public:
    explicit TempDisplay(Subject* s) : subject(s) { subject->registerObserver(this); }
    void update() override { std::cout << "TempDisplay updated\n"; }
};

int main() {
    Subject weather;
    Observer* temp = new TempDisplay(&weather);  
    weather.notifyObservers();                  

    delete temp;                                
    std::cout << "-- temp deleted --\n";
    weather.notifyObservers();                   
    return 0;
}


// Q7.1. Dangling observer
//
// An observer is deleted but never removed from the subject's list, then the subject notifies again, as shown above.
// What happens on the second notifyObservers()?
//   a) it prints TempDisplay updated again — harmless
//   b) undefined behaviour: a use-after-free (ASan reports heap-use-after-free)
//   c) a compiler error
//   d) it safely prints nothing
