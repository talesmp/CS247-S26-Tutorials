#include "cheapaccount.h"
#include <iostream>
#include <utility>

CheapAccount::CheapAccount(std::string num)
    : Account(std::move(num)), minutes_(0), freemin_(200), rate_(1) {}

void CheapAccount::addMinutes(int m) { minutes_ += m; }

// BROKEN. Override written as "base behaviour + a bit extra" instead of the
// COMPLETE spec:
void CheapAccount::bill() {
    Account::bill();                              // base: adds fee
    balance_ += (minutes_ - freemin_) * rate_;    // plus the overage
    // BUG: the spec also says minutes == 0 after bill(). Never reset here, so the
    // next bill() re-charges minutes already billed.
}

void CheapAccount::print() const {
    std::cout << "CheapAccount balance = " << balance() << "\n";
}
