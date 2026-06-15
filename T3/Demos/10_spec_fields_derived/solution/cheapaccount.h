#ifndef CHEAPACCOUNT_H
#define CHEAPACCOUNT_H

#include "account.h"

class CheapAccount : public Account {
    int minutes_;
    int freemin_;
    double rate_;
public:
    explicit CheapAccount(std::string num);
    // ensures: ActNo==num, balance==0, minutes==0, fee==30, freemin==200, rate==1

    void addMinutes(int m);

    void bill() override;
    // modifies: this->balance, this->minutes
    // ensures:  this->balance == this@pre->balance + fee + (minutes - freemin)*rate
    //           this->minutes == 0
    void print() const override;
};

#endif // CHEAPACCOUNT_H
