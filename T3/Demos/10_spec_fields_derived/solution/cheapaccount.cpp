#include "cheapaccount.h"
#include <iostream>
#include <utility>

CheapAccount::CheapAccount(std::string num)
    : Account(std::move(num)), minutes_(0), freemin_(200), rate_(1) {}

void CheapAccount::addMinutes(int m) { minutes_ += m; }

// FIX: implement the COMPLETE spec, written out in full -- not "base + extra".
// Every clause of the override's ensures is realized here, including minutes == 0.
void CheapAccount::bill() {
    balance_ = balance_ + fee_ + (minutes_ - freemin_) * rate_;
    minutes_ = 0;
}

void CheapAccount::print() const {
    std::cout << "CheapAccount balance = " << balance() << "\n";
}
