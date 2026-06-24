#ifndef SUBJECT_H
#define SUBJECT_H
class Observer;                                 
class Subject {
public:
    virtual ~Subject() = default;
    virtual void registerObserver(Observer* o) = 0;
    virtual void removeObserver(Observer* o)   = 0;
    virtual void notifyObservers()             = 0;
};
#endif 
