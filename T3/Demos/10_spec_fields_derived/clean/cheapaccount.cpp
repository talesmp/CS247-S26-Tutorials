#include "cheapaccount.h"
#include <iostream>
#include <utility>

CheapAccount::CheapAccount(std::string num)
    : Account(std::move(num)), minutes_(0), freemin_(200), rate_(1) {}

void CheapAccount::addMinutes(int m) { minutes_ += m; }

void CheapAccount::bill() {
    Account::bill();
    balance_ += (minutes_ - freemin_) * rate_;
}

void CheapAccount::print() const {
    std::cout << "CheapAccount balance = " << balance() << "\n";
}
