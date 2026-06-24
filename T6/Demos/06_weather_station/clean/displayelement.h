#ifndef DISPLAYELEMENT_H
#define DISPLAYELEMENT_H
class DisplayElement {
public:
    virtual ~DisplayElement() = default;       
    virtual void display() const = 0;
};
#endif 
