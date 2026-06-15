#ifndef CHEAPACCOUNT_H
#define CHEAPACCOUNT_H

#include "account.h"

class CheapAccount : public Account {
    int minutes_;
    int freemin_;
    double rate_;
public:
    explicit CheapAccount(std::string num);
    void addMinutes(int m);
    void bill() override;
    void print() const override;
};

#endif
